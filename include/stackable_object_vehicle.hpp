/**
 * @file stackable_object_vehicle.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com):)
 * @brief This file defines the Vehicle class representing a generic vehicle.
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
    /**
     * @brief Constructor for the Vehicle class.
     *
     * This constructor initializes a new Vehicle object with the specified
     * properties.
     *
     * @param w_a The number of wheels of the vehicle.
     * @param h_t A flag indicating whether the vehicle has a trunk.
     * @param e_d The engine displacement of the vehicle in liters.
     */
    Vehicle(int w_a, bool h_t, float e_d);
    ~Vehicle() = default;

    /**
     * @brief Prints the vehicle information to the console.
     *
     * This function prints the number of wheels, trunk existence flag, and
     * engine displacement of the vehicle.
     */
    virtual void print() override;

    // Property getters

    /**
     * @brief Getter function for the number of wheels.
     *
     * This function returns the number of wheels of the vehicle.
     *
     * @return The number of wheels.
     */
    int get_wheels_amount();

    /**
     * @brief Getter function for the trunk existence flag.
     *
     * This function returns true if the vehicle has a trunk, false otherwise.
     *
     * @return True if the vehicle has a trunk, false otherwise.
     */
    bool get_has_trunk();

    /**
     * @brief Getter function for the engine displacement.
     *
     * This function returns the engine displacement of the vehicle in liters.
     *
     * @return The engine displacement in liters.
     */
    float get_engine_displacement();

    // Property setters

    /**
     * @brief Setter function for the number of wheels.
     *
     * This function sets the number of wheels of the vehicle.
     *
     * @param w_a The new number of wheels.
     */
    void set_wheels_amount(int w_a);

    /**
     * @brief Setter function for the trunk existence flag.
     *
     * This function sets whether the vehicle has a trunk.
     *
     * @param h_t True to indicate the vehicle has a trunk, false otherwise.
     */
    void set_if_has_trunk(bool h_t);

    /**
     * @brief Setter function for the engine displacement.
     *
     * This function sets the engine displacement of the vehicle in liters.
     *
     * @param e_d The new engine displacement in liters.
     */
    void set_engine_displacement(float e_d);

  private:
    int wheels_amount;         // cantidad de ruedas
    bool has_trunk;            // tiene un baúl
    float engine_displacement; // cilindrada
};
