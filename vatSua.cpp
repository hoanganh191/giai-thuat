#include <iostream>
#include <algorithm>

using namespace std;

void bublle_sort(int ds[5], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (ds[j] < ds[j + 1])
            {
                swap(ds[j], ds[j + 1]);
            }
        }
    }
}

void insert_sort(int ds[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = ds[i];
        int j = i - 1;
        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && ds[j] > key) {
            ds[j + 1] = ds[j];
            j = j - 1;
        }
        ds[j + 1] = key;
    }
    
}

int main()
{
    int ds[] = {5,4,3,2,1};
    int n = sizeof(ds) / sizeof(int);
    insert_sort(ds, n);

    for (int i = 0; i < n; i++)
    {
        cout << ds[i] << " ";
    }
    cout << "\n";
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        cout << ds[left++] << " " << ds[right--] << endl;
    }
    
}   
