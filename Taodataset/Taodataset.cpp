#include<iostream>
#include <cstdlib>
#include<iomanip>
#include<fstream>
using namespace std;
void Nhap(int[], int&, fstream&);
void Xuat(int[], int, fstream&);
int main()
{
	fstream input("input.txt", ios::in);
	fstream output("output.txt", ios::out);
	int k;
	static int b[1000009];
	Nhap(b, k, input);
	Xuat(b, k, output);
	return 1;
}
void Nhap(int a[], int& n, fstream& input)
{
	input >> n;
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (20000 + 1) - 10000;
		input >> a[i];
	}
	input.close();
}
void Xuat(int a[], int n, fstream& output)
{
	output << n;
	for (int i = 0; i < n; i++)
		output <<endl << a[i];
	output.close();
}