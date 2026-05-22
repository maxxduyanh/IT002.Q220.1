#include "NhanVien.h"

Ngay::Ngay(int d, int m, int y) : ngay(d), thang(m), nam(y) {}
int Ngay::tinhTuoi(int namHienTai) const { return namHienTai - nam; }
istream& operator>>(istream& in, Ngay& n) {
    cout << "Nhap ngay thang nam: ";
    in >> n.ngay >> n.thang >> n.nam;
    return in;
}
ostream& operator<<(ostream& out, const Ngay& n) {
    out << n.ngay << "/" << n.thang << "/" << n.nam;
    return out;
}

NhanVien::NhanVien() { luong = 0; }
NhanVien::~NhanVien() {}
void NhanVien::nhap() {
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap ngay sinh\n"; cin >> ngaySinh;
}
void NhanVien::xuat() const {
    cout << "Ho ten: " << hoTen << " | Ngay sinh: " << ngaySinh
         << " | Luong: " << luong;
}
double NhanVien::getLuong() const { return luong; }
int NhanVien::getTuoi() const { return ngaySinh.tinhTuoi(); }

void NhanVienSanXuat::nhap() {
    NhanVien::nhap();
    cout << "Nhap luong can ban: "; cin >> luongCanBan;
    cout << "Nhap so san pham: "; cin >> soSanPham;
    tinhLuong();
}
void NhanVienSanXuat::xuat() const {
    cout << "[Nhan vien san xuat] ";
    NhanVien::xuat();
    cout << " | Luong can ban: " << luongCanBan
         << " | So san pham: " << soSanPham << endl;
}
double NhanVienSanXuat::tinhLuong() {
    luong = luongCanBan + soSanPham * 5000;
    return luong;
}
void NhanVienVanPhong::nhap() {
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: "; cin >> soNgayLamViec;
    tinhLuong();
}
void NhanVienVanPhong::xuat() const {
    cout << "[Nhan vien van phong] ";
    NhanVien::xuat();
    cout << " | So ngay lam viec: " << soNgayLamViec << endl;
}
double NhanVienVanPhong::tinhLuong() {
    luong = soNgayLamViec * 100000;
    return luong;
}