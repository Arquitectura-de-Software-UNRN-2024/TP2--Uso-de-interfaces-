/**
 * @file main.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../../include/cli.hpp"
#include "../../include/stack_user.hpp"
#include "../../include/stackable_object_vehicle.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (cli::needs_help(argc, argv)) {
        std::cout << cli::help_str(argv) << std::endl;
        exit(0);
    }
    StackUser stack(cli::parse_args(argc, argv));

    Vehicle obj1(1, true, 600); // monociclo picante
    stack.push(&obj1);
    Vehicle obj2(2, true, 20); // motito con baul
    stack.push(&obj2);
    Vehicle obj3(3, false, 1300.5); // triciclo para que el nene vaya al jardin;
    stack.push(&obj3);
    Vehicle obj4(4, false, 0.002); // un hotwheels naftero
    stack.push(&obj4);
    Vehicle obj5(5, true,
                 200.8); // la quinta rueda es la de auxilio (esta en el baúl)
    stack.push(&obj5);
    Vehicle obj6(5, false,
                 200.8); // la quinta rueda es la de auxilio (es una EcoSport)
    stack.push(&obj6);
    stack.print();
    return 0;
}
