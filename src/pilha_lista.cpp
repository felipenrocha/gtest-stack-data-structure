#include "../include/pilha_lista.hpp"

Pilha::Pilha()
{
    this->topo = NULL;
    this->tamanho = 0;
}

void Pilha::push(int value)
{
    if (isEmpty())
    {
        this->topo = new Elemento(value);
        this->tamanho++;
    }
    else
    {
        Elemento *tmp = this->topo;
        this->topo = new Elemento(value);
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

    try
    {
        isEmpty();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Elemento *tmp;
    tmp = this->topo;
    this->topo = this->topo->getNextElement();
    this->tamanho--;
    delete (tmp);
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