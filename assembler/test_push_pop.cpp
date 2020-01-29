//
// Tests: push and pop
//

#include "stack.hpp"
#include <iostream>
#include <cassert>

//=================================================================
int main()
{
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<String>  stk;

    // TEST
    stk.push("bake"); stk.push("sale");

    // PRINT
    std::cout << "stk: ";
    stk.print();
    std::cout << '\n';

    // VERIFY
    assert(stk.top() == "sale");
    assert(stk.pop() == "sale");
    assert(stk.pop() == "bake");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<int>  stk;

    // TEST
    stk.push(1); stk.push(2); stk.push(3);

    // PRINT
    std::cout << "stk: ";
    stk.print();
    std::cout << '\n';

    // VERIFY
    assert(stk.top() == 3);
    assert(stk.pop() == 3);
    assert(stk.pop() == 2);
    assert(stk.pop() == 1);
  }

  std::cout << "\nDone testing push, pop, and top\n\n";

}
