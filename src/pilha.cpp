#include "../include/pilha.hpp"

Pilha::Pilha()
{
    this->topo = NULL;
    this->tamanho = 0;
}

void Pilha::push(Elemento * elemento)
{
    
    if (isEmpty())
    {
        this->topo = elemento;
        this->tamanho++;
    }
    else
    {
        Elemento *tmp = this->topo;
        this->topo = elemento;
        this->topo->setNextElement(tmp);
        this->tamanho++;
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
    this->tamanho--;
   
}

bool Pilha::isEmpty()
{
    if (top() == NULL && size() == 0)
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