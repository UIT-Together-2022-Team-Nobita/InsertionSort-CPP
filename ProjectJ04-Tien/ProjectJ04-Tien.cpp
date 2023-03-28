#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool Input(int[][1000], int&, int&, string);
void InsertionSort(int[][1000], int, int);
bool Output(int[][1000], int, int, string);

int main()
{
	static int mat[1000][1000];
	int m, n;
	cout << "Project J04" << endl;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intmatrixdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Input(mat, m, n, filenameinp) == true)
		{
			InsertionSort(mat, m, n);
			string filenameout = filename;
			filenameout += ".outp";
			Output(mat, m, n, filenameout);
			cout << "\nImport	" << filenameinp << "	successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else
			cout << "\nCan't open the file" << filename << endl;
	}
	cout << endl;
	return 1206;
}

bool Input(int mat[][1000], int& m, int& n, string filename)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	fi >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> mat[i][j];
	return true;
}
void InsertionSort(int a[][1000], int m, int n)
{
	for (int k = 1; k < m * n; k++)
	{
		int vt;
		int x = a[k / n][k % n];
		for (vt = k - 1; vt >= 0 && a[vt / n][vt % n] > x; vt--)
			a[(vt + 1) / n][(vt + 1) % n] = a[vt / n][vt % n];
		a[(vt + 1) / n][(vt + 1) % n] = x;
	}
}
bool Output(int mat[][1000], int m, int n, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << m << setw(5) << n << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << setw(5) << mat[i][j];
		fo << endl;
	}
	return true;
}