#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

   
    void normalize();

public:
  
    Time(int h = 0, int m = 0, int s = 0);

   
    ~Time();

  
    Time operator+(const Time& other);

  
    Time operator-(const Time& other);

   
    Time operator++(int);

    
    Time operator--(int);

   
    bool operator==(const Time& other) const;

    
    bool operator!=(const Time& other) const;

  
    friend ostream& operator<<(ostream& os, const Time& t);
};

#endif // TIME_H