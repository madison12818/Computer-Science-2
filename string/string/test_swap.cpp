//  String class test program
//
//  Name:  test_swap.cpp
//  Tests: swap
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
    String  first("first");
    String  second("second");

    // TEST
    first.swap(second);

    // PRINT
    std::cout << "first = " << first << " and second = " << second << "\n";

    // VERIFY
    assert(second == "first");
    assert(first  == "second");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  first;
    String  second("second");

    // TEST
    first.swap(second);

    // PRINT
    std::cout << "first = " << first << " and second = " << second << "\n";

    // VERIFY
    assert(second == "");
    assert(first  == "second");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  first("first");
    String  second;

    // TEST
    first.swap(second);

    // PRINT
    std::cout << "first = " << first << " and second = " << second << "\n";

    // VERIFY
    assert(second == "first");
    assert(first  == "");
  }
  
  std::cout << "\nDone testing swap\n\n";
}
