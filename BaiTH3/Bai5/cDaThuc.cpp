#include "cDaThuc.h"

// Input: bậc và các hệ số
// Output: đa thức
// Thuật toán:
// 1. Nhập bậc n
// 2. Nhập n+1 hệ số
void cDaThuc::Nhap() {
    cout << "Nhap bac: ";
    cin >> bac;

    a.resize(bac + 1);
    for (int i = 0; i <= bac; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

// Output: in đa thức
// Thuật toán: in từ bậc cao → thấp
void cDaThuc::Xuat() {
    for (int i = bac; i >= 0; i--) {
        cout << a[i];
        if (i > 0) cout << "x^" << i << " + ";
    }
    cout << endl;
}

// Input: x
// Output: giá trị P(x)
// Thuật toán: tính tổng a[i]*x^i
double cDaThuc::GiaTri(double x) {
    double res = 0;
    double pow_x = 1;

    for (int i = 0; i <= bac; i++) {
        res += a[i] * pow_x;
        pow_x *= x;
    }
    return res;
}

// Input: đa thức dt
// Output: tổng 2 đa thức
// Thuật toán:
// 1. Lấy max bậc
// 2. Cộng từng hệ số
cDaThuc cDaThuc::Cong(const cDaThuc& dt) {
    cDaThuc kq;
    kq.bac = max(bac, dt.bac);
    kq.a.resize(kq.bac + 1, 0);

    for (int i = 0; i <= kq.bac; i++) {
        double x = (i <= bac ? a[i] : 0);
        double y = (i <= dt.bac ? dt.a[i] : 0);
        kq.a[i] = x + y;
    }
    return kq;
}

// Input: đa thức dt
// Output: hiệu 2 đa thức
// Thuật toán: tương tự cộng nhưng trừ
cDaThuc cDaThuc::Tru(const cDaThuc& dt) {
    cDaThuc kq;
    kq.bac = max(bac, dt.bac);
    kq.a.resize(kq.bac + 1, 0);

    for (int i = 0; i <= kq.bac; i++) {
        double x = (i <= bac ? a[i] : 0);
        double y = (i <= dt.bac ? dt.a[i] : 0);
        kq.a[i] = x - y;
    }
    return kq;
}