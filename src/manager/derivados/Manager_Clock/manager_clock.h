#ifndef MANAGER_CLOCK
#define MANAGER_CLOCK

#include "../../manager.h"

class Buffer_Manager_clock : public Buffer_Manager {
    public:
        Buffer_Manager_clock();

    protected:
        int evict() override;

    private:   
        vector <bool> clock;
        void acesso(int index, bool is_hit) override;
        int pos;
};


#endif