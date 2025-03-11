#include <iostream>
#include <cmath>

using namespace std;

class SoPhuc {
    private:
        int thuc;
        int ao;
    public:
        SoPhuc(){
            thuc = 0;
            ao = 0;
        }

        SoPhuc(int a, int b){
            thuc = a;
            ao = b;
        }

        friend istream &operator >> (istream &is,SoPhuc &sp1){
            cout << "Nhap phan thuc va ao: ";
            is >> sp1.thuc >> sp1.ao;
            return is; 
        }

        void xuat(){
            if (ao > 0)
            {
                cout << thuc << " + " << ao << "i";
            } else {
                cout << thuc << " " << ao << "i";
            }
            
        }

        float modul(){
            return sqrt(thuc*thuc + ao*ao);
        }

        SoPhuc &operator = (const SoPhuc sp2){
            this->thuc = sp2.thuc;
            this->ao = sp2.ao;
            return *this;
        }

        bool operator > (SoPhuc sp2){
            return this->modul() >  sp2.modul();
        }

        SoPhuc operator * (SoPhuc sp2){
            SoPhuc ketqua;
            ketqua.thuc = this->thuc*sp2.thuc - this->ao*sp2.ao;
            ketqua.ao = this->thuc*sp2.ao + this->ao*sp2.thuc;
            return ketqua; 
        }

       



};

int main(){
    SoPhuc sp1(2,5),sp2(3,6);
    SoPhuc tich = sp1 * sp2;
    tich.xuat();
    
}