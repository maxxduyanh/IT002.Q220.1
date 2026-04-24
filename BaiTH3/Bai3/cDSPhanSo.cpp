#include "cDSPhanSo.h"
#include <algorithm>

// kiểm tra số nguyên tố
bool cDSPhanSo::LaSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Input: n phân số
// Output: danh sách
void cDSPhanSo::Nhap() {
    int n;
    cout << "Nhap so luong: ";
    cin >> n;
    ds.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so " << i+1 << ": ";
        ds[i].Nhap();
    }
}

// Output danh sách
void cDSPhanSo::Xuat() {
    for (auto x : ds) {
        x.Xuat();
        cout << " ";
    }
    cout << endl;
}

// Input: không
// Output: tổng phân số
// Thuật toán: quy đồng cộng
cPhanSo cDSPhanSo::Tong() {
    cPhanSo sum = {0,1};
    for (auto x : ds) {
        sum.tu = sum.tu * x.mau + x.tu * sum.mau;
        sum.mau = sum.mau * x.mau;
    }
    sum.RutGon();
    return sum;
}

// Output: phân số lớn nhất
cPhanSo cDSPhanSo::Max() {
    return *max_element(ds.begin(), ds.end(), [](cPhanSo a, cPhanSo b){
        return a.GiaTri() < b.GiaTri();
    });
}

// Output: phân số nhỏ nhất
cPhanSo cDSPhanSo::Min() {
    return *min_element(ds.begin(), ds.end(), [](cPhanSo a, cPhanSo b){
        return a.GiaTri() < b.GiaTri();
    });
}

// Output: phân số có tử nguyên tố lớn nhất
cPhanSo cDSPhanSo::TuNguyenToMax() {
    cPhanSo res = {0,1};
    int maxTu = -1;

    for (auto x : ds) {
        if (LaSoNguyenTo(abs(x.tu)) && abs(x.tu) > maxTu) {
            maxTu = abs(x.tu);
            res = x;
        }
    }
    return res;
}

// sắp xếp tăng
void cDSPhanSo::SapXepTang() {
    sort(ds.begin(), ds.end(), [](cPhanSo a, cPhanSo b){
        return a.GiaTri() < b.GiaTri();
    });
}

// sắp xếp giảm
void cDSPhanSo::SapXepGiam() {
    sort(ds.begin(), ds.end(), [](cPhanSo a, cPhanSo b){
        return a.GiaTri() > b.GiaTri();
    });
}