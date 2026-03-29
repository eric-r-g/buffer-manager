#ifndef MANAGER_FIFO
#define MANAGER_FIFO

#include "../../manager.h"

class Buffer_Manager_FIFO : public Buffer_Manager{
    public:
        Buffer_Manager_FIFO();
    
    protected:
        int evict() override;

    private:
        int prox; //indice do proximo slot que sera substituido
};

#endif