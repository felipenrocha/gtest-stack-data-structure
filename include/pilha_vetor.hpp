#ifndef __PILHA_VETOR_H__
#define __PILHA_VETOR_H__
#include <iostream>
#include <vector>
using namespace std;

class Elemento
{
public:
    int *dado;
    int getValue() { return *dado; };
    Elemento();
    Elemento(int data);
    ~Elemento();
};

class Pilha
{
    Elemento *pilha;
    int quantidade;
    int capacidade;

public:
    Pilha(int size);
    void push(Elemento *data);
    void pop();
    Elemento *top();
    int size() { return this->capacidade; };
    bool isEmpty();
    void destroyStack();
    void setSize(int size);
    bool isFull();
    int getQuantidade() { return this->quantidade; }
    Elemento *createStack(Elemento *stack);
};
#endif