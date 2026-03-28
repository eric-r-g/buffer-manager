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
    registro new_registro = acess_database(key); // consultar no arquivo
    int pos = evict();
    memory[pos] = new_registro;
    return memory[pos].text;
}

void Buffer_Manager::displayCache(){
    // ToDo: implementar função
}

void Buffer_Manager::displayStats(){
    // ToDo: implementar função
}

registro Buffer_Manager::acess_database(int key){
    // ToDo: ajeitar resto da função
    fstream myfile;
    myfile.open("bancodedados.csv");
    // o que é a chave??
}
