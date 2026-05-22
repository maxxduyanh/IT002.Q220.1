#include "SinhVien.h"

SinhVien::SinhVien() { tongTinChi = 0; diemTB = 0; }
SinhVien::~SinhVien() {}
void SinhVien::nhap() {
    cin.ignore();
    cout << "Nhap MSSV: "; getline(cin, maSV);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap dia chi: "; getline(cin, diaChi);
    cout << "Nhap tong tin chi: "; cin >> tongTinChi;
    cout << "Nhap diem trung binh: "; cin >> diemTB;
}
void SinhVien::xuat() const {
    cout << "MSSV: " << maSV << " | Ho ten: " << hoTen
         << " | Dia chi: " << diaChi << " | Tin chi: " << tongTinChi
         << " | Diem TB: " << diemTB;
}
double SinhVien::getDiemTB() const { return diemTB; }

void SinhVienCaoDang::nhap() {
    SinhVien::nhap();
    cout << "Nhap diem thi tot nghiep: "; cin >> diemThiTotNghiep;
}
void SinhVienCaoDang::xuat() const {
    cout << "[Sinh vien cao dang] "; SinhVien::xuat();
    cout << " | Diem thi TN: " << diemThiTotNghiep
         << " | Ket qua: " << (duDieuKienTotNghiep() ? "Du DK" : "Khong du DK") << endl;
}
bool SinhVienCaoDang::duDieuKienTotNghiep() const {
    return tongTinChi >= 120 && diemTB >= 5 && diemThiTotNghiep >= 5;
}

void SinhVienDaiHoc::nhap() {
    SinhVien::nhap();
    cin.ignore();
    cout << "Nhap ten luan van: "; getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: "; cin >> diemLuanVan;
}
void SinhVienDaiHoc::xuat() const {
    cout << "[Sinh vien dai hoc] "; SinhVien::xuat();
    cout << " | Ten luan van: " << tenLuanVan << " | Diem LV: " << diemLuanVan
         << " | Ket qua: " << (duDieuKienTotNghiep() ? "Du DK" : "Khong du DK") << endl;
}
bool SinhVienDaiHoc::duDieuKienTotNghiep() const {
    return tongTinChi >= 170 && diemTB >= 5 && diemLuanVan >= 5;
}