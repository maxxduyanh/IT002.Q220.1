#include "SoPhuc.h"
#include <iostream>
#include <cmath>
using namespace std;

void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: "; cin >> iThuc;
    cout << "Nhap phan ao: "; cin >> iAo;
}

void SoPhuc::Xuat() {
    if (iAo >= 0)
        cout << iThuc << " + " << iAo << "i";
    else
        cout << iThuc << " - " << abs(iAo) << "i";
    cout << endl;
}

// Tác dụng: Cộng hai số phức
// Output: (a + c) + (b + d)i
SoPhuc SoPhuc::Tong(SoPhuc b) {
    SoPhuc res;
    res.iThuc = this->iThuc + b.iThuc;
    res.iAo = this->iAo + b.iAo;
    return res;
}

// Tác dụng: Trừ hai số phức
// Output: (a - c) + (b - d)i
SoPhuc SoPhuc::Hieu(SoPhuc b) {
    SoPhuc res;
    res.iThuc = this->iThuc - b.iThuc;
    res.iAo = this->iAo - b.iAo;
    return res;
}

// Tác dụng: Nhân hai số phức
// Output: (ac - bd) + (ad + bc)i
SoPhuc SoPhuc::Tich(SoPhuc b) {
    SoPhuc res;
    res.iThuc = this->iThuc * b.iThuc - this->iAo * b.iAo;
    res.iAo = this->iThuc * b.iAo + this->iAo * b.iThuc;
    return res;
}

// Tác dụng: Chia hai số phức
// Công thức: Nhân tử và mẫu cho số phức liên hợp của mẫu
SoPhuc SoPhuc::Thuong(SoPhuc b) {
    SoPhuc res;
    double mauSo = b.iThuc * b.iThuc + b.iAo * b.iAo;
    if (mauSo == 0) {
        cout << "Loi: Khong the chia cho 0!" << endl;
        res.iThuc = 0; res.iAo = 0;
        return res;
    }
    res.iThuc = (this->iThuc * b.iThuc + this->iAo * b.iAo) / mauSo;
    res.iAo = (this->iAo * b.iThuc - this->iThuc * b.iAo) / mauSo;
    return res;
}