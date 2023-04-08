#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool Input(int[], int&, string);
void InsertionSort(int[], int);
bool Output(int[], int, string);

int main()
{
	static int a[1000000];
	int n;
	cout << "Project J01" << endl;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
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
			cout << "\nImport	" << filenameinp << "	successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else
			cout << "\nCan't open the file" << filename << endl;
	}
	cout << endl;
	return 1206;
}

bool Input(int a[], int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	fi >> n;
	for (int i = 0; i < n; i++)
		fi >> a[i];
	return true;
}

void InsertionSort(int a[], int n)
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

bool Output(int a[], int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; i++)
		fo << setw(5) << a[i];
	return true;
}