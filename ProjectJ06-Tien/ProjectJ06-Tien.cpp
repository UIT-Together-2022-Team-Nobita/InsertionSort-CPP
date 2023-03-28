#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct node
{
	int info;
	struct node* pNext;
	struct node* pPrev;
};
typedef struct node NODE;
struct list
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void Init(LIST&);
bool IsEmpty(LIST);
NODE* GetNode(int);
void AddTail(LIST&, NODE*);
bool Inp(LIST&, string, int);
void InsertionSort(LIST&);
int NodeCount(LIST);
void Outp(LIST);
bool Outp(LIST, string);

int main()
{
	cout << "Project G6" << endl;
	LIST l;
	for (int i = 1; i <= 13; i++)
	{
		string filename = "intdata";
		if (i < 10)
			filename += '0';
		filename += to_string(i);
		string filenameinp = filename;
		filenameinp += ".inp";
		if (Inp(l, filenameinp, i) == true)
		{
			InsertionSort(l);
			string filenameout = filename;
			filenameout += ".outp";
			Outp(l, filenameout);
			cout << "\nImport	" << filenameinp << "	successfully!";
			cout << "\nExport	" << filenameout << "	successfully!" << endl;
		}
		else cout << "\nCan't open the file " << filename << "\n";
	}
	return 1206;
}

void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
bool IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return true;
	return false;
}
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}

bool Inp(LIST& l, string filename, int i)
{
	ifstream fi(filename);
	if (fi.fail() == true)
		return false;
	int n;
	int x{};
	fi >> n;
	Init(l);
	for (int i = 1; i <= n; i++)
	{
		fi >> x;
		NODE* p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
	return true;
}
void InsertionSort(LIST& l)
{
	NODE* p = l.pHead->pNext;
	l.pHead->pNext = NULL;
	while (p != NULL)
	{
		NODE* q = l.pHead;
		while (q != NULL && q->info < p->info)
			q = q->pNext;
		NODE* next = p->pNext;
		if (q == l.pHead)
		{
			p->pNext = l.pHead;
			l.pHead->pPrev = p;
			l.pHead = p;
		}
		else
		{
			p->pNext = q;
			p->pPrev = q->pPrev;
			q->pPrev->pNext = p;
			q->pPrev = p;
		}
		p = next;
	}
}
int NodeCount(LIST l)
{
	int counter = 0;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		counter++;
		p = p->pNext;
	}
	return counter;
}
void Outp(LIST l)
{
	NODE* p = l.pHead;
	while (p != NULL)
	{
		cout << setw(5) << p->info;
		p = p->pNext;
	}
	cout << ".";
}
bool Outp(LIST l, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return false;
	fo << setw(5) << NodeCount(l) << endl;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		fo << setw(5) << p->info;
		p = p->pNext;
	}
	return true;
}