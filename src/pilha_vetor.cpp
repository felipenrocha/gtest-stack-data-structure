#include "../include/pilha_vetor.hpp"
#include <stdio.h>
#include <string.h>

// Métodos para os elementos do array;

Elemento::Elemento() // Construção necessária ao iniciar array
{
    this->dado = NULL;
}
Elemento::Elemento(int data)
{
    this->dado = (int *)malloc(sizeof(int *));
    memcpy(dado, &data, sizeof(int));
}
int Elemento::getValue()
{
    return *dado;
}

// Métodos para pilha

Pilha::Pilha(int size)
{
    if (size <= 0)
    {
        throw invalid_argument("Pilha deve possuir tamanho maior que 0!");
    }

    this->tamanho = size;
    this->quantidade = 0;
    this->pilha = createStack();
}

Elemento *Pilha::createStack()
{
    Elemento *newStack = new Elemento[size() * sizeof(Elemento *)];
    return newStack;
}

void Pilha::push(Elemento *data)
{
    if (isFull())
    {
        throw invalid_argument("Pilha Cheia!");
    }
    else
    {
        memcpy(&pilha[quantidade], data, sizeof(Elemento *));
        this->quantidade++;
    }
}
void Pilha::pop()
{
    if (isEmpty())
    {
        throw invalid_argument("Pilha Vazia!");
    }
    else
    {

        Elemento *tmp = (Elemento *)malloc(sizeof(Elemento *));
        memcpy(tmp, &pilha[quantidade], sizeof(Elemento *));
        delete (tmp->dado);
        // delete (tmp);
        quantidade--;
    }
}

Elemento *Pilha::top()
{
    return &pilha[quantidade - 1];
}

int Pilha::size()
{
    return this->tamanho;
}
bool Pilha::isEmpty()
{
    if (getQuantidade() <= 0)
    {
        return true;
    }

    return false;
}

void Pilha::destroyStack()
{
    while (!isEmpty())
    {
        pop();
    }
    delete(pilha->dado);
    delete(pilha);
    this->quantidade = 0;
    pilha = createStack();
}
void Pilha::setSize(int size)
{

    if (size <= getQuantidade())
    {
        throw invalid_argument("Impossível mudar o tamanho pois já existe mais mais elementos, tente mudar para no mínimo a quantidade de elementos da pilha!");
    }
    this->tamanho = size;
}
bool Pilha::isFull()
{
    if (getQuantidade() >= size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Pilha::getQuantidade()
{
    return this->quantidade;
}
