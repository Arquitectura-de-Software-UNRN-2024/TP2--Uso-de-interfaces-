/**
 * @file stackable_object_vehicle.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "stack_interface.hpp"
#include <iostream>

class Vehicle : public StackableObject {
  public:
    Vehicle(int w_a, bool h_t, float e_d);
    ~Vehicle() = default;
    virtual void print() override;
    // property get
    int get_wheels_amount();
    bool get_has_trunk();
    float get_engine_displacement();
    // property set
    void set_wheels_amount(int w_a);
    void set_if_has_trunk(bool h_t);
    void set_engine_displacement(float e_d);

  private:
    int wheels_amount;         // cantidad de ruedas
    bool has_trunk;            // tiene un baúl
    float engine_displacement; // cilindrada
};
