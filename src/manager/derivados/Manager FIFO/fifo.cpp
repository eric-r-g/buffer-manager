#include "fifo.h"

FIFO::FIFO() :  prox(0) {}

/*
A ideia é manter uma variável (prox) para determinar o slot que vai ser substituido
Começa do 0 e vai incrementando de 1 em 1 (FIFO), até chegar no maximo (memory.size), ai volta pra 0
*/

int FIFO::evict(){
    int pos = prox;
    
    registro& removido = memory[pos];
    cout << "Removendo pagina: " << removido.text;
    if (removido.update) cout << " W";
    cout << endl;

    prox = (prox + 1) % memory.size(); //pra nao ter acesso invalido (> memory.size)

    return pos;
}