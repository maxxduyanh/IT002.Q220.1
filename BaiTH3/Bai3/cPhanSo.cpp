#include "cPhanSo.h"
#include <cmath>

// Input: tử và mẫu
// Output: phân số
// Thuật toán: nhập 2 số nguyên
void cPhanSo::Nhap() {
    cin >> tu >> mau;
}

// Input: không
// Output: in dạng a/b
void cPhanSo::Xuat() {
    cout << tu << "/" << mau;
}

// Input: không
// Output: phân số tối giản
// Thuật toán: chia tử và mẫu cho gcd
void cPhanSo::RutGon() {
    int a = abs(tu), b = abs(mau);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    tu /= a;
    mau /= a;
}

// Input: không
// Output: giá trị thực
// Thuật toán: ép kiểu double
double cPhanSo::GiaTri() {
    return (double)tu / mau;
}