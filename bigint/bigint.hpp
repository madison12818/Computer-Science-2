// bigint.hpp
//
// Madison Dockery
//
// project 1 

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

const int CAPACITY = 200;

class bigint{

public:
   // constructors
   bigint();
   bigint(int);
   bigint(const char[]);
  
   // methods
   void   debugPrint (std::ostream&) const;
   bigint operator+  (const bigint&) const;
   int    operator[] (const int&)    const;
   bigint times10    (const int&)    const;
   bigint timesDigit (const int&)    const;
   bigint operator*  (const bigint&) const;
  
   // friends
   friend std::ostream& operator<< (std::ostream&, const bigint&);
   friend std::istream& operator>> (std::istream&, bigint&);
   friend bool          operator== (const bigint&, const bigint&);
   friend bigint        factorial  (const bigint&);

private:
   int digit[CAPACITY];

};

#endif // BIGINT_HPP
