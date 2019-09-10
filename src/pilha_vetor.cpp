#include "../include/pilha_vetor.hpp"

PilhaVetor::PilhaVetor(int size)
{
    if (size <= 0)
    {
        throw invalid_argument("Pilha deve possuir tamanho maior que 0!");
    }
    this->capacidade = size;
    this->pilha.reserve(size);
    this->quantidade = 0;
}

void PilhaVetor::push(TipoDeDado data)
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
void PilhaVetor::pop()
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

TipoDeDado PilhaVetor::top()
{
    return this->pilha.back();
}

void PilhaVetor::destroyStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

bool PilhaVetor::isFull()
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

bool PilhaVetor::isEmpty()
{
    if (getQuantidade() == 0)
    {
        return true;
    }

    return false;
}
void PilhaVetor::setSize(int size)
{
    if (size < quantidade)
    {
        throw invalid_argument("Impossível mudar o tamanho pois já existe mais mais elementos, tente mudar para no mínimo a quantidade de elementos da pilha!");
    }
    pilha.resize(size);
    pilha.reserve(size);
}