#include <iostream>
#include <vector> 
#include <fstream>

using namespace std;

struct registro{
    int key = 0; // 0 - chave inexistente
    string text;
    bool update;
};

struct Buffer_Manager{
    int cache_hit, cache_miss;
    vector <registro> memory; 

    Buffer_Manager(){
        cache_hit = 0, cache_miss = 0;
        memory = vector <registro> (5);
    }

    string fetch(int key){
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

    // retorna posição escolhida
    int evict(){
        // ToDo: deixar abstrato
    }

    void displayCache(){
        // ToDo: implementar função
    }

    void displayStats(){
        // ToDo: implementar função
    }

    registro acess_database(int key){
        // ToDo: ajeitar resto da função
        fstream myfile;
        myfile.open("bancodedados.csv");
        // o que é a chave??
    }
};