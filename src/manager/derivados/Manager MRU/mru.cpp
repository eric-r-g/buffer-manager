#include "mru.h"

MRU::MRU() : Buffer_Manager(){
    ultimo_indice = 0;
}

/*
No MRU sempre o indice que foi acesso mais recentemente sera o apagado, ai basta guardar esse indice
*/

void MRU::acesso(int index, bool /*hit*/){
    //para o MRU, nao importa se foi hit ou miss
    //o indice que acabou de ser usado vai ser o mais recente
    ultimo_indice = index;
}

int MRU::evict(){
    int pos = ultimo_indice;

    registro& removido = memory[pos];
    cout << "Removendo pagina: " << removido.text;
    if (removido.update) cout << " W";
    cout << endl;

    return pos;
}