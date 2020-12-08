// string.cpp

#include "string.hpp"

// HELPER
//----------------------------

void String::resetCapacity(int size){ //Resets capacity to be size

   // save contenets to tmp
   char *tmp = new char[size + 1];
   int i = 0;
   while (str[i] != '\0'){
      tmp[i] = str[i];
      ++i;
   }
   tmp[i] = '\0';

   // delete str
   delete[] str;

   // reset size and make a new array
   stringSize = size + 1;
   str = new char[stringSize];
  
   i = 0;
   while (tmp[i] != '\0'){
      str[i] = tmp[i];
      ++i;
   }

   // insert null char at final position
   str[i] = '\0';
}

// CONSTRUCTORS
//======================================================================

// PRIVATE CONSTRUCTORS
//----------------------------

String::String(int size){ //String(10) - size of 10.

   stringSize = size;
   str = new char[stringSize];

   str[0] = '\0';
}

String::String(int size, const char cArray[]){ //String(10, "abc") - Size 10 with "abc"

   stringSize = size;
   str = new char[stringSize];

   int i = 0;
   while (cArray[i] != '\0' && i < stringSize - 1){
      str[i] = cArray[i];
      ++i;
   }

   str[i] = '\0';
}

// PUBLIC CONSTRUCTORS
//----------------------------

String::String(){ //Empty string

   stringSize = 1;
   str = new char[stringSize];

   str[0] = '\0';
} 

String::String(char c){ //String('x')

   stringSize = 2;
   str = new char[stringSize];

   str[0] = c;
   str[1] = '\0';
}

String::String(const char cArray[]){ //String("abc")

   // get length of cArray
   int i = 0;
   while (cArray[i] != '\0'){
      ++i;
   }

   stringSize = i + 1;
   str = new char[stringSize];
  
   // re-use i
   i = 0;
   while (cArray[i] != '\0'){
      str[i] = cArray[i];
      ++i;
   }

   str[i] = '\0';
}

String::String(const String& newString){ //Copy Constructor

   stringSize = newString.stringSize;
   str = new char[stringSize];

   int i = 0;
   while (newString.str[i] != '\0'){
      str[i] = newString.str[i];
      ++i;
   }

   str[i] = '\0';
}

// METHODS
//======================================================================

String::~String(){ //Destructor
   delete[] str;
}

void String::swap(String& swapString){ //Constant time swap
   
   String tmp = swapString;
   swapString = *this;
   *this = tmp;
}

String& String::operator=(String rhs){ //Assignment copy

   delete[] str;
   stringSize = rhs.stringSize;
   str = new char[stringSize];

   int i = 0;
   while (i < stringSize - 1){
      str[i] = rhs.str[i];
      ++i;
   }

   str[i] = '\0';

   return *this;
}

char& String::operator[](int i){ //Accessor/Modifier
   return str[i];
}

char String::operator[](int i) const{ //Accessor
   return str[i];
}

int String::capacity() const{ ////Max chars that can be stored (not including null)
   return stringSize - 1;
}

int String::length() const{ //Actual number of chars in String

   int i = 0;
   while (str[i] != '\0'){
      ++i;
   }

   return i;
}

String String::operator+(const String& rhs) const{ //Concatination

   String result(rhs.length() + this->length() + 1);

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

String& String::operator+=(const String& rhs){
  *this = *this + rhs;
  return *this;
}

bool String::operator==(const String& rhs) const{

   int thisLength = this->length();

   // check lengths first
   if (thisLength != rhs.length())
      return false;
  
   int i = 0;
   while (i < thisLength){

      if (str[i] != rhs.str[i]){
         return false;
      }
    
      ++i;
   }

   return true;
}

bool String::operator<(const String& rhs) const{

   int rhsLength = rhs.length();
   int lhsLength = this->length();

   // move past all chars that are the same
   int i = 0;
   while ((str[i] == rhs.str[i]) && (i < rhsLength) && (i < lhsLength)){
      ++i;
   }

   return str[i] < rhs.str[i];
}

String String::substr(int start, int end) const{ //The sub-string from staring position to ending position

   String subString(end - start + 2); // need '+ 2' since its inclusive and null char

   int i = start;
   while (i < end + 1 && str[i] != '\0'){
      subString[i - start] = str[i];
      ++i;
   }

   subString.str[i - start] = '\0';

   return subString;
}

int String::findch(int pos, char ch) const{ //Find location of charater starting at a position

   int thisLength = this->length();
   int i = pos;
   while (i < thisLength){
      if (str[i] == ch){
         return i;
      }
      ++i;
   }

   return -1;
}

int String::findstr(int pos, const String& subString) const{ //Find location of str starting at a position

   int thisLength = this->length();
   int len =  subString.length();
   int i = pos;
   while ((i + len - 1) < thisLength){
      if (this->substr(i, i + len - 1) == subString){
         return i;
      } 
      ++i;
   }

   return -1;
}

// MILESTONE 3
std::vector<String> String::split(char splitChar) const{

   std::vector<String> result;

   int thisLength = this->length();
   for (int i = 0; i <= thisLength; ++i){ // need <= incase the splitChar is the final char
    
      String tmp;
      
      // keep adding to tmp until splitChar reached
      while (str[i] != splitChar && i < thisLength){
         tmp += str[i];
         ++i;
      }

      result.push_back(tmp);
   }

   return result;
}

int String::toInt() const{
  
    int thisLength = this->length();
    int num = 0;
    for (int i = 0; i < thisLength; ++i) {
        num *= 10;
        num += str[i] - 48;
    }
   
    return num;
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
   str = String(); // reset string
   do{
      str += inChar;

      inChar = input.get();
   }while (inChar != ' ' && inChar != '\n' && !input.eof());
 
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
