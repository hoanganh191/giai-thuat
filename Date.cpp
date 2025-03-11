#include <iostream>

using namespace std;

class date {
    private:
        int ngay;
        int thang;
        int nam;
    
    public:
        date(){
            this->ngay = 0;
            this->thang = 0;
            this->nam = 0;
        }

        date(int ngay, int thang,int nam){
            this->ngay = ngay;
            this->thang = thang;
            this->nam = nam;
        }

        ~date(){
            this->ngay = 0;
            this->thang = 0;
            this->nam = 0;
        }

        int getNgay(int t,int n){
            switch(t){
                case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12: 
                    return 31;
                    break;
                case 2:
                    if(n % 400 == 0 || (n % 4 == 0 && n % 100 != 0) ) return 29;
                    else return 28;
                    break;
                default:
                    return 30;
                    break;
                     
            }
        }

        void nhap(){
            do {
                cout << "Nhap ngay : ";
                cin >> ngay;
                cout << "Nhap thang : ";
                cin >> thang;
                cout << "Nhap nam : ";
                cin >> nam;
            } while(ngay > this->getNgay(thang,nam) || thang < 1 || thang > 12 || nam < 1 );
            
        }

        void xuat(){
            cout << ngay << " / " << thang << " / " << nam << endl;
        }

        void chuanHoa(){
            while(ngay > getNgay(thang,nam)){
                ngay = ngay - getNgay(thang,nam);
                thang++;
                if(thang > 12) {
                    thang = 1;
                    nam++;
                }
            }
        }

        date operator ++(){
            date ketqua;
            ketqua.ngay = this->ngay;
            ketqua.thang = this->thang;
            ketqua.nam = this->nam;
            ketqua.ngay++;
            ketqua.chuanHoa();
            return ketqua;
        }

        date operator -- (){
            date ketqua(this->ngay,this->thang,this->nam);
            ketqua.ngay--;
            if (ketqua.ngay < 1)
            {
                ketqua.thang--;
                ketqua.ngay = ketqua.getNgay(ketqua.thang,ketqua.ngay);
            }

            if(ketqua.thang < 1){
                ketqua.thang = 12;
                ketqua.nam--;
                if(ketqua.nam <= 0){
                    cout << "Thoi gian ban nhap khong the quay ve truoc cong nguyen";
                    return *this;
                }
                
            }
            
            return ketqua;
        }

};

int main(){
    date ngay1,tang,giam;
    ngay1.nhap();
    cout << "Ban vua nhap ngay : " ;
    ngay1.xuat();
    cout << "\nTang 1 ngay la: ";
    tang = ++ngay1;
    tang.xuat();
    cout << "\ngiam 1 ngay la: ";
    giam = --ngay1;
    giam.xuat();


}