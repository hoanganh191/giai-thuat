#include<iostream>
#include<cmath>

using namespace std;

int ucln(int a, int b){
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0)
    {
        return a+b;
    }

    while(b != 0){
        int temp = a%b;
        a = b;
        b = temp;
    }

    return a;
    
}

class PhanSo {
    protected:
        int tu = 0;
        int mau = 0;
    public:
        PhanSo(){
            tu = 0;
            mau = 0;
        }

        PhanSo(int a, int b){
            tu = a;
            mau = b;
        }
        
        PhanSo &operator = (const PhanSo &ps2){
            tu = ps2.tu;
            mau = ps2.mau;
            return *this;
        }

        PhanSo operator + (PhanSo &ps2){
            PhanSo ketqua;
            ketqua.tu = this->tu*ps2.mau + ps2.tu*this->mau;
            ketqua.mau = this->mau*ps2.mau;
            ketqua.rutgon();
            return ketqua;
        }

        void nhap(){
            cout << "Nhap tu va mau : ";
            cin >> tu >> mau;
        }

        void xuat(){
            cout << tu << " / " << mau << endl;
        }

        PhanSo rutgon(){
            int uc = ucln(tu,mau);
            tu = tu/uc;
            mau = mau/uc;
            return *this;
        }

        bool operator > (PhanSo ps2){
            return (this->tu)*ps2.mau > ps2.tu*(this->mau);
        }
};

int main(){
    // PhanSo ds[20];
    // int n =3;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "\nNhap phan so thu " << i + 1 << " :";
    //     ds[i].nhap();
    // }

    // cout << "---Danh sach sap xep la: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j =  i + 1; j < n; j++)
    //     {
    //         if(ds[j] > ds[i]){
    //             PhanSo temp = ds[i];
    //             ds[i] = ds[j];
    //             ds[j] = temp;
    //         }
    //     }
        
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     ds[i].xuat();
        
    // }
    
    PhanSo ps1(2,5),ps2(3,5);
    PhanSo tong;
    tong = ps1 + ps2;
    tong.rutgon().xuat();
    
 
    
    


}
