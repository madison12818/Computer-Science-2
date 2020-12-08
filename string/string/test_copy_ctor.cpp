//  String class test program
//
//  Name: test_copy_ctor.cpp
//  Tests: copy constructor
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
    String  copiedStr(str);

    // PRINT
    std::cout << "In the kitchen, wrist twistin' like a stir fry = " << copiedStr << "\n";

    // VERIFY
    assert(str       == "In the kitchen, wrist twistin' like a stir fry");
    assert(copiedStr == "In the kitchen, wrist twistin' like a stir fry");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE

    // TEST
    String  str("");
    String  copiedStr(str);

    // PRINT
    std::cout << " = " << copiedStr << "\n";

    // VERIFY
    assert(str       == "");
    assert(copiedStr == "");
  }

  std::cout << "\nDone testing copy constructor\n\n";
}
