#include <StackInterface.h>
#include <FixedArrayStack.h>
#include <DynamicMemStack.h>
#include <StackUser.h>

int main()
{
    //FixedArrayStack stack;
    DynamicMemStack stack;

    StackUser user(&stack);
    user.cargarPila();
    user.imprimirPila();

    return 0;
}
