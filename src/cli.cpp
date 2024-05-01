/**
 * @file cli.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief This file contains the implementation of the command line interface
 * (CLI) functionalities
 * @version 0.1
 * @date 2024-05-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/cli.hpp"
#include "../include/dynamic_mem_stack.hpp"
#include "../include/dynamic_mem_stack_resizeable.hpp"
#include "../include/fixed_array_stack.hpp"
#include <cstring>

namespace cli {

const std::string help_string =
    "\n"
    "## Opciones\n"
    "  --help| -h\n"
    "      Muestra esta información de ayuda.\n"
    "  -f\n"
    "      Selecciona la implementación de pila estática. La pila se crea con "
    "un tamaño predeterminado "
    "      definido por la variable `FIXED_ARRAY_STACK_CAPACITY` en el archivo "
    "`fixed_array_stack.hpp`.\n"
    "  -d [tamaño]\n"
    "      Selecciona la implementación de pila de memoria dinámica. Si no se "
    "proporciona un tamaño, "
    "      se crea una pila predeterminada con un tamaño especificado por la "
    "constante `DYNAMIC_STACK_INITIAL_CAPACITY` "
    "      en el archivo `dynamic_mem_stack.hpp`. Si se proporciona un tamaño "
    "(por ejemplo, `-d 100`), la pila "
    "      se inicializa con la capacidad inicial especificada.\n"
    "  -r [tamaño]\n"
    "      Selecciona la implementación de pila de memoria dinámica "
    "redimensionable. Si no se proporciona un tamaño, "
    "      se crea una pila predeterminada con un tamaño especificado por la "
    "constante `DYNAMIC_STACK_INITIAL_CAPACITY` "
    "      en el archivo `dynamic_mem_stack.hpp`. Si se proporciona un tamaño "
    "(por ejemplo, `-r 100`), la pila "
    "      se inicializa con la capacidad inicial especificada.\n";

std::string help_str(char *argv[]) {
    return "## Modo de uso: " + std::string(argv[0]) + " <Opciones>\n" +
           help_string;
}

bool needs_help(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            return true;
        }
    }
    return false;
}

Stack *parse_args(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "-f") == 0) {
            return new FixedArrayStack();
        }
        int n = 0;
        if (argc > 2) {
            try {
                n = std::stoi(argv[2]);
            } catch (std::exception &e) {
                n = 0;
            }
        }
        if (strcmp(argv[1], "-d") == 0) {
            return n < 1 ? new DynamicMemStack() : new DynamicMemStack(n);
        }
        if (strcmp(argv[1], "-r") == 0) {
            return n < 1 ? new DynamicMemStackResizeable()
                         : new DynamicMemStackResizeable(n);
        }
    }
    return new FixedArrayStack();
}

} // namespace cli
