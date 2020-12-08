//  String class test program
//
//  Name: test_generic_ctor.cpp
//  Tests: constructors
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

        // TEST
        String  str();

	// PRINT
	std::cout << "str() = " << str << "\n"; 

        // VERIFY
        assert(str == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

	// PRINT
	std::cout << "str(a) = " << str << "\n";

        // VERIFY
        assert(str == 'a');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("In the kitchen, wrist twistin' like a stir fry");

	// PRINT
	std::cout << "str(In the kitchen, wrist twistin' like a stir fry) = " << str << "\n";

        // VERIFY
        assert(str == "In the kitchen, wrist twistin' like a stir fry");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("");

	// PRINT
	std::cout << "str() = " << str << "\n";

        // VERIFY
        assert(str == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('d');

	// PRINT
	std::cout << "str(d) = " << str << "\n";

        // VERIFY
        assert(str == 'd');
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "\nDone testing constructors.\n\n";

}

