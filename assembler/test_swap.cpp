//
// Tests: swap
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
    stack<String> first;
    first.push("bake"); first.push("sale");
    stack<String> second;
    second.push("cookies"); second.push("cupcakes"); second.push("icecream");

    // TEST
    first.swap(second);

    // PRINT
    std::cout << "first: "; first.print();
    std::cout << "second: "; second.print();
    std::cout << '\n';

    // VERIFY
    stack<String> firstCheck;
    firstCheck.push("bake"); firstCheck.push("sale");
    stack<String> secondCheck;
    secondCheck.push("cookies"); secondCheck.push("cupcakes"); secondCheck.push("icecream");
    assert(second == firstCheck);
    assert(first  == secondCheck);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<int> first;
    first.push(123);
    stack<int> second;
    second.push(3); second.push(2); second.push(1);

    // TEST
    first.swap(second);

    // PRINT
    std::cout << "first: "; first.print();
    std::cout << "second: "; second.print();
    std::cout << '\n';

    // VERIFY
    stack<int> firstCheck;
    firstCheck.push(123);
    stack<int> secondCheck;
    secondCheck.push(3); secondCheck.push(2); secondCheck.push(1);
    assert(second == firstCheck);
    assert(first  == secondCheck);
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<char> first;
    stack<char> second;
    second.push('d'); second.push('d'); second.push('t');

    // TEST
    first.swap(second);

    // PRINT
    std::cout << "first: "; first.print();
    std::cout << "second: "; second.print();
    std::cout << '\n';

    // VERIFY
    stack<char>  firstCheck;
    stack<char> secondCheck;
    secondCheck.push('d'); secondCheck.push('d'); secondCheck.push('t');
    assert(second == firstCheck);
    assert(first  == secondCheck);
  }

  std::cout << "\nDone testing swap\n\n";

}
