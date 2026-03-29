#ifndef MANAGER_CLOCK
#define MANAGER_CLOCK

#include "../manager.h"

class Buffer_Manager_clock : public Buffer_Manager {
    protected:
        int evict() override;

    private:   
        vector <bool> clock;
        void acesso(int index, bool is_hit) override;
        int pos;
};


#endif