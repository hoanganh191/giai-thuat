#include <iostream>
#include <vector>

void swap2(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

using namespace std;
int partition(vector<int> &ds,int left, int right){
    int pivot = ds[right]; 
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (ds[j] <= pivot)
        {
            i++;
            swap2(ds[j],ds[i]);
        }
        
    }
    
    swap2(ds[i+1],ds[right]);
    
    return i+1 ;
    
}

void quickSort(vector<int> &ds,int left, int right){
    if(left >= right) return;
    int pi = partition(ds,left,right);
    quickSort(ds,left,pi - 1);
    quickSort(ds,pi + 1,right);
}
int main(){
    vector<int> ds = {3,55,6,77,9,11,8,6};
    quickSort(ds,0,ds.size() - 1);
    for(int x : ds){
        cout << x << " ";
    }
}