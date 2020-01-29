//
// fib.cpp
//

#include<iostream>

/*
void fibFor(int end){ //for loop fib version
  int a = 0,  b = 1, nextTerm = 0;
  if(end == 1){
    std::cout << a;
  }
  else if(end > 1){
      std::cout << a << ", " << b << ", ";
  }
  for(int i = 3; i < end; ++i){
      nextTerm = a+b;
      a=b;
      b = nextTerm;
      std::cout << nextTerm << ", ";
  }
  nextTerm = a+b;
  std::cout << nextTerm;  
}
*/

int fibRec(int end){ //recursive fib version
  if(end == 0){
    return 0;
  }
  else if(end == 1){
    return 1;
  }
  
  return fibRec(end-1)+fibRec(end-2);
}

int fibTail(int end, int term1, int term2) { //tail recursive fib version
   
  if(end == 0){
    return 0;
  }
  else if(end == 1){
    return 1;
  }
  
  return fibTail(end-1, term2, term1+term2);  
}

int main(){

  std::cout << "How many numbers of fib seq?\n";
  int end;
  std::cin >> end;
  
  /*
  //for loop version
  fibFor(end);
  std::cout << "\nfor loop fib done\n";
  */

  //recursive version
  fibRec(end);
  for(int i = 0; i < end-1; ++i){
    std::cout << fibRec(i) << ", ";
  }
  std::cout << fibRec(end-1) << std::endl;
  std::cout << "recursive fib done\n";

  //tail recursive version
  fibTail(end, 0, 1);
  for(int i = 0; i < end-1; ++i){
    std::cout << fibRec(i) << ", ";
  }
  std::cout << fibRec(end-1) << std::endl;
  std::cout << "tail fib done\n";



}
