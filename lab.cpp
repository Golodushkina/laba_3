#include <iostream>
#include <vector>

using namespace std;

double convert(double temperature, char from, char to)
{ 
	if (from =='C' && to =='K')
		return temperature + 273.15;
	else if (from == 'K' && to == 'C')
		return temperature - 273.15;
	
	else if (from == 'C' && to == 'F')
		return 9/5 * temperature + 32;
	else if (from == 'F' && to == 'C')
		return 5/9 * (temperature - 32);
	
	else if (from == 'F' && to == 'K')
		return 5/9 * (temperature - 32) + 273.15;
	else if (from == 'K' && to == 'F')
		return 9/5 * (temperature - 273.15) + 32;
	else
		cout << "Error" << endl;
	return 0;
}

int main()
{
	vector <double> Tcel,Tkel,Tfar;
	while (cin)
	{
		double n,cel,kel,far;
		char shk;
		cout << "Enter the tempereture: ";
		cin >> n >> shk;

		if (!cin)
			break;

		if (shk=='C')
		{
			cel = n;
			kel = convert( n, 'C', 'K');
			far = convert( n, 'C', 'F');
			if (kel <= 0)
			{
				cout << "Error main";
			}
			Tcel.push_back(cel);
			Tfar.push_back(far);
			Tkel.push_back(kel);
		}
		else if (shk=='K')
		{
			kel = n;
			cel = convert( n, 'K', 'C'); 
			far = convert( n, 'K', 'F');
			if (kel <= 0)
			{
				cout << "Error main";
			}
			Tcel.push_back(cel);
			Tfar.push_back(far);
			Tkel.push_back(kel);
		}
		else if (shk=='F')
		{
			far = n;
			cel = convert( n, 'F', 'C');
			kel = convert( n, 'F', 'K');
			if (kel <= 0)
			{
				cout << "Error main";
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