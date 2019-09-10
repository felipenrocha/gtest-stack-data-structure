#ifndef __PILHA_VETOR_H__
#define __PILHA_VETOR_H__
#include <iostream>
#include <vector>
using namespace std;

class TipoDeDado
{
    int dado;

public:
    
    int getValue() { return this->dado; };
    void setValue(int data) { this->dado = data; }
};

class PilhaVetor
{
    vector<TipoDeDado> pilha;
    int quantidade;

public:
    PilhaVetor(int size);
    void push(TipoDeDado data);
    void pop();
    TipoDeDado top();
    int size();
    bool isEmpty();
    void destroyStack();
    void setSize(int size);
    bool isFull();
    int getQuantidade(){return this->quantidade;};
};
#endif