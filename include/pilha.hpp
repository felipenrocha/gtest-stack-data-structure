#ifndef __PILHA_H__
#define __PILHA_H__
#include <iostream>
#include "./lista.hpp"

class Pilha
{

    Elemento *topo;
    int tamanho;

public:
    Pilha(); // Create pilha
    void push(Elemento * elemento);
    void pop();
    Elemento * top() { return this->topo; };
    int size() { return this->tamanho; };
    bool isEmpty();
    void destroyStack();
    // void setSize(); Não disponível p/ pilha com lista
    // bool isFull(); Não disponível p/ pilha com lista
};

#endif
