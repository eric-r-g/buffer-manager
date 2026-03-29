#ifndef MANAGER_CLOCK
#define MANAGER_CLOCK

#include "../manager.h"

using namespace std;

class Buffer_Manager_clock : public Buffer_Manager {
    public:
        int evict() override;
    private:   
        vector <bool> clock;
        void on_access(int index, bool is_hit) override;
        int pos;
};


#endif