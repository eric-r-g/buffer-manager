#ifndef MANAGER
#define MANAGER

#include <iostream>
#include <vector> 
#include <fstream>

using namespace std;

struct registro{
    int key = 0; // 0 - chave inexistente
    string text;
    bool update;
};

class Buffer_Manager{
    public:
        Buffer_Manager();

        string fetch(int key);

        // definir para cada um dos métodos
        virtual int evict() = 0;

        void displayCache();

        void displayStats();

    private:
        int cache_hit;
        int cache_miss;
        vector <registro> memory; 

        registro acess_database(int key);
};

#endif