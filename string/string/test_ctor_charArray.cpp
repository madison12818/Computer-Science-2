//  String class test program
//
//  Name: test_ctor_charArray.cpp
//  Tests: char array constructor
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
    String  str("In the kitchen, wrist twistin' like a stir fry");

    // PRINT
    std::cout << "str(In the kitchen, wrist twistin' like a stir fry) = " << str << "\n";

    // VERIFY
    assert(str == "In the kitchen, wrist twistin' like a stir fry");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("");

    // PRINT
    std::cout << "str = " << str << "\n";

    // VERIFY
    assert(str == "");
  }

  std::cout << "\nDone testing char array constructor.\n\n";
}
