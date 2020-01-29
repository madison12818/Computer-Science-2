// factorial.cpp
//
// Project 1

#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
  {
    //------------------------------------------------------
    // Setup fixture
    bigint num(0);
    bigint result;

    // Test 
    result = factorial(num);
    
    // Print
    std::cout << num << "! == " << result << "\n";

    // Verify
    assert(num    == 0);
    assert(result == 1);
  }

  {
    //------------------------------------------------------
    // Setup fixture
    bigint num(3);
    bigint result;

    // Test
    result = factorial(num);

    // Print
    std::cout << num << "! == " << result << "\n";

    // Verify
    assert(num    == 3);
    assert(result == 6);
  }

  {
    //------------------------------------------------------
    // Setup fixture
    bigint num(9);
    bigint result;

    // Test
    result = factorial(num);

    // Print
    std::cout << num << "! == " << result << "\n";

    // Verify
    assert(num    == 9);
    assert(result == "362880");
  }

  {
    //------------------------------------------------------
    // Setup fixture
    bigint num(11);
    bigint result;

    // Test
    result = factorial(num);

    // Print
    std::cout << num << "! == " << result << "\n";

    // Verify
    assert(num    == 11);
    assert(result == "39916800");
  }

  {
    //------------------------------------------------------
    // Setup fixture
    bigint num(13);
    bigint result;

    // Test
    result = factorial(num);

    // Print
    std::cout << num << "! == " << result << "\n";

    // Verify
    assert(num    == 13);
    assert(result == "6227020800");
  }

  {
    //------------------------------------------------------
    // Setup fixture
    bigint num(14);
    bigint result;

    // Test
    result = factorial(num);

    // Print
    std::cout << num << "! == " << result << "\n";

    // Verify
    assert(num    == 14);
    assert(result == "87178291200");
  }

  {
    //------------------------------------------------------
    // Setup fixture
    bigint num(100);
    bigint result;

    // Test
    result = factorial(num);

    // Print
    std::cout << num << "! == " << result << "\n";

    // Verify
    assert(num    == 100);
  }
  
}
