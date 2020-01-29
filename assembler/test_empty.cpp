//
// Tests: empty and == operator
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
    stack<int> check;
    check.push(1); check.push(2); check.push(3);

    // PRINT
    std::cout << "stk: "; stk.print();
    std::cout << '\n';

    // VERIFY
    assert(stk.empty() == false);
    assert(stk == check);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<int> stk;
    stack<int> check;
    check.push(1);

    // PRINT
    std::cout << "stk: "; stk.print();
    std::cout << '\n';

    // VERIFY
    assert(stk.empty() == true);
    assert(!(stk == check));
  }

  std::cout << "\nDone testing empty and == operator\n\n";
}
