////////////////////////////////////////////////////////////////////////////
//
// postfix.cpp, reads infix expressions and writes postfix expressions to file
// Madison Dockery
// 4/5/2019

#include "utilities.hpp"
#include <fstream>

////////////////////////////////////////////////////////////////////////////
//
int main(int argc, char* argv[]) {
  
  // check num of arguments
  if (argc < 2 || argc > 3) {

    std::cout << "Not a proper command.\n"
	      << "postfix input [output]\n";
    return 1;
  }

  //opening file
  std::ifstream inFile(argv[1]);
  if(!inFile){                            // Make sure it opened correctly.

    std::cout << "Could not open file, exiting." << std::endl;
    exit(1);
  }
  
  // check if output file given
  bool outputFileGiven = false; // just for read-ability
  std::ofstream output;
  if (argc == 3) {

    output.open(argv[2]);
    outputFileGiven = true;
  }  

  // begin reading file
  while (!inFile.eof()) {
    
    String tmp;
    char inChar = inFile.get();
    while (inChar != '\n' && !inFile.eof()) {
      tmp += inChar;
      inChar = inFile.get();
    }

    if (tmp != "" && !outputFileGiven) {
      std::cout << "Infix: " << tmp << '\n';
      std::cout << "Postfix: " << StringToPostfix(tmp) << "\n\n";
    }
    else if (tmp != "" && outputFileGiven) {
      output << "Infix: " << tmp << '\n';
      output << "Postfix: " << StringToPostfix(tmp) << "\n\n";
    }
  }  

  inFile.close();
  output.close();

  return 0;
  
    
}
