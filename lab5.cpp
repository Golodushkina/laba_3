#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

double convert(double temperature, char from, char to)
{
	double result = 0;
	if (from == 'C' && to == 'K')
	{
		result = temperature + 273.15;
		if (result <= 0)
		{
			throw logic_error("Wrong temperature value");
		}
	}
	else if (from == 'K' && to == 'C')
	{
		result = temperature - 273.15;
		if (temperature <= 0)
		{
			throw logic_error("Wrong temperature value");
		}
	}		
	else if (from == 'C' && to == 'F')
	{
		result = 9/5 * temperature + 32;
		if (temperature + 273.15 <= 0)
		{
			throw logic_error("Wrong temperature value");
		}
	}
	else if (from == 'F' && to == 'C')
	{
		result = 5/9 * (temperature - 32);
		if (result + 273.15 <= 0)
		{
			throw logic_error("Wrong temperature value");
		}
	}
	else if (from == 'F' && to == 'K')
	{
		result = 5/9 * (temperature - 32) + 273.15;
		if (result <= 0)
		{
			throw logic_error("Wrong temperature value");
		}
	}
	else if (from == 'K' && to == 'F')
	{
		result = 9/5 * (temperature - 273.15) + 32;
		if (temperature <= 0)
		{
			throw logic_error("Wrong temperature value");
		}
	}
	else
	{
		throw invalid_argument("Wrong scale value");
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
			kel = far = 0;
			
			try
			{
				kel = convert( n, 'C', 'K');
				far = convert( n, 'C', 'F');
			}
			catch (const invalid_argument& e)
			{
				cout << e.what() << endl;
			}
			catch (const logic_error& e)
			{
				cout << e.what() << endl;
			}
			catch (const exception& e)
			{
				cout << e.what() << endl; 
			}
			
			Tcel.push_back(cel);
			Tfar.push_back(far);
			Tkel.push_back(kel);
		}
		else if (shk=='K')
		{
			kel = n;
			cel = far = 0;
			
			try
			{
				cel = convert( n, 'K', 'C');
				far = convert( n, 'K', 'F');
			}
			catch (const invalid_argument& e)
			{
				cout << e.what() << endl;
			}
			catch (const logic_error& e)
			{
				cout << e.what() << endl;
			}
			catch (const exception& e)
			{
				cout << e.what() << endl; 
			}
			
			Tcel.push_back(cel);
			Tfar.push_back(far);
			Tkel.push_back(kel);
		}
		else if (shk=='F')
		{
			far = n;
			cel = kel = 0;
			
			try
			{
				cel = convert( n, 'F', 'C');
				kel = convert( n, 'F', 'K');
			}
			catch (const invalid_argument& e)
			{
				cout << e.what() << endl;
			}
			catch (const logic_error& e)
			{
				cout << e.what() << endl;
			}
			catch (const exception& e)
			{
				cout << e.what() << endl; 
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