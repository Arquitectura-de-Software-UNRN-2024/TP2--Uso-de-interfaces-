#include <DynamicMemStack.h>
#include <FixedArrayStack.h>
#include <StackInterface.h>
#include <StackUser.h>

int main() {
    // FixedArrayStack stack;
    DynamicMemStack stack;

    StackUser user(&stack);
    user.cargarPila();
    user.imprimirPila();

    return 0;
}
