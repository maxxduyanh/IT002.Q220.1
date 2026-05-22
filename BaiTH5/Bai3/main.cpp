#include "SinhVien.h"

int main() {
    int nCD, nDH;
    vector<SinhVienCaoDang> dsCD;
    vector<SinhVienDaiHoc> dsDH;

    cout << "Nhap so sinh vien cao dang: "; cin >> nCD; dsCD.resize(nCD);
    for (int i = 0; i < nCD; i++) { cout << "\nSinh vien CD " << i + 1 << endl; dsCD[i].nhap(); }
    cout << "Nhap so sinh vien dai hoc: "; cin >> nDH; dsDH.resize(nDH);
    for (int i = 0; i < nDH; i++) { cout << "\nSinh vien DH " << i + 1 << endl; dsDH[i].nhap(); }

    cout << "\n===== DANH SACH SINH VIEN =====\n";
    for (auto &x : dsCD) x.xuat();
    for (auto &x : dsDH) x.xuat();

    cout << "\n===== SINH VIEN DU DIEU KIEN TOT NGHIEP =====\n";
    for (auto &x : dsCD) if (x.duDieuKienTotNghiep()) x.xuat();
    for (auto &x : dsDH) if (x.duDieuKienTotNghiep()) x.xuat();

    cout << "\n===== SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP =====\n";
    int khongDatCD = 0, khongDatDH = 0;
    for (auto &x : dsCD) if (!x.duDieuKienTotNghiep()) { x.xuat(); khongDatCD++; }
    for (auto &x : dsDH) if (!x.duDieuKienTotNghiep()) { x.xuat(); khongDatDH++; }

    if (!dsDH.empty()) {
        int vt = 0;
        for (int i = 1; i < dsDH.size(); i++)
            if (dsDH[i].getDiemTB() > dsDH[vt].getDiemTB()) vt = i;
        cout << "\nSinh vien DH co DTB cao nhat:\n"; dsDH[vt].xuat();
    }
    if (!dsCD.empty()) {
        int vt = 0;
        for (int i = 1; i < dsCD.size(); i++)
            if (dsCD[i].getDiemTB() > dsCD[vt].getDiemTB()) vt = i;
        cout << "\nSinh vien CD co DTB cao nhat:\n"; dsCD[vt].xuat();
    }
    cout << "\nSo SV CD khong du DK: " << khongDatCD;
    cout << "\nSo SV DH khong du DK: " << khongDatDH << endl;
    return 0;
}