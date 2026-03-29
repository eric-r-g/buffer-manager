#ifndef MANAGER
#define MANAGER

#include <iostream>
#include <vector> 
#include <fstream>
#include <sstream>

using namespace std;

struct registro{
    int key = 0; // 0 - chave inexistente
    string text;
    bool update;
};

class Buffer_Manager{
    public:
        Buffer_Manager();
        virtual ~Buffer_Manager() = default; //destructor padrao

        string fetch(int key);

        void displayCache();

        void displayStats();
    
    protected:
        // definir para cada um dos métodos
        virtual int evict() = 0;

        //notificar sobre um acesso (hit ou miss)
        virtual void on_access(int index, bool is_hit) {}

        int cache_hit;
        int cache_miss;
        vector <registro> memory; 

    private:
        registro acess_database(int key);
};

#endif
