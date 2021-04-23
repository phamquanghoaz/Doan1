#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include<fstream>
#include <time.h>
using namespace std;

void Nhap(int[], int&, fstream&);
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
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
    heapSort(b, k);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "heapsort take " << time_use << "seconds";

    return 1;
}
void Nhap(int a[], int& n, fstream& input)
{
    input >> n;
    for (int i = 0; i < n; i++)
        input >> a[i];
    input.close();
}
