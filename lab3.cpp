#include <iostream>
#include <vector>

using namespace std;

enum class Error {
	NoError,
	WrongTemperature,
	WrongScale
};

Error convert(double temperature, char from, char to, double& result)
{
	if (from == 'C' && to == 'K')
	{
		result = temperature + 273.15;
		if (result <= 0)
		{
			return Error::WrongTemperature;
		}
		return Error::NoError;
	}
	else if (from == 'K' && to == 'C')
	{
		result = temperature - 273.15;
		if (temperature <= 0)
		{
			return Error::WrongTemperature;
		}
		return Error::NoError;
	}		
	else if (from == 'C' && to == 'F')
	{
		result = 9/5 * temperature + 32;
		if (temperature + 273.15 <= 0)
		{
			return Error::WrongTemperature;
		}
		return Error::NoError;
	}
	else if (from == 'F' && to == 'C')
	{
		result = 5/9 * (temperature - 32);
		if (result + 273.15 <= 0)
		{
			return Error::WrongTemperature;
		}
		return Error::NoError;
	}
	else if (from == 'F' && to == 'K')
	{
		result = 5/9 * (temperature - 32) + 273.15;
		if (result <= 0)
		{
			return Error::WrongTemperature;
		}
		return Error::NoError;
	}
	else if (from == 'K' && to == 'F')
	{
		result = 9/5 * (temperature - 273.15) + 32;
		if (temperature <= 0)
		{
			return Error::WrongTemperature;
		}
		return Error::NoError;
	}
	else
	{
		result = 0;
		return Error::WrongScale;
	}
}

int main()
{
	vector <double> Tcel,Tkel,Tfar;
	while (cin)
	{
		double n,cel,kel,far;
		char shk;
		Error error_code;
		cout << "Enter the temperature: ";
		cin >> n >> shk;

		if (!cin)
			break;

		if (shk=='C')
		{
			cel = n;
			error_code = convert( n, 'C', 'K', kel);
			if (error_code != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			error_code = convert( n, 'C', 'F', far);
			if (error_code != Error::NoError)
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
			error_code = convert( n, 'K', 'C', cel);
			if (error_code != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			error_code = convert( n, 'K', 'F', far);
			if (error_code != Error::NoError)
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
			error_code = convert( n, 'F', 'C', cel);
			if (error_code != Error::NoError)
			{
				cout << "Error!" << endl;
			}
			error_code = convert( n, 'F', 'K', kel);
			if (error_code != Error::NoError)
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