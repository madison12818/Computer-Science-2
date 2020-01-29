// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

	// Print
	std::cout << "bigint = 4, bi[0] = " << digit << "\n";

        // Verify
        assert(digit == 4);
    }
    
    {
      // Setup
      bigint bi("55555555555555555555555");

      // Test
      int digit = bi[22];

      // Print
      std::cout << "bigint = 55555555555555555555555, bi[22] = " << digit << "\n";

      // Verify
      assert(digit == 5);
    }

    {
      // Setup
      bigint bi("123456789");

      // Test
      int digit = bi[6];

      // Print
      std::cout << "bigint = 123456789, bi[6] = " << digit << "\n";

      // Verify
      assert(digit == 3);
    }

    std::cout << "Done testing subscript." << std::endl;
}

