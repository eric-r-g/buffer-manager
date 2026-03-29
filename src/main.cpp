#include "fifo.h"
#include "mru.h"

int main() {
    // ========== Teste FIFO ==========
    cout << "=== FIFO Manager ===" << endl;
    FIFO fifo;
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
    MRU mru;
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

    return 0;
}
