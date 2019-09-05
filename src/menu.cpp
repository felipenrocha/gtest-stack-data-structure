#include "../include/menu.hpp"

void menu()
{
    int opcao;
    do
    {

        cout << "Selecione uma opção: " << endl
             << endl;
        cout << "1) Pilha Lista" << endl;
        cout << "2) Pilha Vetor" << endl;
        cout << "Qualquer outra tecla para terminar o programa" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            menu_lista();
            break;
        case 2:
            menu_vetor();
        default:
            break;
        }
    } while (opcao == 1 || opcao == 2);
}

void menu_lista()
{
    cout << "Pilha Vazia! Selecione uma das operações abaixo: " << endl;
    int opcao;
    Pilha pilha(10);
    do
    {
        cout << endl;
        cout << "1) Push inteiro" << endl;
        cout << "2) Pop pilha" << endl;
        cout << "3) Topo pilha" << endl;
        cout << "4) Tamanho pilha" << endl;
        cout << "5) Destruir pilha" << endl;
        cout << "6) Sair"
             << endl;
        cin >> opcao;
        switch (opcao)
        {
        case 1:
        {
            int value;
            cout << "Qual valor do inteiro deseja inserir na pilha?" << endl;
            cin >> value;
            Elemento elemento(value);
            cout << "Elemento value: " << elemento.getValue() << endl;
            pilha.push(&elemento);
        }
        break;
        case 2:
            cout << "Elemento removido: " << pilha.top()->getValue() << endl;
            pilha.pop();
            break;
        case 3:
            cout << "Topo da pilha: " << pilha.top()->getValue() << endl;
            break;
        case 4:
            cout << "Tamanho da pilha: " << pilha.size() << endl;
            break;
        case 5:
            pilha.destroyStack();
            cout << "Pilha Detruída!" << endl;
            break;
        default:
            break;
        }

    } while (opcao != 6);
}


void menu_vetor()
{
    cout << "Pilha Vetor" << endl;
}