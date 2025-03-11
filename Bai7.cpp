#include <iostream>
#include <string>
using namespace std;

class ThiSinh {
private:
    string maThiSinh;
    string hoTen;
    float diemToan;
    float diemLy;
    float diemHoa;

public:

    ~ThiSinh(){
        cout << "Giai phong thi sinh " << hoTen << endl;
    }
    // Phương thức nhập thông tin thí sinh
    void nhap() {
        cout << "Nhap ma thi sinh: ";
        cin >> maThiSinh;
        cin.ignore();  // Để tránh lỗi khi nhập tên
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap diem Toan: ";
        cin >> diemToan;
        cout << "Nhap diem Ly: ";
        cin >> diemLy;
        cout << "Nhap diem Hoa: ";
        cin >> diemHoa;
    }

    // Phương thức xuất thông tin thí sinh
    void xuat() {
        cout << "Ma thi sinh: " << maThiSinh << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem Toan: " << diemToan << endl;
        cout << "Diem Ly: " << diemLy << endl;
        cout << "Diem Hoa: " << diemHoa << endl;
    }

    // Phương thức tính tổng điểm
    float tinhTongDiem() {
        return diemToan + diemLy + diemHoa;
    }

    // Phương thức kiểm tra điểm hợp lệ
    bool kiemTraDiem() {
        return diemToan >= 2 && diemLy >= 2 && diemHoa >= 2;
    }

    // Getter để lấy tổng điểm
    float getTongDiem() {
        return tinhTongDiem();
    }
};

int main() {
    int n;
    cout << "Nhap so luong sinh vien : ";
    cin >> n;
    ThiSinh *dsthisinh = new ThiSinh[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien " << i + 1 << " : ";
        dsthisinh[i].nhap();
    }

    //In ra thi sinh diem cao nhat 
    int indexMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (dsthisinh[indexMax].getTongDiem() < dsthisinh[i].getTongDiem())
        {
            indexMax = i;
        }
        
        
    }

    cout << "----thi sinh co diem cao nhat la----" << endl;
    dsthisinh[indexMax].xuat();
    delete[] dsthisinh;

    

    
    
}
