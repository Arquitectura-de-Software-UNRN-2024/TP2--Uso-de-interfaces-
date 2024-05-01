/**
 * @file dummy_stackable_object.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../include/dummy_stackable_object.hpp"
#include <iostream>

int DummyStackableObject::count = 0;

DummyStackableObject::DummyStackableObject() {
    this->id = this->count;
    this->count++;
}

void DummyStackableObject::print() {
    std::cout << this->id << std::endl;
}
