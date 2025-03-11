#include <iostream>

using namespace std;

class Time {
    private:
        int gio;
        int phut;
        int giay;
    public:
        Time(){
            gio = 0;
            phut = 0;
            giay = 0;
        }

        Time(int gio, int phut, int giay){
            this->gio = gio;
            this->phut = phut;
            this->giay = giay;
        }

        void nhap(){
            do {
                cout << "Nhap gio : " ;
                cin >> gio;
            } while(gio >= 24 || gio < 0);
            
            do {
                cout << "Nhap phut : ";
                cin >> phut;
            } while(phut >= 60 || phut < 0);

            do {
                cout << "Nhap giay : ";
                cin >> giay;
            } while(giay >= 60 || giay < 0);
        }

        void xuat(){
            cout << gio << ": " << phut << " :" << giay << endl;
        }

        void chuanHoa(){
            //Ta se chuan hoa theo thu tu giay => phut => gio
            if(giay >= 60){
                phut= phut + giay/60; //chia lay phan nguyen
                giay = giay%60; //chia lay phan du
            } 

            if(giay < 0){
                int temp = abs(giay);//Bien tam doi giay sang duong de chia lay nguyen va du
                giay = 60 - temp%60; //Do luc nay giay dang am, ta bu 1 phut = 60 giay de cho no ve duong
                phut = phut - temp/60 - 1;
            }

            if(phut >= 60){
                gio = gio + phut/60;
                phut = phut%60;
            }

            if(phut < 0){
                int temp = abs(phut);
                phut = 60 - temp%60;
                gio = gio - temp/60 - 1;
            }

            if (gio >= 24)
            {
                gio = gio % 24;
            }

            if(gio < 0){
                gio = (24 + (gio%24)%24); //Luc nay gio dang am thi ta lui dong ho bay nhieu 
            }
            

        }

        Time operator ++ (){
            Time ketqua;
            ketqua.gio = this->gio;
            ketqua.phut = this->phut;
            ketqua.giay = this->giay;
            ketqua.giay++;
            ketqua.chuanHoa();
            return ketqua;
        }

        Time operator -- (){
            Time ketqua;
            ketqua.gio = this->gio;
            ketqua.phut = this->phut;
            ketqua.giay = this->giay;
            ketqua.giay--;
            ketqua.chuanHoa();
            return ketqua;
        }


};


int main(){
    Time tg1, ketquagiam,ketquatang;
    cout << "Nhap thoi gian 1 :";
    tg1.nhap();
    ketquagiam = --tg1;
    ketquatang = ++tg1;
    cout << "Ket qua tang 1 giay la: ";
    ketquatang.xuat();
    cout << "\nKet qua giam 1 giay la: ";
    ketquagiam.xuat();


}