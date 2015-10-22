
#include "temperature.hpp"
#include "scale.hpp"
#include "convert.hpp"

Temperature::Temperature()
{
    this->value = 0;
    this->scale = Scale::Kelvin;
}

Temperature::Temperature(double value, Scale scale)
{
    this->scale = scale;
    this->value = value;
}

std::ostream& operator<<(std::ostream& out, const Temperature& t)
{
    out << t.value << t.scale;
    return out;
}

std::istream& operator>>(std::istream& in, Temperature& t)
{
    in >> t.value >> t.scale;
    return in;
}

Temperature& Temperature::operator=(const Temperature& other)
{
    if (this != &other)
    {
        this->value = other.value;
        this->scale = other.scale;
    }
    return *this;
}

bool Temperature::operator==(const Temperature &other) const
{
    if (this->scale == other.scale)
    {
        return this->value == other.value;
    }
    else
    {
        Temperature temp = convert(other, other.scale, this->scale);
        return this->value == temp.value;
    }
}

bool Temperature::operator!=(const Temperature &other) const
{
    return !(*this == other);
}


bool Temperature::operator< (const Temperature &other) const
{
    if (this->scale == other.scale)
    {
        return this->value < other.value;
    }
    else
    {
        Temperature temp = convert(other, other.scale, this->scale);
        return this->value < temp.value;
    }
}

bool Temperature::operator>=(const Temperature &other) const
{
    return !(*this < other);
}


bool Temperature::operator> (const Temperature &other) const
{
    return !(*this < other || *this == other);
}

bool Temperature::operator<=(const Temperature &other) const
{
    return !(*this > other);
}

Temperature& Temperature::operator+=(const Temperature& other)
{
    if (this->scale == other.scale)
    {
        this->value += other.value;
    }
    else
    {
        Temperature temp = convert(other, other.scale, this->scale);
        this->value += temp.value;
    }
    return *this;
}

Temperature& Temperature::operator/=(int num)
{
    this->value /= num;
    return *this;
}

const Temperature& Temperature::operator+(const Temperature& other) const
{
    return (Temperature)(*this) += other;
}

const Temperature& Temperature::operator/(int num) const
{
    return (Temperature)(*this) /= num;
}
