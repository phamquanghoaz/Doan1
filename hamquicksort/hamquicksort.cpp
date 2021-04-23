#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include<fstream>
#include <time.h>
using namespace std;

void Nhap(int[], int&, fstream&);

void quickSort(int Data[], int l, int r)
{
	if (l <= r)
	{
		float key = Data[(l + r) / 2];

		int i = l;
		int j = r;

		while (i <= j)
		{
			while (Data[i] < key)
				i++;
			while (Data[j] > key)
				j--;

			if (i <= j)
			{
				swap(Data[i], Data[j]);
				i++;
				j--;
			}
		}


		if (l < j)
			quickSort(Data, l, j);
		if (r > i)
			quickSort(Data, i, r);
	}
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
    quickSort(b, 0, k - 1);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "quicksort take " << time_use << "seconds";

	return 1;
}
void Nhap(int a[], int& n, fstream& input)
{
	input >> n;
	for (int i = 0; i < n; i++)
		input >> a[i];
	input.close();
}
