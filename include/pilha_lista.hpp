#ifndef __PILHA_LISTA_H__
#define __PILHA_LISTA_H__
#include <iostream>
#include "./lista.hpp"



class Elemento
{
private:
    int data;

public:
    Elemento(int data);
    class Elemento *proximo;
    int getValue() { return this->data; }
    Elemento *getNextElement() { return this->proximo; }
    void setValue(int value) { this->data = value; }
    void setNextElement(Elemento *newElement) { this->proximo = newElement; }
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
    Elemento *top() { return this->topo; };
    int size() { return this->tamanho; };
    bool isEmpty();
    void destroyStack();
    void setSize(int size) { this->tamanho = size; };
    bool isFull();
    int getQuantidade() { return this->quantidade; }
};

#endif
