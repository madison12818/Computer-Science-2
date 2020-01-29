#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer: Madison Dockery
// Updated:    3/23/2019
//
//
//
//

#include <new>
#include <iostream>
#include <cassert>
#include "../string/string.hpp"

////////////////////////////////////////////////////////////////////////////
//           
template<typename T> 
class Node {
public:
  Node () : next(nullptr) {}
  Node (T dt) : data(dt), next(nullptr) {}
  Node (const Node<T>& cpNode) 
    : data(cpNode.data), next(cpNode.next) {}
  
  T data;
  Node *next;
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//    
template <typename T> //remember to put this above all the functions so you can use T
class stack {
public:
              stack     ();
              stack     (const stack<T>&);
              ~stack    ();
    void      swap      (stack<T>&);
    stack<T>& operator= (stack<T>);
	bool      empty     () const;
	bool      full      () const;
	T         top       () const;
	T         pop       ();
	void      push      (const T&);
        void      print     () const; // used for testing
    bool      operator==(const stack<T>&) const; // used for testing
private:
	Node<T>   *tos;
};

////////////////////////////////////////////////////////////////////////////
// MEMBER FUNCTIONS
//
//

// default constructor
template <typename T>
stack<T>::stack() : tos(nullptr) {};

// copy constructor (uses default constructor)
template <typename T>
stack<T>::stack(const stack<T>& stk) : stack() {

   // move through stack 
   Node<T> *copyItr = stk.tos;
   Node<T> *thisItr;
   while(copyItr != nullptr) {
      if (tos == nullptr) {
         tos =  new Node<T>(copyItr->data);
	 thisItr = tos;
      }

      else {
         thisItr->next = new Node<T>(copyItr->data);
	 thisItr = thisItr->next;
      }

      // move copy iterator forward
      copyItr = copyItr->next;
   }
}

// destructor
template <typename T>
stack<T>::~stack(){

   Node<T> *deleteNode;
   while (tos != nullptr) {
      // get node ready to delete
      deleteNode = tos;
      
      // move itr forward
      tos = tos->next;

      // then delete
      delete deleteNode;
   }
}

// constant time swap
template <typename T>
void stack<T>::swap(stack<T>& swapStack) {

   Node<T> *tmp = tos;
   tos = swapStack.tos;
   swapStack.tos = tmp;
}

// overloaded assignment (using swap)
template <typename T>
stack<T>& stack<T>::operator=(stack<T> stk) {

   this->swap(stk);
   return *this;
}

// return true if stack is empty
template <typename T>
bool stack<T>::empty() const {
   return tos == nullptr;
}

// check if no more memory can be allocated
template <typename T>
bool stack<T>::full() const {
   Node<T> *tmp  = new(std::nothrow) Node<T>();

   // check if memory allocated correctly
   if (tmp == nullptr) return true;

   delete tmp;
   return false;
}

// return data from top of stack
template <typename T>
T stack<T>::top() const  {
   return tos->data;
}

// return and delete top item
template <typename T>
T stack<T>::pop() {

   T tmpData = tos->data;
   Node<T> *deleteNode = tos;

   // move tos to next
   tos = tos->next;

   delete deleteNode;

   return tmpData;
}

// adds item to stack
template <typename T>
void stack<T>::push(const T& dt) {

   assert(!this->full());

   Node<T> *newTos = new Node<T>(dt);

   // set newTos to point to old tos
   newTos->next = tos;

   // update tos
   tos = newTos;
}

// prints whole stack from top to bottom, used for testing
template <typename T>
void stack<T>::print() const {

   Node<T> *itr = tos;
   while(itr != nullptr) {
      std::cout << itr->data << ", ";
      itr = itr->next;
   }
   std::cout << '\n';
}

// used for testing
template <typename T>
bool stack<T>::operator==(const stack<T>& rhs) const {

   Node<T> *lhsItr = tos, *rhsItr = rhs.tos;
   while(lhsItr != nullptr && rhsItr != nullptr) {
      if (lhsItr->data != rhsItr->data){
         return false;
      }

      // move iterators forward
      lhsItr = lhsItr->next;
      rhsItr = rhsItr->next;
   }

   if (rhsItr == nullptr && lhsItr != nullptr) {
      return false;
   }
   else if (rhsItr != nullptr && lhsItr == nullptr) {
      return false;
   }

   return true;
}

#endif

