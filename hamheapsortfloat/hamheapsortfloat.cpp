#include<iostream>
#include<iomanip>
#include <stdlib.h>
#include<fstream>
#include <time.h>
using namespace std;

void Nhap(float[], int&, fstream&);
void heapify(float arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(float arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
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
    static float b[1000000];
    Nhap(b, k, input);
    start = clock();
    heapSort(b, k);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "heapsort take " << time_use << "seconds";

    return 1;
}
void Nhap(float a[], int& n, fstream& input)
{
    input >> n;
    for (int i = 0; i < n; i++)
        input >> a[i];
    input.close();
}
