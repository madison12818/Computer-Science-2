////////////////////////////////////////////////////////////////////////////
//
// utilities.cpp, contains function definitions for utilities
// Madison Dockery
// 4/5/2019

#include "utilities.hpp"

////////////////////////////////////////////////////////////////////////////
//
String StringToPostfix(String infixExp) {
  
  stack<String> result;
  std::vector<String> tokens = infixExp.split(' ');
  int size = tokens.size() - 1;
  for (int i = 0; i < size; ++i) {
    
    if (tokens[i] == ')') {
      
      String right = result.pop();
      String oper = result.pop();
      String left = result.pop();

      result.push(left + " " + right + " " + oper);
    }
    else if (tokens[i] != '(') {
      result.push(tokens[i]);
    }
  }

  return result.top();
}

String StringToPrefix(String infixExp) {

  stack<String> result;
  std::vector<String> tokens = infixExp.split(' ');
  int size = tokens.size() - 1;
  for (int i = 0; i < size; ++i) {

    if (tokens[i] == ')') {

      String right = result.pop();
      String oper = result.pop();
      String left = result.pop();

      result.push(oper + " " + left + " " + right);
    }
    else if (tokens[i] != '(') {
      result.push(tokens[i]);
    }
  }

  return result.top();
}

String evaluate(String leftOp, String op, 
	        String rightOp, std::ostream& out) {

  // load leftOp
  out << "\tLD\t" << leftOp << std::endl;

  // choose the correct op to perform on rightOp
  if      (op == '+') out << "\tAD\t";
  else if (op == '-') out << "\tSB\t";
  else if (op == '*') out << "\tMU\t";
  else                out << "\tDV\t";
  out << rightOp << std::endl;

  // create num to keep track of TMP
  static int num = 0;
  ++num;

  // convert num to string
  String numStr;
  for (int tmp = num; tmp != 0; tmp = tmp / 10) {

      int digit = tmp % 10;
      char tmpChar = digit + 48;
      numStr = tmpChar + numStr;
  }
  numStr = String("TMP") + numStr;
  
  // store TMPn
  out << "\tST\t" << numStr << std::endl;

  return numStr;
}

void PostfixToAssembly(String postfix, std::ostream& out) {

  std::vector<String> tokens = postfix.split(' ');
  int size = tokens.size();
  stack<String> assembly;
  for (int i = 0; i < size; ++i) {

      if (tokens[i] != '+' && tokens[i] != '-' &&
	  tokens[i] != '/' && tokens[i] != '*')
	assembly.push(tokens[i]);
      
      else {

	  String right = assembly.pop();
	  String left = assembly.pop();
	  assembly.push(evaluate(left, tokens[i], right, out));
      }
  }
}

void PrefixToAssembly(String prefix, std::ostream& out) {

  std::vector<String> tokens = prefix.split(' ');
  int size = tokens.size() - 1;
  stack<String> assembly;
  for (int i = size; i >= 0; --i) {

      if (tokens[i] != '+' && tokens[i] != '-' &&
          tokens[i] != '/' && tokens[i] != '*')
        assembly.push(tokens[i]);

      else {

          String left = assembly.pop();
          String right = assembly.pop();
          assembly.push(evaluate(left, tokens[i], right, out));
      }
  }
}
