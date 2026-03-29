#ifndef MRU_H
#define MRU_H

#include "manager.h"

class MRU : public Buffer_Manager{
    public:
        MRU();
    
    protected:
        int evict() override;
        void acesso(int index, bool hit) override; //atualiza o ultimo indice acessado

    private:
        int ultimo_indice;
};

#endif