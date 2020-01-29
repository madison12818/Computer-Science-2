// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(0);

	// Print
	std::cout << "3 times 10^0 = " << bi << "\n";

        // Verify
        assert(bi == 3);  
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint bi(45);

      // Test
      bi = bi.times10(2);

      // Print
      std::cout << "45 times 10^2 = " << bi << "\n";

      // Verify
      assert(bi == 4500);  
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint bi(7889);

      // Test
      bi = bi.times10(10);

      // Print
      std::cout << "7889 times 10^10 = " << bi << "\n";

      // Verify
      assert(bi == "78890000000000");  
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint bi("9876543210000123456789");

      // Test
      bi = bi.times10(12);

      // Print
      std::cout << "9876543210000123456789 times 10^12 = " << bi << "\n";

      // Verify
      assert(bi == "9876543210000123456789000000000000");
    }

    //Add test cases as needed.

    std::cout << "Done testing times_10" << std::endl;
}

