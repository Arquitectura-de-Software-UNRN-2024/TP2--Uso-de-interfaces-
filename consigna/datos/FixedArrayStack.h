#ifndef FIXEDARRAYSTACK_H
#define FIXEDARRAYSTACK_H

#include <StackInterface.h>

#define N 5

class FixedArrayStack : public StackInterface
{
    public:
        FixedArrayStack();
        virtual ~FixedArrayStack();

        virtual StackableObject * pop();
        virtual bool push(StackableObject *o);
        virtual int getCount();

    protected:

    private:
        int indice;
        StackableObject *pila[N];
};

#endif // FIXEDARRAYSTACK_H
