// add.cpp
//
// Project 1

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main(){

   std::ifstream in("data1-1.txt");    // Define stream for input
   if(!in){                            // Make sure it opened correctly.
      std::cout << "Could not open data1-1.txt, exiting." << std::endl;
      exit(1);
   }
    
   bigint left;
   bigint right;
   bigint result;

   while (!in.eof()){
      in >> left;
      in >> right;

      // if end of file, left and right get defaulted to 0
      if (!(left == 0) && !(right == 0)){
         std::cout << "Left: " << left << "\n\n"
		   << "Right: " << right << "\n\n";
	  
	 result = left + right;
	  
	 std::cout << "Result: " << result << "\n\n";
      }
   }
 
   in.close();
   return 0;
}
