//
// Tests: postfix
//

#include "stack.hpp"
#include "utilities.hpp"
#include <iostream>
#include <cassert>

//===================================================================
int main()
{
  {
    // SETUP
    String infix("( AX + ( B * C ) ) ;");

    // TEST
    String postfix = StringToPostfix(infix);

    // PRINT
    std::cout << "Infix: " << infix << '\n'
	      << "Postfix: " << postfix << '\n';

    // VERIFY
    assert(postfix == "AX B C * +");
  }

  {
    // SETUP
    String infix("( ( AX + ( B * CY ) ) / ( D - E ) ) ;");

    // TEST
    String postfix = StringToPostfix(infix);

    // PRINT
    std::cout << "Infix: " << infix << '\n'
              << "Postfix: " << postfix << '\n';

    // VERIFY
    assert(postfix == "AX B CY * + D E - /");
  }

  {
    // SETUP
    String infix("( ( A + B ) * ( C + E ) ) ;");

    // TEST
    String postfix = StringToPostfix(infix);

    // PRINT
    std::cout << "Infix: " << infix << '\n'
              << "Postfix: " << postfix << '\n';

    // VERIFY
    assert(postfix == "A B + C E + *");
  }

  {
    // SETUP
    String infix("( AX * ( BX * ( ( ( CY + AY ) + BY ) * CX ) ) ) ;");

    // TEST
    String postfix = StringToPostfix(infix);

    // PRINT
    std::cout << "Infix: " << infix << '\n'
              << "Postfix: " << postfix << '\n';

    // VERIFY
    assert(postfix == "AX BX CY AY + BY + CX * * *");
  }

  {
    // SETUP
    String infix("( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;");

    // TEST
    String postfix = StringToPostfix(infix);

    // PRINT
    std::cout << "Infix: " << infix << '\n'
              << "Postfix: " << postfix << '\n';

    // VERIFY
    assert(postfix == "H A B C + D * + F * G * E * * J +");
  }

  std::cout << "\nDone testing postfix\n\n";
}
