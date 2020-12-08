//  String class test program
//
//  Name:  test_concat.cpp
//  Tests: + and += operators
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
    String  left("first");
    String  right("second");

    // TEST
    String  result = (left + right);

    // PRINT
    std::cout << left << " + " << right << " = " << result << "\n";

    // VERIFY
    assert(result == "firstsecond");
    assert(left   == "first");
    assert(right  == "second");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left("boom ba da bum");
    String  right;

    // TEST
    String  result = (left + right);

    // PRINT
    std::cout << left << " + " << right << " = " << result << "\n";

    // VERIFY
    assert(result == "boom ba da bum");
    assert(left   == "boom ba da bum");
    assert(right  == "");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left;
    String  right("babypowder");

    // TEST
    String  result = (left + right);

    // PRINT
    std::cout << left << " + " << right << " = " << result << "\n";

    // VERIFY
    assert(result == "babypowder");
    assert(left   == "");
    assert(right  == "babypowder");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    char    left = 'o';
    String  right("n my bum");

    // TEST
    String  result = (left + right);

    // PRINT
    std::cout << left << " + " << right << " = " << result << "\n";

    // VERIFY
    assert(result == "on my bum");
    assert(left   == 'o');
    assert(right  == "n my bum");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left("spread on both cheek");
    char    right = 's';

    // TEST
    String  result = (left + right);

    // PRINT
    std::cout << left << " + " << right << " = " << result << "\n";

    // VERIFY
    assert(result == "spread on both cheeks");
    assert(left   == "spread on both cheek");
    assert(right  == 's');
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    char    left[] = "now im not chaffing anymore";
    String  right(", thank heavens");

    // TEST
    String  result = (left + right);

    // PRINT
    std::cout << left << " + " << right << " = " << result << "\n";

    // VERIFY
    assert(result == "now im not chaffing anymore, thank heavens");
    assert(right  == ", thank heavens");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left("now im not chaffing anymore");
    String  right(", thank heavens");

    // PRINT BEFORE
    std::cout << left << " += " << right;

    // TEST
    left += right;

    // PRINT AFTER
    std::cout << " ->  " << left << "\n";

    // VERIFY
    assert(left   == "now im not chaffing anymore, thank heavens");
    assert(right  == ", thank heavens");
  }

  std::cout << "\nDone testing + and += operators\n\n";
}
