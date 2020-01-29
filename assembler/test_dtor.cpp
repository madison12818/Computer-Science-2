//
// Tests: Destructor
//

#include "stack.hpp"
#include <iostream>
#include <cassert>

//===========================================================
int main()
{
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<String> stk;
    stk.push("you"); stk.push("a dork");

    // TEST
    stk.~stack();

    // VERIFY
    assert(stk.empty() == true);
  }

  std::cout << "\nDone testing destructor\n\n";
}
