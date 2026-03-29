#include "manager.h"

using namespace std;

Buffer_Manager::Buffer_Manager(){
    cache_hit = 0, cache_miss = 0;
    //memory = vector <registro> (5); nao quis apagar nada teu, mas acho que nao faz sentido -> ja tem no .h
    memory.resize(5);
    //inicializar a seed aleatoria (uma unica vez)
    static bool seed = false;
    if(!seed){
        srand(static_cast<unsigned>(time(nullptr)));
        seed = true;
    }
}

string Buffer_Manager::fetch(int key){
    //verificar se a pagina ja ta no buffer
    for(int i = 0 ; i < memory.size() ; i++){
        registro r = memory[i];
        if(r.key == key){
            cache_hit++;
            on_access(i, true); //notificar acesso (hit)
            return r.text;
        }
    }

    cache_miss++;
    registro novo_registro = acess_database(key); //consultar no arquivo

    //procurar um slot vazio
    int pos = -1;
    for(int i = 0 ; i < memory.size() ; i++){
        if(memory[i].key == 0) { //slot vazio
            pos = i;
            break;
        }
    }
    //se nao tiver slot vazio, aplica a politica de substituicao
    if(pos == -1) pos = evict();

    memory[pos] = novo_registro;
    on_access(pos, false); // notifica acesso (miss)
    return memory[pos].text;
}

void Buffer_Manager::displayCache(){
    //imprime as informaçoes dos registros no buffer
    cout << "Conteudo do Buffer:" << endl;
    for (const auto& reg : memory) {
        cout << "Chave: " << reg.key
                << ", Valor: " << reg.text
                << ", Atualizacao: " << (reg.update ? "true" : "false")
                << endl;
    }
}

void Buffer_Manager::displayStats(){
    cout << "Cache Hits: " << cache_hit << endl;
    cout << "Cache Misses: " << cache_miss << endl;
}

registro Buffer_Manager::acess_database(int key){
    //tenta abrir o arquivo de banco de dados
    ifstream file("bancodedados.csv");
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo bancodedados.csv" << endl;
        registro r;
        r.key = -1;
        r.text = "Erro";
        r.update = false;
        return r;
    }

    //percorre o arquivo ate achar a chave especificada
    string linha;
    while(getline(file, linha)){
        stringstream ss(linha);

        string chave;
        getline(ss, chave, ',');
        int chave_atual = stoi(chave); //tranforma a chave para inteiro

        if (chave_atual == key) {
            string texto;
            getline(ss, texto); //pega o resto da linha
            registro reg;
            reg.key = key;
            reg.text = texto;
            reg.update = rand() % 2; //true ou false aleatorio
            return reg;
        }
    }

    //se chegou aqui, nao encontrou a chave
    registro nao_encontrado;
    nao_encontrado.key = -1;
    nao_encontrado.text = "Nao Encontrado";
    nao_encontrado.update = false;
    return nao_encontrado;
}
