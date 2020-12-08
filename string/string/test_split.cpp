//  String class test program
//
//  Name: test_split.cpp
//  Tests: split 
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
    String  str("abc ef gh");

    // TEST
    std::vector<String> result = str.split(' ');

    // PRINT
    int size = result.size();
    for (int i = 0; i < size; ++i)
      std::cout << i << ". " << result[i] << " ";
    std::cout << "\n";

    // VERIFY
    assert(result[0] == "abc");
    assert(result[1] == "ef");
    assert(result[2] == "gh");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("-a--b-");

    // TEST
    std::vector<String> result = str.split('-');

    // PRINT
    int size = result.size();
    for (int i = 0; i < size; ++i)
      std::cout << i << ". " << result[i] << " ";
    std::cout << "\n";

    // VERIFY
    assert(result[0] == "");
    assert(result[1] == "a");
    assert(result[2] == "");
    assert(result[3] == "b");
    assert(result[4] == "");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("all hands on deck");

    // TEST
    std::vector<String> result = str.split(' ');

    // PRINT
    int size = result.size();
    for (int i = 0; i < size; ++i)
      std::cout << i << ". " << result[i] << " ";
    std::cout << "\n";

    // VERIFY
    assert(result[0] == "all");
    assert(result[1] == "hands");
    assert(result[2] == "on");
    assert(result[3] == "deck");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("yallxreadyxforxthis");

    // TEST
    std::vector<String> result = str.split('x');

    // PRINT
    int size = result.size();
    for (int i = 0; i < size; ++i)
      std::cout << i << ". " << result[i] << " ";
    std::cout << "\n";

    // VERIFY
    assert(result[0] == "yall");
    assert(result[1] == "ready");
    assert(result[2] == "for");
    assert(result[3] == "this");
  }

  {
    //------------------------------------------------------
    // SETUP FIXTURE
    String  str("who?let?the?dogs?out?");

    // TEST
    std::vector<String> result = str.split('?');

    // PRINT
    int size = result.size();
    for (int i = 0; i < size; ++i)
      std::cout << i << ". " << result[i] << " ";
    std::cout << "\n";

    // VERIFY
    assert(result[0] == "who");
    assert(result[1] == "let");
    assert(result[2] == "the");
    assert(result[3] == "dogs");
    assert(result[4] == "out");
    assert(result[5] == "");
  }
  
  std::cout << "\nDone testing split\n\n";
}
