//
// Tests: assign operator
//

#include "stack.hpp"
#include <iostream>
#include <cassert>

//===================================================================
int main()
{
  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<int> first;
    first.push(1); first.push(2); first.push(3);
    stack<int> second;
    second.push(1); second.push(2);
    stack<int> third;
    third.push(9);

    // TEST
    first = second = third;

    // PRINT
    std::cout << "first: "; first.print();
    std::cout << "second: "; second.print();
    std::cout << "third: "; third.print();
    std::cout << '\n';

    // VERIFY
    assert(first  == third);
    assert(second == third);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<String> first;
    first.push("don't"); first.push("stop"); first.push("the music");
    stack<String> second;
    second.push("by"); second.push("rihanna");
    stack<String> third;
    third.push("cheeks");

    // TEST
    first = second = third;

    // PRINT
    std::cout << "first: "; first.print();
    std::cout << "second: "; second.print();
    std::cout << "third: "; third.print();
    std::cout << '\n';

    // VERIFY
    assert(first  == third);
    assert(second == third);
  }

  std::cout << "\nDone testing assign operator\n\n";
}
