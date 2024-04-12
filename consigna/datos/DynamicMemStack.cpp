#include <iostream>
#include "DynamicMemStack.h"

DynamicMemStack::DynamicMemStack()
{
    this->top = NULL;
    this->count = 0;
}

DynamicMemStack::~DynamicMemStack()
{
    StackableObject * o;

    while( (o = pop()) )
        delete o;
}

StackableObject * DynamicMemStack::pop()
{
    StackableObject * o = NULL;

    if(this->top)
    {
        o = this->top->getObject();
        removeTopNode();
    }

    return o;
}

bool DynamicMemStack::push(StackableObject *o)
{
    StackNode * newNode = new StackNode(o);
    if(newNode)
    {
        addTopNode(newNode);
    }

    return newNode != NULL;
}


void DynamicMemStack::removeTopNode()
{
    if(this->top)
    {
        StackNode * prev = this->top->getPrevNode();
        delete this->top;
        this->top = prev;
        this->count--;
    }
}

void DynamicMemStack::addTopNode(StackNode * newTop)
{
    if(newTop)
    {
        newTop->setPrevNode(this->top);
        this->top = newTop;
        this->count++;
    }
}

int DynamicMemStack::getCount()
{
    return this->count;
}
