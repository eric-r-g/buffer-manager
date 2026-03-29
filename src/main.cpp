#include "manager/derivados/Manager_FIFO/manager_FIFO.h"
#include "manager/derivados/Manager_MRU/manager_MRU.h"
#include "manager/derivados/Manager_Clock/manager_clock.h"
#include "manager/derivados/Manager_LRU/manager_LRU.h"

int main() {
    // ========== Teste FIFO ==========
    cout << "=== FIFO Manager ===" << endl;
    Buffer_Manager_FIFO fifo;
    fifo.fetch(1);
    fifo.fetch(2);
    fifo.fetch(3);
    fifo.fetch(4);
    fifo.fetch(5);
    fifo.displayCache();
    fifo.fetch(6); // deve remover a página 1 (FIFO)
    fifo.displayCache();
    fifo.displayStats();

    cout << "\n=== MRU Manager ===" << endl;
    Buffer_Manager_MRU mru;
    mru.fetch(1);
    mru.fetch(2);
    mru.fetch(3);
    mru.fetch(4);
    mru.fetch(5);
    mru.displayCache();
    mru.fetch(1); // hit na página 1 (torna-se a mais recente)
    mru.fetch(6); // deve remover a mais recente (página 1)
    mru.displayCache();
    mru.displayStats();

    cout << "=== LRU Manager ===" << endl;
    Buffer_Manager_LRU lru;
    lru.fetch(1);
    lru.fetch(2);
    lru.fetch(3);
    lru.fetch(4);
    lru.fetch(5);
    lru.displayCache();
    lru.fetch(6);
    lru.displayCache();
    lru.displayStats();

    cout << "\n=== clock Manager ===" << endl;
    Buffer_Manager_clock clock;
    clock.fetch(1);
    clock.fetch(2);
    clock.fetch(3);
    clock.fetch(4);
    clock.fetch(5);
    clock.displayCache();
    clock.fetch(1); // hit na página 1 (torna-se a mais recente)
    clock.fetch(6); // deve remover a mais recente (página 1)
    clock.displayCache();
    clock.displayStats();

    return 0;
}
