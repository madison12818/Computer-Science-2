//  String class test program
//
//  Name:  test_lessThan.cpp
//  Tests: < and <= operators
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
    String  left("aaaa");
    String  right("aaaab");

    // TEST
    bool    result = (left < right);

    // PRINT
    std::cout << left << " < " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == true);
    assert(left   == "aaaa");
    assert(right  == "aaaab");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left("aaaab");
    String  right("aaaa");

    // TEST
    bool    result = (left < right);

    // PRINT
    std::cout << left << " < " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == false);
    assert(left   == "aaaab");
    assert(right  == "aaaa");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left("aaaab");
    String  right("aaaac");

    // TEST
    bool    result = (left < right);

    // PRINT
    std::cout << left << " < " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == true);
    assert(left   == "aaaab");
    assert(right  == "aaaac");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    char    left = 'a';
    String  right("baaac");

    // TEST
    bool    result = (left < right);

    // PRINT
    std::cout << left << " < " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == true);
    assert(left   == 'a');
    assert(right  == "baaac");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    char    left[] = "ggggg";
    String  right("baaac");

    // TEST
    bool    result = (left < right);

    // PRINT
    std::cout << left << " < " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == false);
    assert(right  == "baaac");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left("ggggg");
    String  right("baaac");

    // TEST
    bool    result = (left <= right);

    // PRINT
    std::cout << left << " <= " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == false);
    assert(left   == "ggggg");
    assert(right  == "baaac");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  left("baaac");
    String  right("baaac");

    // TEST
    bool    result = (left <= right);

    // PRINT
    std::cout << left << " <= " << right << " is " << std::boolalpha <<  result << "\n";

    // VERIFY
    assert(result == true);
    assert(left   == "baaac");
    assert(right  == "baaac");
  }

  std::cout << "\nDone testing < and <= operators.\n\n";
}
