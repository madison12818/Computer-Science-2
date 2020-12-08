//  String class test program
//
//  Name:  test_equal.cpp
//  Tests: == operator
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
    String  left("Dance with my dogs in the nighttime");
    String  right("Dance with my dogs in the nighttime");

    // TEST
    bool    result = (left == right);

    // PRINT
    std::cout << left << " == " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == true);
    assert(left   == "Dance with my dogs in the nighttime");
    assert(right  == "Dance with my dogs in the nighttime");
  }
  
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left("Dance with my dogs");
    String  right("Dance with my dogs in the nighttime");

    // TEST
    bool    result = (left == right);

    // PRINT
    std::cout << left << " == " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == false);
    assert(left   == "Dance with my dogs");
    assert(right  == "Dance with my dogs in the nighttime");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    char    left = 'a';
    String  right('a');

    // TEST
    bool    result = (left == right);

    // PRINT
    std::cout << left << " == " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == true);
    assert(left   == 'a');
    assert(right  == 'a');
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    char    left = 'a';
    String  right("bac");

    // TEST
    bool    result = (left == right);

    // PRINT
    std::cout << left << " == " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == false);
    assert(left   == 'a');
    assert(right  == "bac");
  }
  
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    char    left[] = "In that skillet, watch me flip it like it's Five Guys";
    String  right("bac");

    // TEST
    bool    result = (left == right);

    // PRINT
    std::cout << left << " == " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == false);
    assert(right  == "bac");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    char    left[] = "In that skillet, watch me flip it like it's Five Guys";
    String  right("In that skillet, watch me flip it like it's Five Guys");

    // TEST
    bool    result = (left == right);

    // PRINT
    std::cout << left << " == " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == true);
    assert(right  == "In that skillet, watch me flip it like it's Five Guys");
  }

  std::cout << "\nDone testing == operator.\n\n";
}
