#ifndef STACKUSER_H
#define STACKUSER_H

#include <StackInterface.h>

class StackUser {
  public:
    StackUser(StackInterface *stack);
    virtual ~StackUser();

    void cargarPila();
    void imprimirPila();

  private:
    StackInterface *stack;
};

#endif // STACKUSER_H
