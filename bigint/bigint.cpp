//bigint.cpp
//
//Madison Dockery
//
//Project 1


#include "bigint.hpp"

bigint::bigint(){

   for (int i = 0; i < CAPACITY; ++i){
      digit[i] = 0;
   }

}

bigint::bigint(int num){

   // initially set digit to zero
   for (int i = 0; i < CAPACITY; ++i){
      digit[i] = 0;
   }

   int i = 0;
   while (num != 0){

      int tmp = num % 10; // get ones digit
      digit[i] = tmp;
      num = num / 10; // make tens to ones, hundreds to tens, etc.
      ++i;
   }
}

bigint::bigint(const char num[]){

   // initially set digit to zero
   for (int i = 0; i < CAPACITY; ++i){
      digit[i] = 0;
   }

   // find length of char array
   int length = 0;
   while (num[length] != '\0'){
      ++length;
   }

   // work backwards through array
   int j = 0;
   for (int i = length - 1; i >= 0; --i){
      digit[i] = num[j] - 48;
      ++j;
   }
}

void bigint::debugPrint(std::ostream& output) const{

   for (int i = CAPACITY - 1; i >= 0; --i){
      output << digit[i] << "|";
   }
  
   output << "\n";
}

std::ostream& operator<<(std::ostream& output, const bigint& num){

   // move starting index past all leading zeros
   int startIndex = CAPACITY - 1;
   while (num.digit[startIndex] == 0 && startIndex != 0){
      --startIndex;
   }

   int outputCount = 1;
   for (int i = startIndex; i >= 0; --i){

      if (outputCount % 80 != 0){ // only output 80 digits in a row
         output << num.digit[i];
      }
      
      else{
         output << num.digit[i] << "\n";
      }

      ++outputCount;
   }

   return output;
}

bool operator==(const bigint& lhs, const bigint& rhs){

   for (int i = 0; i < CAPACITY; ++i){
      if (lhs.digit[i] != rhs.digit[i]){
         return false;
      }
   }

   return true;
}

// MILESTONE 2
//------------------------------------------------------------------------

std::istream& operator>>(std::istream& input, bigint& num){

   // put input into char array
   char numChar[CAPACITY];
   int i = 0;
   char inputChar;

   do{

      // get next char in input
      inputChar = input.get();
      
      if (inputChar <= '9' && inputChar >= '0'){
         numChar[i] = inputChar;
	  ++i;
      }

   }while(inputChar != ';' && !input.eof());

   // put null terminating char after last digit added
   numChar[i] = '\0';

   // construct and assign
   bigint tmp(numChar);
   num = tmp;

   return input;
}

bigint bigint::operator+(const bigint& rhs) const{

   bigint newNum;
   int digitSum;
   bool carryOver = false;
   for (int i = 0; i < CAPACITY; ++i){

      // reset
      digitSum = 0;

      digitSum = digit[i] + rhs.digit[i];

      if (carryOver){
         ++digitSum;
      }
      
      // check carry over
      if (digitSum >= 10){
         carryOver = true;
      }
      else{
	 carryOver = false;
      }

      // get ones digit if over ten
      digitSum = digitSum % 10;

      newNum.digit[i] = digitSum;
   }

   return newNum;
}

int bigint::operator[](const int& num) const{

   return digit[num];
}

// MILESTONE 3
//------------------------------------------------------------------------

bigint bigint::times10(const int& num) const {
   bigint result;

   // copy digits from old bigint to new one starting from num
   for (int i = num; i < CAPACITY; ++i)
      result.digit[i] = digit[i - num];

   return result;
}

bigint bigint::timesDigit(const int& num) const {

   bigint result;
  
   for (int i = 0; i < CAPACITY; ++i) {

         bigint digitResult(digit[i] * num);
         digitResult = digitResult.times10(i);

         result = result + digitResult;
   }

   return result;
}

bigint bigint::operator*(const bigint& rhs) const {

   bigint result;
  
   for (int i = 0; i < CAPACITY; ++i) {

      bigint temp(rhs.timesDigit(digit[i]));

      result = result + temp.times10(i); 
   }

   return result;
}

// FACTORIAL STARTED
//------------------------------------------------------------------------

bigint factorial(const bigint& num) {

   // check if 0!
   if (num == 0) {
      return bigint(1);
   }
  
   bigint result(1);
   bigint i(0);
   while (!(i == num)) {

      i = i + 1;
      result = result * i;
   }

   return result;
}
