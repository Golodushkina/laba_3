#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include "convert.hpp"

using namespace std;

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