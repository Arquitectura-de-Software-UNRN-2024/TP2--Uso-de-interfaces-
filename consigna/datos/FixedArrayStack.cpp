#include <iostream>
#include "FixedArrayStack.h"

FixedArrayStack::FixedArrayStack()
{
    for(int i = 0; i < N; i++)
    {
        this->pila[i] = NULL;
    }
    this->indice = 0;
}

FixedArrayStack::~FixedArrayStack()
{
    //dtor
}

StackableObject * FixedArrayStack::pop()
{
    StackableObject * o;

    if(this->indice <= 0)
    {
        return  NULL;
    }

    this->indice--;
    o = this->pila[this->indice];
    this->pila[this->indice] = NULL;

    return o;
}

bool FixedArrayStack::push(StackableObject *o)
{
    if(this->indice >= N)
    {
        return  false;
    }

    this->pila[this->indice] = o;
    this->indice++;

    return true;
}

int FixedArrayStack::getCount()
{
    return this->indice;
}
