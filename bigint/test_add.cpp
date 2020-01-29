// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;
	
	// Print
	std::cout << left << " + " << right << " = " << result << "\n";

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Print
      std::cout << left << " + " << right << " = " << result << "\n";

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Print
      std::cout << left << " + " << right << " = " << result << "\n";

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1234");
      bigint right("1234");
      bigint result;

      // Test
      result = left + right;

      // Print
      std::cout << left << " + " << right << " = " << result << "\n";

      // Verify
      assert(left   == 1234);
      assert(right  == 1234);
      assert(result == 2468);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("987654321");
      bigint right("123456789");
      bigint result;

      // Test
      result = left + right;

      // Print
      std::cout << left << " + " << right << " = " << result << "\n";

      // Verify
      assert(left   == 987654321);
      assert(right  == 123456789);
      assert(result == 1111111110);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("568695216");
      bigint right("48");
      bigint result;

      // Test
      result = left + right;

      // Print
      std::cout << left << " + " << right << " = " << result << "\n";

      // Verify
      assert(left   == 568695216);
      assert(right  == 48);
      assert(result == 568695264);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("48");
      bigint right("568695216");
      bigint result;

      // Test
      result = left + right;

      // Print
      std::cout << left << " + " << right << " = " << result << "\n";

      // Verify
      assert(left   == 48);
      assert(right  == 568695216);
      assert(result == 568695264);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("9999");
      bigint right("0");
      bigint result;

      // Test
      result = left + right;

      // Print
      std::cout << left << " + " << right << " = " << result << "\n";

      // Verify
      assert(left   == 9999);
      assert(right  == 0);
      assert(result == 9999);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("99999999999999999999999999999999999999999999999999999999999999");
      bigint right("8888888888888888888888888888888888888888888");
      bigint result;

      // Test
      result = left + right;

      // Print
      std::cout << left << " + " << right << " = " << result << "\n";

      // Verify
      assert(left   == "99999999999999999999999999999999999999999999999999999999999999");
      assert(right  == "8888888888888888888888888888888888888888888");
      assert(result == "100000000000000000008888888888888888888888888888888888888888887");
    }
    
    //Add test cases as needed.
    
    

    
    std::cout << "Done with testing addition." << std::endl;
}

