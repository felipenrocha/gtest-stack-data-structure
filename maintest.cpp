// #include "include/menu.hpp"
#include "include/pilha_vetor.hpp"
int main()
{

    // menu();
    PilhaVetor pilha(5);
    TipoDeDado element;
    element.setValue(1);
    pilha.push(element);

    cout << "Topo: " << pilha.top().getValue() << endl;
    cout << "Size: " << pilha.size() << endl;
    pilha.setSize(2);
    cout << "Novo tamanho: " << pilha.size() << endl;
    

    return 0;
}
