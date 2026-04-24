#include "cListNhanVienSX.h"
#include <algorithm>

// nhập danh sách
void cListNhanVienSX::Nhap() {
    int n;
    cout << "Nhap so NV: ";
    cin >> n;
    ds.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "\nNV " << i+1 << ":\n";
        ds[i].Nhap();
    }
}

// xuất
void cListNhanVienSX::Xuat() {
    for (auto x : ds)
        x.Xuat();
}

// lương thấp nhất
cNhanVienSX cListNhanVienSX::MinLuong() {
    return *min_element(ds.begin(), ds.end(), [](cNhanVienSX a, cNhanVienSX b){
        return a.getLuong() < b.getLuong();
    });
}

// tổng lương
double cListNhanVienSX::TongLuong() {
    double sum = 0;
    for (auto x : ds)
        sum += x.getLuong();
    return sum;
}

// lớn tuổi nhất
cNhanVienSX cListNhanVienSX::LonTuoiNhat() {
    return *max_element(ds.begin(), ds.end(), [](cNhanVienSX a, cNhanVienSX b){
        return a.Tuoi() < b.Tuoi();
    });
}

// sắp xếp tăng lương
void cListNhanVienSX::SapXepTangLuong() {
    sort(ds.begin(), ds.end(), [](cNhanVienSX a, cNhanVienSX b){
        return a.getLuong() < b.getLuong();
    });
}