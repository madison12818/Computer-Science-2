//
// Tests: Default Constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//=================================================================
int main()
{
  {
    //------------------------------------------------------
    // TEST
    stack<int> stk;

    // VERIFY
    assert(stk.empty());
  }

  std::cout << "\nDone testing default constructor\n\n";

}
