//object_construction.hpp

#ifndef OBJECT_CONSTRUCTION_HPP
#define OBJECT_CONSTRUCTION_HPP

class myClass {
public:
  myClass();  //default constructor
  myClass(const myClass&);  //copy constructor
  ~myClass();  //destructor

  myClass operator=(const myClass&); //assignmenet overload

//private:
  //int* x;


};

#endif 

