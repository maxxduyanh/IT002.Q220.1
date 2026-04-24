#include "cTamGiac.h"

// Input: 2 điểm P, Q
// Output: độ dài đoạn PQ
// Thuật toán: sqrt((x1-x2)^2 + (y1-y2)^2)
double cTamGiac::DoDai(cDiem P, cDiem Q) {
    return sqrt(pow(P.x - Q.x, 2) + pow(P.y - Q.y, 2));
}

// Input: nhập 3 điểm A, B, C
// Output: cập nhật tam giác
// Thuật toán: gọi Nhap() của từng điểm
void cTamGiac::Nhap() {
    cout << "Nhap A: "; A.Nhap();
    cout << "Nhap B: "; B.Nhap();
    cout << "Nhap C: "; C.Nhap();
}

// Input: không
// Output: in ra 3 điểm
// Thuật toán: gọi Xuat() của từng điểm
void cTamGiac::Xuat() {
    cout << "A"; A.Xuat();
    cout << " B"; B.Xuat();
    cout << " C"; C.Xuat();
    cout << endl;
}

// Input: không
// Output: chu vi tam giác
// Thuật toán: tính tổng 3 cạnh
double cTamGiac::ChuVi() {
    return DoDai(A, B) + DoDai(B, C) + DoDai(C, A);
}

// Input: không
// Output: diện tích tam giác
// Thuật toán:
// 1. Tính 3 cạnh a, b, c
// 2. Tính nửa chu vi p
// 3. Áp dụng công thức Heron
double cTamGiac::DienTich() {
    double a = DoDai(B, C);
    double b = DoDai(A, C);
    double c = DoDai(A, B);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Input: không
// Output: loại tam giác
// Thuật toán:
// 1. Tính 3 cạnh
// 2. Sắp xếp tăng dần
// 3. So sánh:
//    - a=b=c → đều
//    - 1 cặp bằng nhau → cân
//    - a^2 + b^2 = c^2 → vuông
string cTamGiac::LoaiTamGiac() {
    double a = DoDai(B, C);
    double b = DoDai(A, C);
    double c = DoDai(A, B);

    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

    if (abs(a - b) < 1e-6 && abs(b - c) < 1e-6)
        return "Tam giac deu";

    if (abs(a - b) < 1e-6 || abs(b - c) < 1e-6 || abs(a - c) < 1e-6)
        return "Tam giac can";

    if (abs(a*a + b*b - c*c) < 1e-6)
        return "Tam giac vuong";

    return "Tam giac thuong";
}

// Input: dx, dy
// Output: tam giác mới
// Thuật toán: tịnh tiến từng điểm
void cTamGiac::TinhTien(double dx, double dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

// Input: góc quay
// Output: tam giác mới
// Thuật toán: quay từng điểm
void cTamGiac::Quay(double goc) {
    A.Quay(goc);
    B.Quay(goc);
    C.Quay(goc);
}

// Input: k
// Output: tam giác phóng to
// Thuật toán: nhân từng điểm với k
void cTamGiac::PhongTo(double k) {
    A.PhongTo(k);
    B.PhongTo(k);
    C.PhongTo(k);
}

// Input: k
// Output: tam giác thu nhỏ
// Thuật toán: chia từng điểm cho k
void cTamGiac::ThuNho(double k) {
    A.ThuNho(k);
    B.ThuNho(k);
    C.ThuNho(k);
}