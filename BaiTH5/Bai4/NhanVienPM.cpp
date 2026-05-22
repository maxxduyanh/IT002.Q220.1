#include "NhanVienPM.h"

NhanVienPM::NhanVienPM() { tuoi = 0; luongCoBan = luong = 0; }
NhanVienPM::~NhanVienPM() {}
void NhanVienPM::nhap() {
    cin.ignore();
    cout << "Nhap ma NV: "; getline(cin, maNV);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap tuoi: "; cin >> tuoi; cin.ignore();
    cout << "Nhap so dien thoai: "; getline(cin, soDienThoai);
    cout << "Nhap email: "; getline(cin, email);
    cout << "Nhap luong co ban: "; cin >> luongCoBan;
}
void NhanVienPM::xuat() const {
    cout << "Ma NV: " << maNV << " | Ho ten: " << hoTen
         << " | Tuoi: " << tuoi << " | SDT: " << soDienThoai
         << " | Email: " << email << " | Luong: " << luong;
}
double NhanVienPM::getLuong() const { return luong; }

void LapTrinhVien::nhap() {
    NhanVienPM::nhap();
    cout << "Nhap so gio overtime: "; cin >> soGioOvertime;
    tinhLuong();
}
void LapTrinhVien::xuat() const {
    cout << "[Lap trinh vien] "; NhanVienPM::xuat();
    cout << " | Overtime: " << soGioOvertime << endl;
}
double LapTrinhVien::tinhLuong() {
    luong = luongCoBan + soGioOvertime * 200000;
    return luong;
}

void KiemChungVien::nhap() {
    NhanVienPM::nhap();
    cout << "Nhap so loi phat hien: "; cin >> soLoiPhatHien;
    tinhLuong();
}
void KiemChungVien::xuat() const {
    cout << "[Kiem chung vien] "; NhanVienPM::xuat();
    cout << " | So loi: " << soLoiPhatHien << endl;
}
double KiemChungVien::tinhLuong() {
    luong = luongCoBan + soLoiPhatHien * 50000;
    return luong;
}