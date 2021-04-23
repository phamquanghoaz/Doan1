#include<stdio.h>
#include<iomanip>
#include <stdlib.h>
#include<fstream>
#include <time.h>
using namespace std;
void Nhap(int[], int&, fstream&);
void Xuat(int [], int , fstream& );
int cmpfunc(const void* a, const void* b)
{
	return (*(int*)b - *(int*)a);
}
int main()
{
	clock_t start, end;
	double time_use;
	fstream input("input.txt", ios::in);
	fstream output("output.txt", ios::out);
	int k;
	static int b[1000000];
	Nhap(b, k, input);
	start = clock();
	qsort(b, 1000000, sizeof(int),cmpfunc);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	printf("qSort take %f seconds", time_use);
	Xuat(b, k, output);
	return 1;
}
void Nhap(int a[], int& n, fstream& input)
{
	input >> n;
	for (int i = 0; i < n; i++)
		input >> a[i];
	input.close();
}

void Xuat(int a[], int n, fstream& output)
{
	output << n;
	for (int i = 0; i < n; i++)
		output << endl << a[i];
	output.close();
}