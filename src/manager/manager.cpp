#include <iostream>

using namespace std;

struct Buffer_Manager{
    int cache_hit, cache_miss;

    Buffer_Manager(){
        cache_hit = 0, cache_miss = 0;
    }

    string fetch(int key){

    }

    void evict(){

    }

    void displayCache(){

    }

    void displayStats(){

    }
};