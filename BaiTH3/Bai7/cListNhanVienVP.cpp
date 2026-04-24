#include "cListNhanVienVP.h"
#include <algorithm>

// Input: n nhân viên
void cListNhanVienVP::Nhap() {
    int n;
    cout << "Nhap so NV: ";
    cin >> n;
    ds.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "\nNV " << i+1 << ":\n";
        ds[i].Nhap();
    }
}

// Output: danh sách
void cListNhanVienVP::Xuat() {
    for (auto x : ds)
        x.Xuat();
}

// Output: NV lương cao nhất
cNhanVienVP cListNhanVienVP::MaxLuong() {
    return *max_element(ds.begin(), ds.end(), [](cNhanVienVP a, cNhanVienVP b){
        return a.getLuong() < b.getLuong();
    });
}

// Output: tổng lương
double cListNhanVienVP::TongLuong() {
    double sum = 0;
    for (auto x : ds)
        sum += x.getLuong();
    return sum;
}

// Output: NV lớn tuổi nhất
cNhanVienVP cListNhanVienVP::LonTuoiNhat() {
    return *max_element(ds.begin(), ds.end(), [](cNhanVienVP a, cNhanVienVP b){
        return a.Tuoi() < b.Tuoi();
    });
}

// sắp xếp tăng theo lương
void cListNhanVienVP::SapXepTangLuong() {
    sort(ds.begin(), ds.end(), [](cNhanVienVP a, cNhanVienVP b){
        return a.getLuong() < b.getLuong();
    });
}