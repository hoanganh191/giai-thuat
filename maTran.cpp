#include <iostream>

using namespace std;

class Mang2Chieu
{
    protected:
        int **data;
        int m; // so hang
        int n; // so cot

    public:
        Mang2Chieu()
        {
            int m = 0;
            int n = 0;
        }

        Mang2Chieu(int m, int n)
        {
            this->m = m;
            this->n = n;
            data = new int *[m];
            for (int i = 0; i < m; i++)
            {
                data[i] = new int[n];
            }
        }

        ~Mang2Chieu()
        {
            for (int i = 0; i < m; i++)
            {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
            this->m = 0;
            this->n = 0;
            cout << "Xoa thanh cong" << endl;
        }

        
};

class MangB : public Mang2Chieu
{
    private:
        string tenMang;

    public:
        MangB() : Mang2Chieu()
        {
            cout << "Tao thanh cong" << endl;
        }

        MangB(int m, int n) : Mang2Chieu(m, n)
        {
            cout << "Tao thanh cong co tham so" << endl;
        }

        void nhap()
        {
            cout << "Nhap mang kich thuoc: ";
            cin >> this->m >> this->n;
            data = new int *[m];
            for (int i = 0; i < n; i++)
            {
                data[i] = new int[n];
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> data[i][j];
                }
            }
        }

        void xuat()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << data[i][j] << " ";
                }

                cout << "\n";
            }
        }

        friend istream &operator>>(istream &is, MangB &mang);
        friend ostream &operator<<(ostream &os, MangB mang);
};

istream& operator>>(istream &is, MangB &mang)
{
    cout << "Nhap ten ma tran :";
    getline(is,mang.tenMang);
    cout << "Nhap kich thuoc cua ma tran : ";
    is >> mang.m >> mang.n;
    //Cap phat dong
    mang.data = new int*[mang.m];
    for (int i = 0; i < mang.m; i++)
    {
        mang.data[i] = new int[mang.n];
    }
    
    for (int i = 0; i < mang.m; i++)
    {
        for (int j = 0; j < mang.n; j++)
        {
            is >> mang.data[i][j];
        }
    }
    cout << "Nhap thanh cong\n";
    return is;
}

int main()
{

    MangB mang1, mang2;
    cout << "Nhap mang 1 " << endl;
    cin >> mang1;
    cout << "Nhap mang 2" << endl;
    cin >> mang2;
    cout << "ket qua mang 1" <<  endl;
    mang1.xuat();
    cout << "mang 2 la: " << endl;
    mang2.xuat();
    
    

}
