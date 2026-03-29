#include "manager/derivados/Manager_FIFO/manager_FIFO.h"
#include "manager/derivados/Manager_MRU/manager_MRU.h"
#include "manager/derivados/Manager_Clock/manager_clock.h"
#include "manager/derivados/Manager_LRU/manager_LRU.h"
#include "manager/manager.h"

#include <memory>

int main() {
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Seja bem vindo! Selecione a politica de substituição que você deseja." << endl;
    cout << "1 - Clock, 2 - FIFO, 3 - LRU, 4 - MRU." << endl;
    

    unique_ptr<Buffer_Manager> manager;
    int val = 0;
    while(val <= 0 || val >= 5){
        cout << "-> ";
        cin >> val;

        switch(val){
            case 1:
            manager = make_unique<Buffer_Manager_clock>();
            break;
        case 2:
            manager = std::make_unique<Buffer_Manager_FIFO>();
            break;
        case 3:
            manager = std::make_unique<Buffer_Manager_LRU>();
            break;
        case 4:
            manager = std::make_unique<Buffer_Manager_MRU>();
            break;
        default:
            cout << "---------------------------------------------------------------------" << endl;
            cout << "politica invalida, tente novamente." << endl;
            val = 0;
            break;
        }
        
    }

    int comando = 1;
    while(comando){
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Digite um comando." << endl;
        cout << "1 - fetch, 2 - display cache, 3 - display stats, 0 - terminar." << endl;
        cout << "-> ";
        cin >> comando;

        // declarado fora para não haver problema com o switch
        int chave;
        string conteudo;

        cout << "---------------------------------------------------------------------" << endl;
        switch(comando){
            case 0:
                cout << "Finalizando programa." << endl;
                break;
            case 1:
                cout << "Digite a chave desejada." << endl;
                cout << "-> ";
                cin >> chave;

                conteudo = manager ->fetch(chave);
                cout << "O conteudo da pagina era o seguinte: " << endl;
                cout << conteudo << endl;
                break;
            case 2:
                manager -> displayCache();
                break;
            case 3:
                manager -> displayStats();
                break;
            default:
                cout << "Comando invalido, tente novamente." << endl;
                comando = 1;
                break;
        }
    }

    return 0;
}
