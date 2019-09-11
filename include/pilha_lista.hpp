#ifndef __PILHA_LISTA_H__
#define __PILHA_LISTA_H__
#include <iostream>

using namespace std;

class Elemento
{
private:
    int data;

public:
    Elemento(int data);
    class Elemento * proximoElemento;
    int getValue();
    Elemento *getNextElement();
    void setValue(int value);
    void setNextElement(Elemento *newElement);
};
class Pilha
{

    Elemento *topo;
    int quantidade;
    int tamanho;

public:
    Pilha(int size); // CreateStack
    void push(Elemento *elemento);
    void pop();
    Elemento *top();
    int size();
    bool isEmpty();
    void destroyStack();
    void setSize(int size);
    bool isFull();
    int getQuantidade();
};

#endif
