#include "cNhanVienVP.h"

// constructor mặc định
cNhanVienVP::cNhanVienVP() {
    ma = "";
    ten = "";
    ngay = thang = nam = 0;
    luong = 0;
}

// constructor có tham số
cNhanVienVP::cNhanVienVP(string ma, string ten, int d, int m, int y, double luong) {
    this->ma = ma;
    this->ten = ten;
    ngay = d;
    thang = m;
    nam = y;
    this->luong = luong;
}

// getter
string cNhanVienVP::getMa() { return ma; }
string cNhanVienVP::getTen() { return ten; }
double cNhanVienVP::getLuong() { return luong; }
int cNhanVienVP::getNamSinh() { return nam; }

// setter
void cNhanVienVP::setLuong(double l) { luong = l; }

// Input: thông tin nhân viên
void cNhanVienVP::Nhap() {
    cin.ignore();
    cout << "Ma: "; getline(cin, ma);
    cout << "Ten: "; getline(cin, ten);
    cout << "Ngay sinh (d m y): ";
    cin >> ngay >> thang >> nam;
    cout << "Luong: ";
    cin >> luong;
}

// Output: thông tin nhân viên
void cNhanVienVP::Xuat() {
    cout << ma << " | " << ten << " | "
         << ngay << "/" << thang << "/" << nam
         << " | Luong: " << luong
         << " | Tuoi: " << Tuoi()
         << endl;
}

// Output: tuổi
// Thuật toán: năm hiện tại - năm sinh (giả sử 2025)
int cNhanVienVP::Tuoi() {
    return 2025 - nam;
}