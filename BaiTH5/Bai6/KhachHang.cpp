#include "KhachHang.h"
#include <algorithm>

KhachHang::KhachHang() { soLuong = 0; donGia = soTien = 0; }
KhachHang::~KhachHang() {}
void KhachHang::doc(ifstream& fin) {
    getline(fin, ten);
    fin >> soLuong;
    fin >> donGia;
    fin.ignore();
}
void KhachHang::ghi(ofstream& fout) const {
    fout << ten << '\n' << soTien << '\n';
}
double KhachHang::getSoTien() const { return soTien; }

double KhachHangA::tinhTien() {
    double tienHang = soLuong * donGia;
    soTien = tienHang + tienHang * 0.1;
    return soTien;
}

void KhachHangB::doc(ifstream& fin) {
    KhachHang::doc(fin);
    fin >> soNamThanThiet;
    fin.ignore();
}
double KhachHangB::tinhTien() {
    double tienHang = soLuong * donGia;
    double khuyenMai = min(soNamThanThiet * 0.05, 0.5);
    double sauGiam = tienHang * (1 - khuyenMai);
    soTien = sauGiam + sauGiam * 0.1;
    return soTien;
}

double KhachHangC::tinhTien() {
    double tienHang = soLuong * donGia * 0.5;
    soTien = tienHang + tienHang * 0.1;
    return soTien;
}