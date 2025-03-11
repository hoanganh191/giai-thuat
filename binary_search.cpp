#include <iostream>

using namespace std;

int lower_bound(int ds[],int n,int x){
    int left = 0;
    int right = n;
    while(left < right){
        int mid = left + (right - left)/2;
        if(ds[mid] < x) left = mid + 1;
        else right = mid;
    }

    if (left < n && ds[left] == x)
    {
        return left;
    } else {
        return -1;
    }
    
}

int upper_bound(int ds[],int n,int x){
    int left = 0;
    int right = n;
    while(left < right){
        int mid = left + (right - left)/2;
        if(ds[mid] <= x) left = mid + 1;
        else right = mid;
    }

    if (left - 1 >= 0 && ds[left-1] == x)
    {
        return left - 1;
    } else {
        return -1;
    }
    
}

int main(){
    int ds[7] = {1,1,2,2,2,4,5};
    int n = sizeof(ds)/sizeof(int);
    int kq = upper_bound(ds,n,2);
    cout << "Ket qua la : " << kq << endl;
}