
#include <stdexcept>
#include "convert.hpp"

double convert(double temperature, Scale from, Scale to)
{
	double result = 0;
	if (from == Scale::Celsius && to == Scale::Kelvin)
	{
		result = temperature + 273.15;
		if (result <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Kelvin && to == Scale::Celsius)
	{
		result = temperature - 273.15;
		if (temperature <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Celsius && to == Scale::Fahrenheit)
	{
		result = 9/5 * temperature + 32;
		if (temperature + 273.15 <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Fahrenheit && to == Scale::Celsius)
	{
		result = 5/9 * (temperature - 32);
		if (result + 273.15 <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Fahrenheit && to == Scale::Kelvin)
	{
		result = 5/9 * (temperature - 32) + 273.15;
		if (result <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == Scale::Kelvin && to == Scale::Fahrenheit)
	{
		result = 9/5 * (temperature - 273.15) + 32;
		if (temperature <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else
	{
		throw std::invalid_argument("Wrong scale value");
	}
	return result;
}
