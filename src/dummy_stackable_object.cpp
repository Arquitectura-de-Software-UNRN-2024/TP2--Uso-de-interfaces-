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
