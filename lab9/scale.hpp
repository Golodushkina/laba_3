
#include <iostream>

#ifndef __SCALE_HPP__
#define __SCALE_HPP__

enum class Scale
{
    Fahrenheit,
    Celsius,
    Kelvin
};

std::ostream& operator<<(std::ostream& out, const Scale& s);
std::istream& operator>>(std::istream& in, Scale& s);

#endif // __SCALE_HPP__
