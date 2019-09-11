#ifndef __PILHA_VETOR_H__
#define __PILHA_VETOR_H__
#include <iostream>
using namespace std;

class Elemento
{


public:
    int *dado;
    int getValue();
    Elemento();
    Elemento(int data);
};

class Pilha
{
    Elemento *pilha;
    int quantidade;
    int tamanho;

public:
    Pilha(int size);
    Elemento *createStack();
    void push(Elemento *data);
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