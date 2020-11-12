#include "ATime.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;
    
ATime::ATime() {
    m_time = 0;
};

// input arguemtns to make a type ATime: "mm/dd/yyyy,  hh:mm:ss"
ATime::ATime(string date, string time) {
    
    // creates variables for each element of time and uses a stringstream to
    // pass values into those variables
    int month, day, year, hour, minute, second;
    char slash, colon;
    stringstream date_stream;
    date_stream << date;
    date_stream >> month >> slash >> day >> slash >> year;
    stringstream time_stream;
    time_stream << time;
    time_stream >> hour >> colon >> minute >> colon >> second;
    
    struct tm input_time;
    input_time.tm_sec = second;
    input_time.tm_min = minute;
    input_time.tm_hour = hour;
    input_time.tm_mday = day;
    input_time.tm_mon = month - 1;
    input_time.tm_year = year - 1900;
    input_time.tm_isdst = -1;
        
    m_time = mktime(&input_time);
    
};

ATime::ATime(time_t t) {
    m_time = t;
};

// puts the time into a readable format and not an int
string ATime::getSVal() const {
    stringstream ss;
    ss << put_time(localtime(&m_time), "%m/%d/%Y %H:%M:%S");
    return ss.str();
};

bool ATime::isValid() const {
    return (m_time > 0);
};
    
bool ATime::ATime::operator<(const ATime & a) const {
    return (m_time < a.m_time);
};
    
bool ATime::ATime::operator==(const ATime & a) const {
    return (m_time == a.m_time);
};
    
bool ATime::operator>(const ATime & a) const {
    return (m_time > a.m_time);
};
    
bool ATime::operator!=(const ATime & a) const {
    return (m_time == a.m_time);
};
    
ATime ATime::operator+(const int a)const {
    return ATime(m_time + a);
};
    
ATime ATime::operator++() { // preinc add one second
    m_time++;
    return *this;
};

ATime ATime::operator++(int) { // postinc add one second
    m_time++;
    return *this;
};

ATime& ATime::operator+=(int a) {
    m_time = m_time + a;
    return *this;
};

int ATime::operator-(const ATime& a) const {
    return static_cast<int> (m_time - a.m_time);
};

int ATime::operator-(const int a) const {
    return static_cast<int> (m_time - a);
};

ostream& operator<<(ostream& output, const ATime at) {
    output << put_time(localtime(&at.m_time), "%m/%d/%Y %H:%M:%S");
    return output;
};
    
ATime operator+(int a, const ATime& b) {
    return ATime(a + b.m_time);
};
