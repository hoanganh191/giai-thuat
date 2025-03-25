#include <iostream>
#include <algorithm>

using namespace std;

void quickSort(int a[], int left, int right)
{
    int i; // chi so ben trai
    int j; // chi so ben phai
    i = left;
    j = right;
    int x = a[(left + right) / 2];
    do
    {
        while (a[i] < x)
            i++; // duyet cho den khi tim phan tu cua cap nghich the o ben trai ( truoc pivot nhung > pivot)
        while (a[j] > x)
            j--; // duyet cho den khi tim phan tu cua cap nghich the o ben trai ( sau pivot nhung < pivot)
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);

    // Xu ly cac phan tru o tren trai va ben phai theo chi so i va j sau phan hoach (do dieu kien dung)
    if (left < j)
    {
        quickSort(a, left, j);
    }

    if (i < right)
    {
        quickSort(a, i, right);
    }
}

int main()
{
    int ds[] = {5, 11, 6, 77, 11, 5, 2, 1};
    int n = sizeof(ds) / sizeof(int); // Dem so luong phan tu trong mang
    quickSort(ds, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << ds[i] << " ";
    }
}
