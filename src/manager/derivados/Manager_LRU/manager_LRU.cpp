#include "manager_LRU.h"

using namespace std;

// retira o cara que foi usados menos recentemente
// ou seja, na frente da fila na ordem
int Buffer_Manager_LRU::evict(){
    int index = ordem.front();
    ordem.erase(ordem.begin());
    return index;
}

// coloca o cara acessado para o final da fila
void Buffer_Manager_LRU::acesso(int index, bool is_hit){
    int pos = 0;
    while(pos < (int) ordem.size() && ordem[pos] != index)
        pos++;

    if(pos < (int) ordem.size()){
        ordem.erase(ordem.begin() + pos);
    }
    ordem.push_back(index);
}