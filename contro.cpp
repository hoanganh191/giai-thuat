#include <iostream>

using namespace std;

void demo(int **a){
    **a = 100;
}

int main(){
    int x = 10;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;
    demo(ptr2);
    cout<< x;
}