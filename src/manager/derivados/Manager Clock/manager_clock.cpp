#include "manager_clock.h"

using namespace std;


int Buffer_Manager_clock::evict(){
    // enquanto ele não achar uma posição recentemente modifica, continua
    while(clock[pos] == 1){
        clock[pos] = 0;
        pos = (pos + 1) % 5; // talvez alterar depois para um constante
    }

    int saida = pos;
    pos = (pos + 1) % 5;
    return saida;
}

void Buffer_Manager_clock::on_access(int index, bool is_hit){
    clock[index] = true;
}
