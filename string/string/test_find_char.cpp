//  String class test program
//
//  Name: test_find_char.cpp
//  Tests: findch
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
    int     result = str.findch(5, '8');

    // PRINT
    std::cout << "str = 0123456789 and str.findch(5, '8') = " << result << "\n";

    // VERIFY
    assert(str    == "0123456789");
    assert(result == 8);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("01234");

    // TEST
    int     result = str.findch(3, '0');

    // PRINT
    std::cout << "str = 01234 and str.findch(3, '0') = " << result << "\n";

    // VERIFY
    assert(str    == "01234");
    assert(result == -1);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("01234");

    // TEST
    int     result = str.findch(0, '9');

    // PRINT
    std::cout << "str = 01234 and str.findch(0, '9') = " << result << "\n";

    // VERIFY
    assert(str    == "01234");
    assert(result == -1);
  }

  std::cout << "\nDone testing findch function.\n\n";
}
