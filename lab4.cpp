#include <iostream>
#include <vector>

using namespace std;

enum class Error {
	NoError,
	WrongTemperature,
	WrongScale
};

Error last_error = Error::NoError;

Error get_last_error()
{
	return last_error;
}

double convert(double temperature, char from, char to)
{
	double result = 0;
	if (from == 'C' && to == 'K')
	{
		result = temperature + 273.15;
		if (result <= 0)
		{
			last_error = Error::WrongTemperature;
		}
		else
		{
			last_error = Error::NoError;
		}
	}
	else if (from == 'K' && to == 'C')
	{
		result = temperature - 273.15;
		if (temperature <= 0)
		{
			last_error = Error::WrongTemperature;
		}
		else
		{
			last_error = Error::NoError;
		}
	}		
	else if (from == 'C' && to == 'F')
	{
		result = 9/5 * temperature + 32;
		if (temperature + 273.15 <= 0)
		{
			last_error = Error::WrongTemperature;
		}
		else
		{
			last_error = Error::NoError;
		}
	}
	else if (from == 'F' && to == 'C')
	{
		result = 5/9 * (temperature - 32);
		if (result + 273.15 <= 0)
		{
			last_error = Error::WrongTemperature;
		}
		else
		{
			last_error = Error::NoError;
		}
	}
	else if (from == 'F' && to == 'K')
	{
		result = 5/9 * (temperature - 32) + 273.15;
		if (result <= 0)
		{
			last_error = Error::WrongTemperature;
		}
		else
		{
			last_error = Error::NoError;
		}
	}
	else if (from == 'K' && to == 'F')
	{
		result = 9/5 * (temperature - 273.15) + 32;
		if (temperature <= 0)
		{
			last_error = Error::WrongTemperature;
		}
		else
		{
			last_error = Error::NoError;
		}
	}
	else
	{
		last_error = Error::WrongScale;
	}
	return result;
}

int main()
{
	vector <double> Tcel,Tkel,Tfar;
	while (cin)
	{
		double n,cel,kel,far;
		char shk;
		cout << "Enter the temperature: ";
		cin >> n >> shk;

		if (!cin)
			break;

		if (shk=='C')
		{
			cel = n;
			kel = convert( n, 'C', 'K');
			if (get_last_error() != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			far = convert( n, 'C', 'F');
			if (get_last_error() != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			Tcel.push_back(cel);
			Tfar.push_back(far);
			Tkel.push_back(kel);
		}
		else if (shk=='K')
		{
			kel = n;
			cel = convert( n, 'K', 'C');
			if (get_last_error() != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			far = convert( n, 'K', 'F');
			if (get_last_error() != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			Tcel.push_back(cel);
			Tfar.push_back(far);
			Tkel.push_back(kel);
		}
		else if (shk=='F')
		{
			far = n;
			cel = convert( n, 'F', 'C');
			if (get_last_error() != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			kel = convert( n, 'F', 'K');
			if (get_last_error() != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			Tcel.push_back(cel);
			Tfar.push_back(far);
			Tkel.push_back(kel);
		}
	}

	cout << Tcel.size() << endl;

	for (int i = 0; i < Tcel.size(); ++i)
	{
		cout << Tcel[i] << "\t";
		cout << Tkel[i] << "\t";
		cout << Tfar[i] << "\t" << endl;
	}
}