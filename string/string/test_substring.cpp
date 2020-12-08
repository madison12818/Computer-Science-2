//  String class test program
//
//  Name: test_substring.cpp
//  Tests: substr
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
    String  str("0123456789");

    // TEST
    String  result = str.substr(0, 5);

    // PRINT
    std::cout << "str = 0123456789 and str.substr(0, 5) = " << result << "\n";

    // VERIFY
    assert(str    == "0123456789");
    assert(result == "012345");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("0123456789");

    // TEST
    String  result = str.substr(5, 9);

    // PRINT
    std::cout << "str = 0123456789 and str.substr(5, 9) = " << result << "\n";

    // VERIFY
    assert(str    == "0123456789");
    assert(result == "56789");
  }

  std::cout << "\nDone testing substr function.\n\n";
}
