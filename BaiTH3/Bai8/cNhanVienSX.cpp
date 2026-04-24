#include "cNhanVienSX.h"

// constructor mặc định
cNhanVienSX::cNhanVienSX() {
    ma = ten = "";
    ngay = thang = nam = 0;
    soSP = 0;
    donGia = 0;
}

// constructor có tham số
cNhanVienSX::cNhanVienSX(string ma, string ten, int d, int m, int y, int sp, double dg) {
    this->ma = ma;
    this->ten = ten;
    ngay = d; thang = m; nam = y;
    soSP = sp;
    donGia = dg;
}

// tính lương
double cNhanVienSX::getLuong() {
    return soSP * donGia;
}

// tính tuổi
int cNhanVienSX::Tuoi() {
    return 2025 - nam;
}

// nhập
void cNhanVienSX::Nhap() {
    cin.ignore();
    cout << "Ma: "; getline(cin, ma);
    cout << "Ten: "; getline(cin, ten);
    cout << "Ngay sinh (d m y): ";
    cin >> ngay >> thang >> nam;
    cout << "So SP: "; cin >> soSP;
    cout << "Don gia: "; cin >> donGia;
}

// xuất
void cNhanVienSX::Xuat() {
    cout << ma << " | " << ten << " | "
         << ngay << "/" << thang << "/" << nam
         << " | SP: " << soSP
         << " | Don gia: " << donGia
         << " | Luong: " << getLuong()
         << " | Tuoi: " << Tuoi()
         << endl;
}