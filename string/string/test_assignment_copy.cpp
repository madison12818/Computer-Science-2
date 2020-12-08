//  String class test program
//
//  Name:  test_assignment_copy.cpp
//  Tests: = operator
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
    String  third("third");

    // TEST
    first = second = third;

    // PRINT
    std::cout << first << " = " << second << " = " << third << "\n";

    // VERIFY
    assert(first  == "third");
    assert(second == "third");
    assert(third  == "third");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  first("bam");
    String  second("boom");
    String  third("pow");

    // TEST
    first = second = third;

    // PRINT
    std::cout << first << " = " << second << " = " << third << "\n";

    // VERIFY
    assert(first  == "pow");
    assert(second == "pow");
    assert(third  == "pow");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  first("butt");
    String  second("cheeks");
    String  third("");

    // TEST
    first = second = third;

    // PRINT
    std::cout << first << " = " << second << " = " << third << "\n";

    // VERIFY
    assert(first  == "");
    assert(second == "");
    assert(third  == "");
  }

  std::cout << "\nDone testing assignment copy\n\n";
}
