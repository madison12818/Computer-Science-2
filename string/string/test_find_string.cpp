//  String class test program
//
//  Name: test_find_string.cpp
//  Tests: findstr
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
    String  str("01234");

    // TEST
    int     result = str.findstr(0, "234");

    // PRINT
    std::cout << "str = 01234 and str.findstr(0, 234) = " << result << "\n";

    // VERIFY
    assert(str    == "01234");
    assert(result == 2);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("01234");

    // TEST
    int     result = str.findstr(0, "3456");

    // PRINT
    std::cout << "str = 01234 and str.findstr(0, 3456) = " << result << "\n";

    // VERIFY
    assert(str    == "01234");
    assert(result == -1);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("01234");

    // TEST
    int     result = str.findstr(3, "12");

    // PRINT
    std::cout << "str = 01234 and str.findstr(3, 12) = " << result << "\n";

    // VERIFY
    assert(str    == "01234");
    assert(result == -1);
  }

  std::cout << "\nDone testing findstr function.\n\n";
}
