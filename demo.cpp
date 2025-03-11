#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &ds, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> a(n1);
    vector<int> b(n2);
    for (int i = 0; i < n1; i++)
    {
        a[i] = ds[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        b[j] = ds[mid + 1 + j];
    }

    int count1 = 0;
    int count2 = 0;
    while (count1 < n1 && count2 < n2)
    {
        if (a[count1] < b[count2])
        {
            ds[left++] = a[count1++];
        }
        else
        {
            ds[left++] = b[count2++];
        }
    }

    while (count1 < n1)
    {
        ds[left++] = a[count1++];
    }

    while (count2 < n2)
    {
        ds[left++] = b[count2++];
    }
}

void mergeSort(vector<int> &ds, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(ds, left, mid);
        mergeSort(ds, mid + 1, right);
        merge(ds, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> ds;
    vector<int> kc;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ds.push_back(temp);
    }
    mergeSort(ds, 0, ds.size() - 1);
    for (int i = 0; i < n - 1; i++)
    {
        kc.push_back(ds[i + 1] - ds[i]);
    }
    mergeSort(kc,0,kc.size() - 1);
    int minIndex = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(kc[minIndex] > kc[i]) minIndex = i;
    }

    cout << "\nKhoang cach gan nhat la: " << kc[minIndex];
    
}
