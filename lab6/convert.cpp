
#include <stdexcept>
#include "convert.hpp"

double convert(double temperature, char from, char to)
{
	double result = 0;
	if (from == 'C' && to == 'K')
	{
		result = temperature + 273.15;
		if (result <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == 'K' && to == 'C')
	{
		result = temperature - 273.15;
		if (temperature <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}		
	else if (from == 'C' && to == 'F')
	{
		result = 9/5 * temperature + 32;
		if (temperature + 273.15 <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == 'F' && to == 'C')
	{
		result = 5/9 * (temperature - 32);
		if (result + 273.15 <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == 'F' && to == 'K')
	{
		result = 5/9 * (temperature - 32) + 273.15;
		if (result <= 0)
		{
			throw std::logic_error("Wrong temperature value");
		}
	}
	else if (from == 'K' && to == 'F')
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
