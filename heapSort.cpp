#include <iostream>
#include <algorithm>

using namespace std;

void heaptify(int ds[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (largest < left && left < n)
    {
        largest = left;
    }

    if (largest < right && right < n)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(ds[largest], ds[i]);
        heaptify(ds, n, largest);
    }
}

void heapSort(int ds[],int n){
    for (int i = (n-1)/2; i >= 0; i--)
    {
        heaptify(ds,n,i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(ds[0],ds[i]);
        heaptify(ds,i,0);
    }
    
    
}

int main()
{
    int ds[] = {3,55,6,77,9,11,8,6};
    int n = sizeof(ds)/sizeof(int);
    heapSort(ds,n);
    for(int x : ds){
        cout << x << " ";
    }
}