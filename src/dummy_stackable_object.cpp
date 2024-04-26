#include "../include/dummy_stackable_object.hpp"
#include <iostream>

DummyStackableObject::DummyStackableObject(){
	this->id = this->count;
	this->count++;
}

void DummyStackableObject::print() { std::cout << this->id << std::endl; }
