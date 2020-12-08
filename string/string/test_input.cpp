//  String class test program
//
//  Name: test_input.cpp
//  Tests: >> operators
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

//===========================================================================
int main (){

   std::ifstream in("input_file.txt"); // Define stream for input
   if(!in){ // Make sure it opened correctly.
                             
      std::cout << "Could not open input_test.txt, exiting." << std::endl;
      exit(1);
   }

   const int wordsInFile = 10;

   // SETUP 
   String strArray[wordsInFile];
   int j = 0;
   while (!in.eof() && j < wordsInFile){
      in >> strArray[j];
      ++j;
   }
  
   // PRINT
   for (int i = 0; i < wordsInFile; ++i){
      std::cout << i << ". " << strArray[i] << " ";
   }
   std::cout << "\n";

   // VERIFY
   assert (strArray[2] == "two");
   assert (strArray[8] == "eight");
   assert (strArray[4] == "four");
   assert (strArray[0] == "zero");
   assert (strArray[9] == "nine");

   std::cout << "\nDone testing >> operator.\n\n";
}
