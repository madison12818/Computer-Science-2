//
// Tests: copy constructor, uses push
//

#include "stack.hpp"
#include <iostream>
#include <cassert>

//============================================================
int main()
{
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<int> stk;
    stk.push(1); stk.push(2); stk.push(3);

    // TEST
    stack<int> newStk(stk);

    // PRINT
    std::cout << "stk: "; stk.print();
    std::cout << "newStk: "; newStk.print();
    std::cout << '\n';
    // VERIFY
    assert(stk == newStk);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<String> stk;

    // TEST
    stack<String> newStk(stk);

    // VERIFY
    assert(stk == newStk);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<String> stk;
    stk.push("boom"); stk.push("pow");

    // TEST
    stack<String> newStk(stk);

    // PRINT
    std::cout << "stk: "; stk.print(); 
    std::cout << "newStk: "; newStk.print();
    std::cout << '\n';

    // VERIFY
    assert(stk == newStk);
  }

  std::cout << "\nDone testing copy constructor\n\n";
}
