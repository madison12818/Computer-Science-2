//  String class test program
//
//  Name: test_default_ctor.cpp
//  Tests: default constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str;

    // PRINT
    std::cout << "str = " << str << "\n";

    // VERIFY
    assert(str == "");
  }

  std::cout << "\nDone testing default constructor\n\n";
}
