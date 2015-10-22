
#include <ios>
#include "scale.hpp"

std::ostream& operator<<(std::ostream& out, const Scale& s)
{
    switch (s)
    {
    case Scale::Fahrenheit:
        out << 'F';
        break;
    case Scale::Celsius:
        out << 'C';
        break;
    case Scale::Kelvin:
        out << 'K';
        break;
    }
    return out;
}

std::istream& operator>>(std::istream& in, Scale& s)
{
    char value;
    in >> value;
    switch (value)
    {
    case 'K':
        s = Scale::Kelvin;
        break;
    case 'C':
        s = Scale::Celsius;
        break;
    case 'F':
        s = Scale::Fahrenheit;
        break;
    default:
        in.setstate(std::ios_base::failbit);
    }
    return in;
}
