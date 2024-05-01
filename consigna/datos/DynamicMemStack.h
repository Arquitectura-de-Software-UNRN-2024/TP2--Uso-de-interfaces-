#ifndef DYNAMICMEMSTACK_H
#define DYNAMICMEMSTACK_H

#include <StackInterface.h>
#include <StackNode.h>

class DynamicMemStack : public StackInterface {
  public:
    DynamicMemStack();
    virtual ~DynamicMemStack();

    virtual StackableObject *pop();
    virtual bool push(StackableObject *o);
    virtual int getCount();

  protected:
  private:
    StackNode *top;
    int count;

    void removeTopNode();
    void addTopNode(StackNode *newTop);
};

#endif // DYNAMICMEMSTACK_H
