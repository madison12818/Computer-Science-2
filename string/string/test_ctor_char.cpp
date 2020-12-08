//  String class test program
//
//  Name: test_ctor_char.cpp
//  Tests: char constructor
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
    String  str('a');

    // PRINT
    std::cout << "str(a) = " << str << "\n";

    // VERIFY
    assert(str == 'a');
  }

  std::cout << "\nDone testing char constructor\n\n";
}
