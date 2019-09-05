#include "../include/pilha_vetor.hpp"

Pilha::Pilha(int size)
{
    this->pilha.resize(size);
    this->quantidade = 0;
}

void Pilha::push(TipoDeDado data)
{
    if (isFull())
    {
        throw invalid_argument("Pilha Cheia!");
    }
    else
    {
        this->pilha.push_back(data);
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
        this->pilha.pop_back();
        this->quantidade--;
    }
}


TipoDeDado Pilha::top()
{
    return this->pilha[pilha.rend];
}

int Pilha::size()
{
    return this->pilha.size();
}
void Pilha::destroyStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

bool Pilha::isFull()
{
    if (getQuantidade() >= size())
    {
        return true;
    }
    return false;
}

bool Pilha::isEmpty()
{
    if (this->pilha.empty())
    {
        return true;
    }

    return false;
}
void Pilha::setSize(int size)
{
    if(size < quantidade)
    {
        throw invalid_argument("Impossível mudar o tamanho pois já existemai mais elementos, tente mudar para no mínimo a quantidade de elementos da pilha!");
    }
    pilha.resize(size);
}