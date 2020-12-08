//  String class test program
//
//  Name:  test_generic_binary_op.cpp
//  Tests: Relational operators, concatination and outputing
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
        String  right();

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
        String  left();
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
        assert(left   == "now im not chaffing anymore");
        assert(right  == ", thank heavens");
    }

    std::cout << "\nDone testing + operator.\n\n"; 
    
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
        assert(right  == "aaaa");
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
        assert(left   == "ggggg");
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

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("baaac");
        String  right("baaac");

        // TEST
        bool    result = (left != right);

        // PRINT
        std::cout << left << " != " << right << " is " << std::boolalpha <<  result << "\n";

        // VERIFY
        assert(result == false);
        assert(left   == "baaac");
        assert(right  == "baaac");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("ba");
        String  right("baaac");

        // TEST
        bool    result = (left != right);

        // PRINT
        std::cout << left << " != " << right << " is " << std::boolalpha <<  result << "\n";

        // VERIFY
        assert(result == true);
        assert(left   == "ba");
        assert(right  == "baaac");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("ba");
        String  right("baaac");

        // TEST
        bool    result = (left > right);

        // PRINT
        std::cout << left << " > " << right << " is " << std::boolalpha <<  result << "\n";

        // VERIFY
        assert(result == false);
        assert(left   == "ba");
        assert(right  == "baaac");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("xxba");
        String  right("baaac");

        // TEST
        bool    result = (left > right);

        // PRINT
        std::cout << left << " > " << right << " is " << std::boolalpha <<  result << "\n";

        // VERIFY
        assert(result == true);
        assert(left   == "xxba");
        assert(right  == "baaac");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("xxba");
        String  right("baaac");

        // TEST
        bool    result = (left >= right);

        // PRINT
        std::cout << left << " >= " << right << " is " << std::boolalpha <<  result << "\n";

        // VERIFY
        assert(result == true);
        assert(left   == "xxba");
        assert(right  == "baaac");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("baaac");
        String  right("baaac");

        // TEST
        bool    result = (left >= right);

        // PRINT
        std::cout << left << " >= " << right << " is " << std::boolalpha <<  result << "\n";

        // VERIFY
        assert(result == true);
        assert(left   == "xxba");
        assert(right  == "baaac");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "\nDone testing relational operators.\n\n";
}

