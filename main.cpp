#include "./include/pilha.hpp"

int main()
{
    Pilha pilha;
    pilha.push(2);
    cout << "Topo Pilha: " << pilha.top()->getValue() << endl;
    cout << "Tamanho: " << pilha.size() << endl;
    pilha.push(3);

    cout << "Topo Pilha: " << pilha.top()->getValue() << endl;
    cout << "Tamanho: " << pilha.size() << endl;
    pilha.destroyStack();
    

    return 0;
}
