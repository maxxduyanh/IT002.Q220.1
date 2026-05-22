#include "GiaoDich.h"

NgayGD::NgayGD(int d, int m, int y) : ngay(d), thang(m), nam(y) {}
bool NgayGD::laThang12Nam2024() const { return thang == 12 && nam == 2024; }
istream& operator>>(istream& in, NgayGD& n) {
    cout << "Nhap ngay thang nam giao dich: ";
    in >> n.ngay >> n.thang >> n.nam;
    return in;
}
ostream& operator<<(ostream& out, const NgayGD& n) {
    out << n.ngay << "/" << n.thang << "/" << n.nam;
    return out;
}

GiaoDich::GiaoDich() { donGia = dienTich = thanhTien = 0; }
GiaoDich::~GiaoDich() {}
void GiaoDich::nhap() {
    cin.ignore();
    cout << "Nhap ma giao dich: "; getline(cin, maGD);
    cin >> ngayGD;
    cout << "Nhap don gia: "; cin >> donGia;
    cout << "Nhap dien tich: "; cin >> dienTich;
}
void GiaoDich::xuat() const {
    cout << "Ma GD: " << maGD << " | Ngay GD: " << ngayGD
         << " | Don gia: " << donGia << " | Dien tich: " << dienTich
         << " | Thanh tien: " << thanhTien;
}
double GiaoDich::getThanhTien() const { return thanhTien; }
bool GiaoDich::giaoDichThang12Nam2024() const { return ngayGD.laThang12Nam2024(); }

void GiaoDichDat::nhap() {
    GiaoDich::nhap();
    cout << "Nhap loai dat (A/B/C): "; cin >> loaiDat;
    tinhThanhTien();
}
void GiaoDichDat::xuat() const {
    cout << "[Giao dich dat] "; GiaoDich::xuat();
    cout << " | Loai dat: " << loaiDat << endl;
}
double GiaoDichDat::tinhThanhTien() {
    thanhTien = dienTich * donGia;
    if (loaiDat == 'A' || loaiDat == 'a') thanhTien *= 1.5;
    return thanhTien;
}

void GiaoDichNhaPho::nhap() {
    GiaoDich::nhap();
    cin.ignore();
    cout << "Nhap loai nha (cao cap/thuong): "; getline(cin, loaiNha);
    cout << "Nhap dia chi: "; getline(cin, diaChi);
    tinhThanhTien();
}
void GiaoDichNhaPho::xuat() const {
    cout << "[Giao dich nha pho] "; GiaoDich::xuat();
    cout << " | Loai nha: " << loaiNha << " | Dia chi: " << diaChi << endl;
}
double GiaoDichNhaPho::tinhThanhTien() {
    thanhTien = dienTich * donGia;
    if (loaiNha == "thuong") thanhTien *= 0.9;
    return thanhTien;
}

void GiaoDichCanHo::nhap() {
    GiaoDich::nhap();
    cin.ignore();
    cout << "Nhap ma can: "; getline(cin, maCan);
    cout << "Nhap vi tri tang: "; cin >> viTriTang;
    tinhThanhTien();
}
void GiaoDichCanHo::xuat() const {
    cout << "[Giao dich can ho] "; GiaoDich::xuat();
    cout << " | Ma can: " << maCan << " | Tang: " << viTriTang << endl;
}
double GiaoDichCanHo::tinhThanhTien() {
    thanhTien = dienTich * donGia;
    if (viTriTang == 1) thanhTien *= 2;
    else if (viTriTang >= 15) thanhTien *= 1.2;
    return thanhTien;
}