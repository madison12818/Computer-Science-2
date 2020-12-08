//string.cpp

#include "string.hpp"

// CONSTRUCTORS
//======================================================================

String::String(){ //Empty string
   str[0] = '\0';
}

String::String(char c){ //String('x')
  str[0] = c;
  str[1] = '\0';
}

String::String (const char cArray[]){ //String("abcd")
   int i = 0;
   while (cArray[i] != '\0'){
      str[i] = cArray[i];
      ++i;
   }
   str[i] = '\0';
}

// METHODS
//======================================================================

char& String::operator[](int i){ //Accessor/Modifier
   return str[i];
}

char String::operator[](int i) const{ //Accessor
   return str[i];
}

int String::capacity() const{ //Max chars that can be stored (not including null terminator)

   // one char spot is taken up by '\0'
   return STRING_SIZE - 1;
}

int String::length() const{ //Number of char in string
   int i = 0;
   while (str[i] != '\0'){
      ++i;
   }
   return i;
}

String String::operator+(const String& rhs) const{ //Concatenation

   String result;

   // copy first string over
   int i = 0;
   while (str[i] != '\0'){
      result.str[i] = str[i];
      ++i;
   }
  
   // add rhs string to the end
   int j = 0;
   while (rhs.str[j] != '\0'){
      result.str[i] = rhs.str[j];
      ++j; 
      ++i;
   }
  
   result.str[i] = '\0';

   return result;
}

bool String::operator==(const String& rhs) const{

   int i = 0;
   while ((str[i] != '\0') || (rhs.str[i] != '\0')){
      if (str[i] != rhs.str[i]){
         return false;
      }
      
      ++i;
   }

   return true;
}

bool String::operator<(const String& rhs) const{

   // move past all chars that are the same
   int i = 0;
   while (str[i] == rhs.str[i]){
      ++i;
   }

   return str[i] < rhs.str[i];
}

String String::substr(int start, int end) const{ //Inclusive

   String subString;
   int i = start;
   while (i < end + 1 && str[i] != '\0'){
      subString[i - start] = str[i];
      ++i;
   }
  
   subString[i - start] = '\0';

   return subString;
}

int String::findch(int pos, char ch) const{ //Return position of ch at or after pos

   int i = pos;
   while (str[i] != '\0'){
      if (str[i] == ch){
         return i;
      }
      ++i;
   }

   return -1;
}

int String::findstr(int pos, const String& subString) const{ //Same as findch except for a string

   int len =  subString.length();
   int i = pos;
   while (str[i + len - 1] != '\0'){
      if (this->substr(i, i + len - 1) == subString){
         return i;
      }
      ++i;
   }

   return -1;
}

// FRIENDS
//======================================================================

std::istream& operator>>(std::istream& input, String& str){

   // first move input past any spaces and end lines until first char is reached
   char inChar;
   do{
      inChar = input.get();
   }while (inChar == ' ' || inChar == '\n');

   // now begin to fill the string until a space or endline or end of file
   int i = 0;
   do{
      str[i] = inChar;
      ++i;

      inChar = input.get();
    }while (inChar != ' ' && inChar != '\n' && !input.eof());

   str[i] = '\0';
 
   return input;
}

std::ostream& operator<<(std::ostream& output, const String& str){

   int len = str.length();
   for (int i = 0; i < len; ++i){
      output << str[i];
   }

   return output;
}

// NON-MEMBER OPERATORS
//======================================================================

void operator+=(String& lhs, const String& rhs){
   lhs = lhs + rhs;
}

String operator+(const char cArray[], const String& str){
   String tmp(cArray);
   return tmp + str;
}

String operator+(char c, const String& str){
   String tmp(c);
   return tmp + str;
}

bool operator==(const char cArray[], const String& str){
   String tmp(cArray);
   return tmp == str;
}

bool operator==(char c, const String& str){
   String tmp(c);
   return tmp == str;
}

bool operator<(const char cArray[], const String& str){
   String tmp(cArray);
   return tmp < str;
}

bool operator<(char c, const String& str){
   String tmp(c);
   return tmp < str;
}

bool operator<=(const String& lhs, const String& rhs){
   return lhs < rhs || lhs == rhs;
}

bool operator!=(const String& lhs, const String& rhs){
   return !(lhs == rhs);
}

bool operator>=(const String& lhs, const String& rhs){
   return rhs < lhs || lhs == rhs;
}

bool operator>(const String& lhs, const String& rhs){
   return rhs < lhs;
}
