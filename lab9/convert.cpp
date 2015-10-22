
#include <stdexcept>
#include "convert.hpp"
#include "scale.hpp"
#include "temperature.hpp"

Temperature convert(Temperature temperature, Scale from, Scale to)
{
	double result;
	if (from == Scale::Celsius && to == Scale::Kelvin)
	{
		result = temperature.value + 273.15;
		if (result <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Kelvin && to == Scale::Celsius)
	{
		result = temperature.value - 273.15;
		if (temperature.value <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Celsius && to == Scale::Fahrenheit)
	{
		result = 9/5 * temperature.value + 32;
		if (temperature.value + 273.15 <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Fahrenheit && to == Scale::Celsius)
	{
		result = 5/9 * (temperature.value - 32);
		if (result + 273.15 <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Fahrenheit && to == Scale::Kelvin)
	{
		result = 5/9 * (temperature.value - 32) + 273.15;
		if (result <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Kelvin && to == Scale::Fahrenheit)
	{
		result = 9/5 * (temperature.value - 273.15) + 32;
		if (temperature.value <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else
	{
		throw std::invalid_argument("Wrong scale value");
	}
	return Temperature(result, to);
}
