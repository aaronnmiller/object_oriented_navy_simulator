// ATime keeps track of the time during the simulation. This is stored in seconds in m_time.

#ifndef ATIME_H
#define ATIME_H

#include <iostream>
#include <ctime>

class ATime {
    friend std::ostream& operator<<(std::ostream& os, ATime at);
    friend ATime operator+(int, const ATime&);
public:
    ATime();
    ATime(std::string,std::string);  // arugments: "mm/dd/yyyy,  hh:mm:ss"
    ATime(time_t t);
    std::string getSVal() const;

    bool isValid() const;
    bool operator<(const ATime &) const;
    bool operator>(const ATime &) const;
    bool operator==(const ATime &) const;
    bool operator!=(const ATime &) const;
    ATime operator+(const int)const;
    ATime operator++();            // preinc add one second
    ATime operator++(int);            // postinc add one second
    ATime& operator+=(int);
    int operator-(const ATime&) const;
    int operator-(const int) const;
private:
    // stored in seconds since Jan 1, 1970
    time_t m_time;
};

#endif
