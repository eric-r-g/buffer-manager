#include "manager_LRU.h"

using namespace std;


int Buffer_Manager_LRU::evict(){
    int index = ordem.front();
    ordem.erase(ordem.begin());
    return index;
}

void Buffer_Manager_LRU::on_access(int index, bool is_hit){
    int pos = 0;
    while(pos < ordem.size() && ordem[pos] != index)
        pos++;

    if(pos < ordem.size()){
        ordem.erase(ordem.begin() + pos);
    }
    ordem.push_back(index);
}