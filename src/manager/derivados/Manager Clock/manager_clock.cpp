#include "manager_clock.h"

using namespace std;

// ToDo: forma de atualizar o clock


int Buffer_Manager_clock::evict(){
    // enquanto ele não achar uma posição recentemente modifica, continua
    while(clock[pos] == 1){
        clock[pos] = 0;
        pos++;
        if(pos == 5) pos = 0; // talvez alterar essa constante para algo fornecido?
    }

    return pos;
}