//
// infix2prefix lab
//

// Given in lab
#include <iostream>
#include <fstream>
#include <vector>
#include "../string/string.hpp"
#include "../assembler/stack.hpp"

// Maybe allowed??
#include <cstdlib>

// StringToPrefix and main were give in lab but empty except return statements

String StringToPrefix(String infixExp) {
 
  stack<String> result;
  std::vector<String> tokens = infixExp.split(' ');
  int size = tokens.size() - 1;
  for (int i = 0; i < size; ++i) {
    
    if (tokens[i] == ')') {
      
      String right = result.pop();
      String oper = result.pop();
      String left = result.pop();

      result.push(oper + " " + left +  " " + right);
    }
    else if (tokens[i] != '(') {
      result.push(tokens[i]);
    }
  }

  return result.top();
}

int main() {
 
  //opening file
  std::ifstream inFile("data3-1.txt");
  if(!inFile){                            // Make sure it opened correctly.
    std::cout << "Could not open data3-1.txt, exiting." << std::endl;
    exit(1);
  }

  while (!inFile.eof()) {
    
    String tmp;
    char inChar = inFile.get();
    while (inChar != '\n' && !inFile.eof()) {
      tmp += inChar;
      inChar = inFile.get();
    }

    if (tmp != "") {
      std::cout << "Infix: " << tmp << '\n';
      std::cout << "Prefix: " << StringToPrefix(tmp) << '\n';
    }
  }  

  inFile.close();
  
  return 0;
}
