#ifndef FIFO_H
#define FIFO_H

#include "manager.h"

class FIFO : public Buffer_Manager{
    public:
        FIFO();
    
    protected:
        int evict() override;

    private:
        int prox; //indice do proximo slot que sera substituido
};

#endif