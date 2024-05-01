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
    "\n"
    "  --help | -h\n"
    "\n"
    "      Muestra esta información de ayuda.\n"
    "\n"
    "  -f\n"
    "\n"
    "      Selecciona la implementación de pila estática.\n" 
    "      La pila se crea con un tamaño predeterminado\n"
    "      definido por la variable `FIXED_ARRAY_STACK_CAPACITY`\n"
    "      en el archivo `fixed_array_stack.hpp`.\n"
    "\n"
    "  -d [tamaño]\n"
    "\n"
    "      Selecciona la implementación de pila de memoria dinámica.\n"
    "      Si no se proporciona un tamaño, se crea una pila predeterminada\n"
    "      con un tamaño especificado por la constante `DYNAMIC_STACK_INITIAL_CAPACITY`\n"
    "      en el archivo `dynamic_mem_stack.hpp`.\n" 
    "      Si se proporciona un tamaño (por ejemplo, `-d 100`), la pila\n"
    "      se inicializa con la capacidad inicial especificada.\n"
    "\n"
    "  -r [tamaño]\n"
    "\n"
    "      Selecciona la implementación de pila de memoria dinámica\n"
    "      redimensionable. Si no se proporciona un tamaño,\n"
    "      se crea una pila predeterminada con un tamaño especificado por\n"
    "      la constante `DYNAMIC_STACK_INITIAL_CAPACITY`\n"
    "      en el archivo `dynamic_mem_stack.hpp`. Si se proporciona un tamaño,\n"
    "      (por ejemplo, `-r 100`), la pila se inicializa con la capacidad especificada.\n";

std::string help_str(char *argv[]) {
    return "\n## Modo de uso: " + std::string(argv[0]) + " <Opciones>\n" +
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
