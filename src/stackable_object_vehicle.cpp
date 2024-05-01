/**
 * @file stackable_object_vehicle.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/stackable_object_vehicle.hpp"

Vehicle::Vehicle(int w_a, bool h_t, float e_d)
    : wheels_amount(w_a), has_trunk(h_t), engine_displacement(e_d) {
}

void Vehicle::print() {
    std::cout 
    << "Cantidad de ruedas: " << this->wheels_amount 
    << "Tiene baúl: " << this->has_trunk 
    << "Cilindrada: " << this->engine_displacement
    << std::endl;
}

// property get

int Vehicle::get_wheels_amount() {
    return this->wheels_amount;
}

bool Vehicle::get_has_trunk() {
    return this->has_trunk;
}

float Vehicle::get_engine_displacement() {
    return this->engine_displacement;
}

// property set

void Vehicle::set_wheels_amount(int w_a) {
    this->wheels_amount = w_a;
}

void Vehicle::set_if_has_trunk(bool h_t) {
    this->has_trunk = h_t;
}

void Vehicle::set_engine_displacement(float e_d) {
    this->engine_displacement = e_d;
}