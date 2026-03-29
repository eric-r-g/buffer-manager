#include "manager_clock.h"

using namespace std;

// mantem uma fila booleana indicando aqueles que 
// foram acessados recentemente
Buffer_Manager_clock::Buffer_Manager_clock(){
    clock.resize(5); // constante
    pos = 0;
}

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

void Buffer_Manager_clock::acesso(int index, bool is_hit){
    clock[index] = true;
}
