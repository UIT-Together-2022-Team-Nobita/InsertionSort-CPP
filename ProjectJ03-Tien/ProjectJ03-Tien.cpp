#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct fraction
{
	int numerator;
	int denominator;
};
typedef struct fraction FRACTION;

bool Input(FRACTION[], int&, string);
int FCompare(FRACTION, FRACTION);
void InsertionSort(FRACTION[], int);
bool Output(FRACTION[], int, string);

int main()
{
	static FRACTION FA[1000000];
	int n;
	cout << "Project J03" << endl;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "fractiondata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Input(FA, n, filenameinp) == true)
		{
			InsertionSort(FA, n);
			string filenameout = filename;
			filenameout += ".outp";
			Output(FA, n, filenameout);
			cout << "\nImport	" << filenameinp << "	successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else
			cout << "\nCan't open the file" << filename << endl;
	}
	cout << endl;
	return 1206;
}

bool Input(FRACTION FA[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> FA[i].numerator >> FA[i].denominator;
	return true;
}
int FCompare(FRACTION ft1, FRACTION ft2)
{
	double q1 = (double)ft1.numerator / ft1.denominator;
	double q2 = (double)ft2.numerator / ft2.denominator;
	if (q1 > q2)
		return 1;
	if (q1 < q2)
		return -1;
	return 0;
}
void InsertionSort(FRACTION FA[], int n)
{
	for (int step = 1; step <= n - 1; step++)
	{
		FRACTION x = FA[step];
		int vt = 0;
		for (vt = step - 1; vt >= 0 && FCompare(FA[vt], x) == 1; vt--)
			FA[vt + 1] = FA[vt];
		FA[vt + 1] = x;
	}
}
bool Output(FRACTION FA[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << FA[i].numerator << setw(5) << FA[i].denominator << endl;
	return true;
}