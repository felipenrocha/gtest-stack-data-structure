#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
using namespace std;

class Elemento
{
private:
    int data;

public:
    Elemento(int data);
    class Elemento *proximo;
    int getValue() { return this->data; }
    Elemento *getNextElement() { return this->proximo; }
    void setValue(int value) { this->data = value; }
    void setNextElement(Elemento *newElement) { this->proximo = newElement; }
};

#endif