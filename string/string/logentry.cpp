//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        3/15/2019
// Author:      Madison Dockery
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
  
   // initial split
   //     vec[0]        |1|2|3                    |4     |5   |6       |7        |8  |9
   // Ex: 131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] "GET /~darci/ HTTP/1.0" 200 5625
   std::vector<String> vec = s.split(' ');

   // check string count
   if (vec.size() != 10) { // if not proper log return blank
      host = ""; date = Date("", "", 0);
      time = Time(0, 0, 0); request = "";
      status = ""; number_of_bytes = 0;
      return;
   }

   host = vec[0]; // Ex: "131.123.47.176"

   // getting date and time
   // dateSplit
   // 0  |1  |2
   // [18/Sep/2002:12:05:25
   std::vector<String> dateSplit = vec[3].split('/'); 
   
   // timeSplit and break off year
   // 0   |1 |2 |3
   // 2002:12:05:25
   std::vector<String> timeSplit = dateSplit[2].split(':');

   // inputing and trimming extra stuff
   String day = dateSplit[0].substr(1, dateSplit[0].length() - 1); // trim off [
   String month = dateSplit[1];
   int year = timeSplit[0].toInt();
   date = Date(day, month, year);

   int hour = timeSplit[1].toInt();
   int minute = timeSplit[2].toInt();
   int second = timeSplit[3].toInt();
   time = Time(hour, minute, second);

   request = vec[5].substr(1, vec[5].length() - 1); // trim off "
   status = vec[8];
   
   // check if byte count is blank
   if (vec[9] == '-') {
      number_of_bytes = 0;
      return;
   }
   number_of_bytes = vec[9].toInt();
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
   std::vector<LogEntry> result;

   while (!in.eof()) {
      
      // inputting line into string
      String input;
      char inChar = in.get();
      for (int i = 0; inChar != '\n' && !in.eof(); ++i) {
         input += inChar;
	 inChar = in.get();
      }

      // construct log
      LogEntry tmp(input);

      // add to result
      result.push_back(tmp);
   }

   return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry>& entries) {

   int size = entries.size();
   for (int i = 0; i < size; ++i) {
      if (entries[i].getHost() != "") {// check if its blank
         out << entries[i].getHost() << '\t'
	 // outputting date
	   << entries[i].getDate().getDay() << '/'
	   << entries[i].getDate().getMonth() << '/'
	   << entries[i].getDate().getYear() << '\t'
	 // outputting time
	   << entries[i].getTime().getHour() << ':'
	   << entries[i].getTime().getMinute() << ':'
	   << entries[i].getTime().getSecond() << '\t'
	 //outputting rest of log
	   << entries[i].getRequest() << ' '
	   << entries[i].getStatus() << ' '
	   << entries[i].getBytes() << '\n';
      }
   }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& entries) {

   int size = entries.size();
   for (int i = 0; i < size; ++i){
      out << entries[i].getHost() << '\n';
   }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry>& entries) {
   
   int count = 0;
   int size = entries.size();
   for (int i = 0; i < size; ++i){
      count += entries[i].getBytes();
   }
     
   return count;
}

