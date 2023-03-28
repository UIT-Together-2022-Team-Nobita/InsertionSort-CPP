#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool Input(float[], int&, string);
void InsertionSort(float[], int);
bool Output(float[], int, string);

int main()
{
	static float a[1000000];
	int n;
	cout << "Project J02" << endl;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "floatdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Input(a, n, filenameinp) == true)
		{
			InsertionSort(a, n);
			string filenameout = filename;
			filenameout += ".outp";
			Output(a, n, filenameout);
			cout << "\nImport	" << filenameinp << "		successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else
			cout << "\nCan't open the file" << filename << endl;
	}
	cout << endl;
	return 1206;
}

bool Input(float a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return true;
}

void InsertionSort(float a[], int n)
{
	for (int step = 1; step <= n - 1; step++)
	{
		int x = a[step];
		int vt = 0;
		for (vt = step - 1; vt >= 0 && a[vt] > x; vt--)
			a[vt + 1] = a[vt];
		a[vt + 1] = x;
	}
}

bool Output(float a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i];
	return true;
}