#ifndef MANAGER_LRU
#define MANAGER_LRU

#include "../manager.h"

using namespace std;

class Buffer_Manager_LRU : public Buffer_Manager {
    public:
        int evict() override;
    private:   
        
};


#endif