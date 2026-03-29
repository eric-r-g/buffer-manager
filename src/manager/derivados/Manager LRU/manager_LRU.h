#ifndef MANAGER_LRU
#define MANAGER_LRU

#include "../manager.h"

using namespace std;

class Buffer_Manager_LRU : public Buffer_Manager {
    public:
        int evict() override;
    private:
        vector <int> ordem;
        void on_access(int index, bool is_hit) override;
};


#endif