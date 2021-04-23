#include<iostream>
#include <cstdlib>
#include<iomanip>
#include<fstream>
using namespace std;
void Nhap(float[], int&, fstream&);
void Xuat(float[], int, fstream&);
int main()
{
	fstream input("input.txt", ios::in);
	fstream output("output.txt", ios::out);
	int k;
	static float b[1000009];
	Nhap(b, k, input);
	Xuat(b, k, output);
	return 1;
}
void Nhap(float a[], int& n, fstream& input)
{
	input >> n;
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		a[i] = -100.0 + (rand() / (RAND_MAX / (200.0)));
		input >> a[i];
	}
	input.close();
}
void Xuat(float a[], int n, fstream& output)
{
	output << n;
	for (int i = 0; i < n; i++)
		output << endl<< a[i];
	output.close();
}