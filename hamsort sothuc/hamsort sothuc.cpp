#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include<fstream>
#include <time.h>
#include<algorithm>
using namespace std;

void Nhap(float[], int&, fstream&);

bool comp(const int a, const int b) {
    return a < b;
}

int main()
{
    clock_t start, end;
    double time_use;
    fstream input("input.txt", ios::in);
    fstream output("output.txt", ios::out);
    int k;
    static float b[1000000];
    Nhap(b, k, input);
    start = clock();
    sort(b, b + k);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "sort take " << time_use << "seconds";
    return 1;
}
void Nhap(float a[], int& n, fstream& input)
{
    input >> n;
    for (int i = 0; i < n; i++)
        input >> a[i];
    input.close();
}
