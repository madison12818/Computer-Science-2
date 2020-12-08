//  String class test program
//
//  Name: test_len_cap.cpp
//  Tests: length, capacity, substr, findch, and findstr
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
    String  str;

    // TEST
    int     result = str.capacity();

    // PRINT
    std::cout << "str.capacity() = " << result << "\n";

    // VERIFY
    assert(str    == "");
    assert(result == 0);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("0123456789");

    // TEST
    int     result = str.length();

    // PRINT
    std::cout << "str = 0123456789 and str.length() = " << result << "\n";

    // VERIFY
    assert(str    == "0123456789");
    assert(result == 10);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str;

    // TEST
    int     result = str.length();

    // PRINT
    std::cout << "str is empty and str.length() = " << result << "\n";

    // VERIFY
    assert(str    == "");
    assert(result == 0);
  }

  std::cout << "\nDone testing length and capacity functions.\n\n";
}
