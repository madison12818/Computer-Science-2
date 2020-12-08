#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        3/15/2019
// Author:      Madison Dockery
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
            Date() {};
            Date(String d, String m, int y)
	      : day(d), month(m), year(y) {}

    // Accessors
    String  getDay()   const { return day;   }
    String  getMonth() const { return month; }
    int     getYear()  const { return year;  }
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() {};
            Time(int h, int m, int s)
	      : hour(h), minute(m), second(s) {}

    // Accessors
    int     getHour()   const { return hour;   }
    int     getMinute() const { return minute; }
    int     getSecond() const { return second; }
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
            LogEntry() {};
            LogEntry(String);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

  // Accessors
    String  getHost()    const { return host; }
    Date    getDate()    const { return date; }
    Time    getTime()    const { return time; }
    String  getRequest() const { return request; }
    String  getStatus()  const { return status; }
    int     getBytes()   const { return number_of_bytes; }
private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif

