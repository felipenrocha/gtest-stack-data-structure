#include "../include/pilha_vetor.hpp"
#include <stdio.h>
#include <string.h>
Elemento::Elemento(int data)
{

    this->dado = (int *)malloc(sizeof(int));
    memcpy(dado, &data, sizeof(int));
}
Pilha::Pilha(int size)
{
    if (size <= 0)
    {
        throw invalid_argument("Pilha deve possuir tamanho maior que 0!");
    }

    pilha = new Elemento(NULL)[size];
    // this->pilha = (Elemento *)malloc((size) * sizeof(Elemento *));
    cout << "tamanho pilha: " << sizeof(pilha) << endl;
    this->capacidade = size;
    this->quantidade = 0;
}
Elemento *Pilha::top()
{
    return &pilha[quantidade - 1];
}
void Pilha::push(Elemento *data)
{
    if (isFull())
    {
        throw invalid_argument("Pilha Cheia!");
    }
    else
    {
        cout << "data = " << data->getValue() << endl;
        cout << "pilha[quantidade] = " << &pilha[quantidade] << endl;
        memcpy(&pilha[quantidade], data, sizeof(Elemento *));
        this->quantidade++;
        cout << "top: " << top()->getValue() << endl;
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
        cout << "poping: " << endl;
        Elemento *tmp = (Elemento *)malloc(sizeof(Elemento *));
        memmove(tmp, &pilha[quantidade], sizeof(Elemento *));
        cout << "pilha[quantidade pop] == " << tmp << endl;
        cout << "pilha[0] = " << &pilha[0] << endl;
        pilha[quantidade] = (Elemento *) malloc(sizeof(Elemento *));
        free(tmp);
    }
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
    if (getQuantidade() == 0)
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
    this->pilha = (Elemento *)realloc(pilha, size * sizeof(Elemento));
    this->capacidade = size;
}