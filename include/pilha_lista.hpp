#ifndef __PILHA_LISTA_H__
#define __PILHA_LISTA_H__
#include <iostream>
#include "./lista.hpp"

class Pilha
{

    Elemento *topo;
    int quantidade;
    int tamanho;

public:
    Pilha(int size); // Create pilha
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
