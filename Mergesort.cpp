#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &ds, int left , int mid , int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> day1(n1);
    vector<int> day2(n2);
    for (int i = 0; i < n1; i++)
    {
        day1[i] = ds[left+i];
    }
    
    for (int j = 0; j < n2; j++)
    {
        day2[j] = ds[mid + 1 + j];
    }

    int count1 = 0;
    int count2 = 0;
    int k = left;
    while(count1 < n1 && count2 < n2){
        if (day1[count1] >= day2[count2])
        {
            ds[k++] = day2[count2++];
        }
        else 
        {
            ds[k++] = day1[count1++];
        }
        
    }

    while (count2 < n2)
    {
        ds[k++] = day2[count2++];
    }
    
    while (count1 < n1)
    {
        ds[k++] = day1[count1++];
    }
  

}

void MergeSort(vector<int>& ds ,int left, int right){
    if(left >= right) return;
    int mid = left + (right - left)/2;
    MergeSort(ds,left,mid);
    MergeSort(ds,mid + 1, right);
    merge(ds,left,mid,right);
}

int main(){
    

}