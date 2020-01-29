#ifndef UTILITIES_HPP
#define UTILITIES_HPP
////////////////////////////////////////////////////////////////////////////
//
// utilities.hpp, contains function prototypes
// Madison Dockery
// 4/5/2019

#include <iostream>
#include "../string/string.hpp"
#include "stack.hpp"

////////////////////////////////////////////////////////////////////////////
//
String StringToPostfix(String);

String StringToPrefix(String);

String evaluate(String, String, String, std::ostream&);

void PostfixToAssembly(String, std::ostream&);

void PrefixToAssembly(String, std::ostream&);

#endif // UTILITIES_HPP
