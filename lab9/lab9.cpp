#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <ios>
#include "convert.hpp"
#include "scale.hpp"
#include "temperature.hpp"

using namespace std;

Temperature maximum_temperature(vector<Temperature> v)
{
    Temperature m = Temperature(0, Scale::Kelvin);

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > m)
        {
            m = v[i];
        }
    }
    return m;
}

Temperature average_temperature(vector<Temperature> v)
{
    Temperature avg = Temperature(0, Scale::Kelvin);

    for (int i = 0; i < v.size(); i++)
    {
        avg += v[i];
    }

    avg /= v.size();

    return avg;
}

int main()
{
	vector <Temperature> Tcel,Tkel,Tfar;
	Temperature maximum = Temperature(0, Scale::Kelvin),
                average = Temperature(0, Scale::Kelvin);
    int n = 0;

	while (cin)
	{
		Temperature cel = Temperature(0, Scale::Celsius),
                    kel = Temperature(0, Scale::Kelvin),
                    far = Temperature(0, Scale::Fahrenheit),
                    input = Temperature();

		cout << "Enter the temperature: ";
		cin >> input;

		if (!cin)
			break;

        if (input > maximum)
        {
            maximum = input;
        }
        average += input;
        n++;

		if (input.scale == Scale::Celsius)
		{
			cel.value = input.value;

			try
			{
				kel = convert( cel, Scale::Celsius, Scale::Kelvin);
				far = convert( cel, Scale::Celsius, Scale::Fahrenheit);
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
		else if (input.scale == Scale::Kelvin)
		{
			kel.value = input.value;

			try
			{
				cel = convert( kel, Scale::Kelvin, Scale::Celsius);
				far = convert( kel, Scale::Kelvin, Scale::Fahrenheit);
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
		else if (input.scale == Scale::Fahrenheit)
		{
			far.value = input.value;

			try
			{
				cel = convert( far, Scale::Fahrenheit, Scale::Celsius);
				kel = convert( far, Scale::Fahrenheit, Scale::Kelvin);
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

    average /= n;

	cout << "Maximum: " << maximum << endl;
	cout << "Average: " << average << endl;

	cout << "Maximum from function: " << maximum_temperature(Tkel) << endl;
	cout << "Average from function: " << average_temperature(Tkel) << endl;

	ofstream out("temperatures.txt", ios_base::trunc);

	for (int i = 0; i < Tcel.size(); ++i)
	{
		out << Tcel[i] << "\t";
		out << Tkel[i] << "\t";
		out << Tfar[i] << "\t" << endl;
	}

	out.close();
}
