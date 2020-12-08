//  String class test program
//
//  Name: test_subscript.cpp
//  Tests: [] operators
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
    char    result = str[5];

    // PRINT
    std::cout << "str = " << str << ", str[5] = " << result << "\n";

    // VERIFY
    assert(str    == "0123456789");
    assert(result == '5');
  }
  
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("0123456789");

    // TEST
    String  result = str; 
    result[5] = '8';

    // PRINT
    std::cout << "before str = " << str << " then str[5] = 8, now str = " << result << "\n";

    // VERIFY
    assert(str    == "0123456789");
    assert(result == "0123486789");
  }

  std::cout << "\nDone testing [] operators.\n\n";
}
