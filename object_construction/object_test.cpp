//object_test.cpp

#include "object_construction.hpp"

int main(){
  
  myClass object1;
  myClass object2(object1);
  myClass object3;
  
  //object1 = object2;
  object3 = object1;

  

  return 0;

}
