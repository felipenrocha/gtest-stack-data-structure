#include "../include/pilha_vetor.hpp"
#include <stdio.h>
#include <string.h>

Elemento::Elemento()
{
    this->dado = (int *)malloc(sizeof(int *));
    this->dado = NULL;
}
Elemento::Elemento(int data)
{
    this->dado = (int *)malloc(sizeof(int *));
    memcpy(dado, &data, sizeof(int));
}
Elemento::~Elemento()
{
    free(this->dado);
    this->dado = NULL;
}
Pilha::Pilha(int size)
{
    if (size <= 0)
    {
        throw invalid_argument("Pilha deve possuir tamanho maior que 0!");
    }

    this->capacidade = size;
    this->quantidade = 0;
    this->pilha = createStack(pilha);
}
Elemento *Pilha::top()
{
    return &pilha[quantidade - 1];
}

Elemento *Pilha::createStack(Elemento *pilha)
{
    Elemento *newStack = new Elemento[capacidade * sizeof(Elemento *)];
    for (int i = 0; i < quantidade; i++)
    {
        newStack[i] = pilha[i];
    }

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
        data = new Elemento(*data);
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
        if (quantidade > 0)
        {
            Elemento *tmp = (Elemento *)malloc(sizeof(Elemento *));
            memcpy(tmp, &pilha[quantidade], sizeof(Elemento *));
            // free(tmp->dado);
            // pilha[quantidade - 1] = new *Elemento;
            free(tmp);
            quantidade--;
        }
    }
}
void Pilha::destroyStack()
{
    while (!isEmpty())
    {
        pop();
    }
    pilha = createStack(pilha);
}

bool Pilha::isFull()
{
    if (getQuantidade() >= (capacidade))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Pilha::isEmpty()
{
    if (getQuantidade() <= 0)
    {
        return true;
    }

    return false;
}
void Pilha::setSize(int size)
{
    if (size < quantidade)
    {
        throw invalid_argument("Impossível mudar o tamanho pois já existe mais mais elementos, tente mudar para no mínimo a quantidade de elementos da pilha!");
    }
    this->capacidade = size;
    this->pilha = createStack(pilha);
}