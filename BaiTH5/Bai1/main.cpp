#include "NhanVien.h"

int main() {
    int n, m;
    vector<NhanVienSanXuat> dsSX;
    vector<NhanVienVanPhong> dsVP;

    cout << "Nhap so nhan vien san xuat: "; cin >> n;
    dsSX.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNhap nhan vien san xuat thu " << i + 1 << endl;
        dsSX[i].nhap();
    }

    cout << "\nNhap so nhan vien van phong: "; cin >> m;
    dsVP.resize(m);
    for (int i = 0; i < m; i++) {
        cout << "\nNhap nhan vien van phong thu " << i + 1 << endl;
        dsVP[i].nhap();
    }

    double tongLuong = 0;
    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    for (auto &x : dsSX) { x.xuat(); tongLuong += x.getLuong(); }
    for (auto &x : dsVP) { x.xuat(); tongLuong += x.getLuong(); }
    cout << "\nTong luong cong ty phai tra: " << tongLuong << endl;

    if (!dsSX.empty()) {
        int vt = 0;
        for (int i = 1; i < dsSX.size(); i++)
            if (dsSX[i].getLuong() < dsSX[vt].getLuong()) vt = i;
        cout << "\nNhan vien san xuat co luong thap nhat:\n";
        dsSX[vt].xuat();
    }
    if (!dsVP.empty()) {
        int vt = 0;
        for (int i = 1; i < dsVP.size(); i++)
            if (dsVP[i].getTuoi() > dsVP[vt].getTuoi()) vt = i;
        cout << "\nNhan vien van phong co tuoi cao nhat:\n";
        dsVP[vt].xuat();
    }
    return 0;
}