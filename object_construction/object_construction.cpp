//object_construction.cpp

#include <iostream>
#include "object_construction.hpp"


myClass::myClass(){
  std::cout << "default constructor called" << std::endl;

}

myClass::myClass(const myClass& ){
  std::cout << "copy constructor called" << std::endl; 

}

myClass::~myClass(){
  std::cout << "destructor called" << std::endl;

}


myClass myClass::operator=(const myClass& object){
  std::cout << "assignment operator called" << std::endl;
  return object;

}
