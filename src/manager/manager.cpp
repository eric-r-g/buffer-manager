#include "manager.h"

using namespace std;

Buffer_Manager::Buffer_Manager(){
    cache_hit = 0, cache_miss = 0;
    memory = vector <registro> (5);
}

string Buffer_Manager::fetch(int key){
    for(registro& r : memory){
        if(r.key == key){
            cache_hit++;
            return r.text;
        }
    }

    cache_miss++;
    registro new_registro = acess_database(key);

    bool isfull = true;
    int pos;
    for(int i = 0; i < 5; i++){
        if(memory[i].key == 0){
            isfull = false;
            pos = i;
        }
    }

    if(isfull) pos = evict();
    memory[pos] = new_registro;
    return memory[pos].text;
}

void Buffer_Manager::displayCache(){
    for(registro& r : memory){
        if(r.key == 0) cout << "Registro vazio.\n";
        else {
            cout << "Chave -> " << r.key << ". ";  
            cout << "Valor -> " << r.text << ". ";
            cout << "Atualização -> " << r.update << ".\n";
        }
    }
}

void Buffer_Manager::displayStats(){
    cout << "Cache Hit: " << cache_hit << "\n";
    cout << "Cache Miss: " << cache_miss << "\n";
}

// ToDo: ajeitar resto da função
registro Buffer_Manager::acess_database(int key){
    fstream myfile;
    myfile.open("../bancodedados.csv");
    // o que é a chave??
}
