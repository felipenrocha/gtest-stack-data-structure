#include "../include/pilha_lista.hpp"


// Métodos para o elemento da lista:


Elemento::Elemento(int value)
{
    setValue(value);
    setNextElement(NULL);
}
int Elemento::getValue()
{
    return this->data;
}
Elemento * Elemento::getNextElement()
{
    return this->proximoElemento;
}
void Elemento::setValue(int value)
{
    this->data = value;
}
void Elemento::setNextElement(Elemento * newElement)
{
    this->proximoElemento = newElement;
}



// Métodos para Pilha:

Pilha::Pilha(int size)
{
    this->topo = NULL;
    this->tamanho = size;
    if (size <= 0)
    {
        throw invalid_argument("Pilha deve possuir tamanho maior que 0!");
    }
    else
    {
        this->quantidade = 0;
    }
}

void Pilha::push(Elemento *elemento)
{
    if (isFull())
    {
        throw invalid_argument("Pilha Cheia!");
    }

    else if (isEmpty())
    {
        this->topo = elemento;
        this->quantidade++;
    }

    else
    {
        Elemento *tmp = this->topo;
        this->topo = elemento;
        this->topo->setNextElement(tmp);
        this->quantidade++;
    }
}

void Pilha::pop()
{
    if (isEmpty())
    {
        throw invalid_argument("Pilha Vazia!");
    }

    // Elemento *tmp;
    // tmp = this->topo;
    this->topo = this->topo->getNextElement();
    this->quantidade--;
}

bool Pilha::isEmpty()
{
    if (top() == NULL && getQuantidade() == 0)
    {
        return true;
    }

    return false;
}
void Pilha::destroyStack()
{
    while (top() != NULL)
    {
        pop();
    }
}

bool Pilha::isFull()
{
    if (quantidade >= tamanho)
    {
        return true;
    }
    return false;
}

void Pilha::setSize(int size)
{
    if (size <= getQuantidade())
    {
        throw invalid_argument("Impossível mudar o tamanho pois já existe mais mais elementos, tente mudar para no mínimo a quantidade de elementos da pilha!");
    }
    this->tamanho = size;
}

Elemento *Pilha::top()
{
    return this->topo;
}
int Pilha::size()
{
    return this->tamanho;
}

int Pilha::getQuantidade()
{
    return this->quantidade;
}