
#include <iostream>
#include "scale.hpp"

#ifndef __TEMPERATURE_HPP__
#define __TEMPERATURE_HPP__

struct Temperature
{
    Temperature();
    Temperature(double value, Scale scale);
    double value;
    Scale scale;
    Temperature& operator=(const Temperature& other);
    bool operator==(const Temperature &other) const;
    bool operator!=(const Temperature &other) const;
    bool operator< (const Temperature &other) const;
    bool operator> (const Temperature &other) const;
    bool operator<=(const Temperature &other) const;
    bool operator>=(const Temperature &other) const;
    Temperature& operator+=(const Temperature& other);
    Temperature& operator/=(int num);
    const Temperature& operator+(const Temperature& other) const;
    const Temperature& operator/(int num) const;
};

std::ostream& operator<<(std::ostream& out, const Temperature& t);
std::istream& operator>>(std::istream& in, Temperature& t);

#endif // __TEMPERATURE_HPP__
