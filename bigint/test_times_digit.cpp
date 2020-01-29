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
        bi = bi.timesDigit(1);

	// Print
	std::cout << "3 times 1 = " << bi << "\n";

        // Verify
        assert(bi == 3); 
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint bi(55);

      // Test
      bi = bi.timesDigit(3);

      // Print
      std::cout << "55 times 3 = " << bi << "\n";

      // Verify
      assert(bi == 165);
    }
    
    {
      //------------------------------------------------------
      // Setup fixture
      bigint bi(150);

      // Test
      bi = bi.timesDigit(4);

      // Print
      std::cout << "150 times 4 = " << bi << "\n";

      // Verify
      assert(bi == 600);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint bi("987648983");

      // Test
      bi = bi.timesDigit(0);

      // Print
      std::cout << "987648983 times 0 = " << bi << "\n";

      // Verify
      assert(bi == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint bi("9500");

      // Test
      bi = bi.timesDigit(9);

      // Print
      std::cout << "9500 times 9 = " << bi << "\n";

      // Verify
      assert(bi == "85500");
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint bi("123454321");

      // Test
      bi = bi.timesDigit(7);

      // Print
      std::cout << "123454321 times 7 = " << bi << "\n";

      // Verify
      assert(bi == "864180247");
    }

    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
}
