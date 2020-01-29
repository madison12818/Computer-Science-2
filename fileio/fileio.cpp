//fileio.cpp
//
//Madison Docery
//
//Lab4

#include<iostream>
#include<fstream>

void fileioRead();
void fileioAdd();

int main(){

   fileioRead();
   fileioAdd();

}

void fileioRead(){
   std::ifstream file("fileio-text.txt");
   char input;
   if(!file.is_open()){
      std::cout << "Unable to open file.\n";
   }

   else{
      file.get(input);
      while(!file.eof() && input != ' '){
         std::cout << input;
         file.get(input);
      }

   }
   std::cout << '\n';
      file.close();
}

void fileioAdd(){

   std::ifstream file("fileio-data-1.txt");
   char numInput;
   int firstNum;
   int secondNum;

   if(!file.is_open()){
      std::cout << "Unable to open file.\n";
   }

   else{
      if(!file.eof()){
         file >> firstNum;
      }
      if(!file.eof()){
         file.get(numInput);
      }
      if(!file.eof()){
         file >> secondNum;
      }
      if(!file.eof()){
         file.get(numInput);
      }

      std::cout << firstNum << "+" << secondNum << "=" << firstNum + secondNum << "\n";
     
   }
   std::cout << '\n';
   file.close();
}
