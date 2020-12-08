//  String class test program
//
//  Name: test_generic_member_function_return.cpp
//  Tests: length, capacity, substr, findch, and findstr
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
        String  str();

        // TEST
        int     result = str.capacity();

	// PRINT
	std::cout << "str.capacity() = " << result << "\n";

        // VERIFY
        assert(str    == "");
        assert(result == STRING_SIZE);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("0123456789");

        // TEST
        int     result = str.length();

	// PRINT
	std::cout << "str = 0123456789 and str.length() = " << result << "\n";

        // VERIFY
        assert(str    == "0123456789");
        assert(result == 10);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str();

        // TEST
        int     result = str.length();

	// PRINT
	std::cout << "str is empty and str.length() = " << result << "\n";

        // VERIFY
        assert(str    == "");
        assert(result == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("0123456789");

        // TEST
        String  result = str.substr(0, 5);

	// PRINT
	std::cout << "str = 0123456789 and str.substr(0, 5) = " << result << "\n";

        // VERIFY
        assert(str    == "0123456789");
        assert(result == "012345");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("0123456789");

        // TEST
        String  result = str.substr(5,9);

	// PRINT
	std::cout << "str = 0123456789 and str.substr(5, 9) = " << result << "\n";

        // VERIFY
        assert(str    == "0123456789");
        assert(result == "56789");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("0123456789");

        // TEST
        int     result = str.findch('8');

	// PRINT
	std::cout << "str = 0123456789 and str.findch(8) = " << result << "\n";

        // VERIFY
        assert(str    == "0123456789");
        assert(result == 8);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("01234");

        // TEST
        int     result = str.findch('8');

        // PRINT
        std::cout << "str = 01234 and str.findch(8) = " << result << "\n";

        // VERIFY
        assert(str    == "01234");
        assert(result == -1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("01234");

        // TEST
        int     result = str.findstr("234");

        // PRINT
        std::cout << "str = 01234 and str.findstr(234) = " << result << "\n";

        // VERIFY
        assert(str    == "01234");
        assert(result == 2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("01234");

        // TEST
        int     result = str.findstr("3456");

        // PRINT
        std::cout << "str = 01234 and str.findstr(3456) = " << result << "\n";

        // VERIFY
        assert(str    == "01234");
        assert(result == -1);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "\nDone testing length, findch, substr, findstr, and capacity.\n\n";
}

