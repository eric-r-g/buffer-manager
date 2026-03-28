#ifndef MANAGER_CLOCK
#define MANAGER_CLOCK

#include "../manager.h"

using namespace std;

class Buffer_Manager_clock : public Buffer_Manager {
    public:
        int evict() override;
    private:   
        vector <bool> clock;
        int pos;
};


#endif