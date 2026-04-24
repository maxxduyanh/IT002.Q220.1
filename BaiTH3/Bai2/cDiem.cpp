#include "cDiem.h"

// Input: nhập x, y từ bàn phím
// Output: cập nhật tọa độ điểm
// Thuật toán: đọc 2 số thực gán cho x, y
void cDiem::Nhap() {
    cin >> x >> y;
}

// Input: không
// Output: in ra tọa độ (x, y)
// Thuật toán: xuất trực tiếp x, y
void cDiem::Xuat() {
    cout << "(" << x << ", " << y << ")";
}

// Input: dx, dy (độ dời)
// Output: điểm mới sau khi tịnh tiến
// Thuật toán: x = x + dx, y = y + dy
void cDiem::TinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}

// Input: góc quay (độ)
// Output: điểm mới sau khi quay
// Thuật toán:
// 1. Đổi góc sang radian
// 2. Áp dụng công thức quay:
//    x' = x*cos - y*sin
//    y' = x*sin + y*cos
void cDiem::Quay(double goc) {
    double rad = goc * M_PI / 180;
    double x_new = x * cos(rad) - y * sin(rad);
    double y_new = x * sin(rad) + y * cos(rad);
    x = x_new;
    y = y_new;
}

// Input: hệ số k
// Output: điểm được phóng to
// Thuật toán: nhân x, y với k
void cDiem::PhongTo(double k) {
    x *= k;
    y *= k;
}

// Input: hệ số k
// Output: điểm được thu nhỏ
// Thuật toán: chia x, y cho k
void cDiem::ThuNho(double k) {
    x /= k;
    y /= k;
}