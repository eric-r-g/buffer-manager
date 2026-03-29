#ifndef MANAGER_MRU
#define MANAGER_MRU

#include "../../manager.h"

class Buffer_Manager_MRU : public Buffer_Manager{
    public:
        Buffer_Manager_MRU();
    
    protected:
        int evict() override;
        void acesso(int index, bool hit) override; //atualiza o ultimo indice acessado

    private:
        int ultimo_indice;
};

#endif