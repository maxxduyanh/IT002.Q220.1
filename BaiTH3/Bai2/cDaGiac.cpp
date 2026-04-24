#include "cDaGiac.h"
#include <cmath>

// Input: 2 điểm A, B
// Output: độ dài AB
// Thuật toán: sqrt((x1-x2)^2 + (y1-y2)^2)
double cDaGiac::DoDai(cDiem A, cDiem B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

// Input: số đỉnh n và n điểm
// Output: danh sách đỉnh đa giác
// Thuật toán:
// 1. Nhập n
// 2. Cấp phát vector n phần tử
// 3. Nhập từng điểm
void cDaGiac::Nhap() {
    cout << "Nhap so dinh: ";
    cin >> n;
    ds.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "Nhap diem " << i + 1 << ": ";
        ds[i].Nhap();
    }
}

// Input: không
// Output: in ra các đỉnh
// Thuật toán: duyệt vector và gọi Xuat()
void cDaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
        cout << " ";
    }
    cout << endl;
}

// Input: không
// Output: chu vi đa giác
// Thuật toán:
// 1. Duyệt các cạnh liên tiếp
// 2. Cộng độ dài cạnh i → i+1
// 3. Cạnh cuối nối về đỉnh đầu (% n)
double cDaGiac::ChuVi() {
    double cv = 0;
    for (int i = 0; i < n; i++) {
        cv += DoDai(ds[i], ds[(i + 1) % n]);
    }
    return cv;
}

// Input: không
// Output: diện tích đa giác
// Thuật toán (Shoelace):
// S = 1/2 * |Σ(x_i*y_{i+1} - x_{i+1}*y_i)|
double cDaGiac::DienTich() {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += ds[i].x * ds[(i + 1) % n].y
           - ds[(i + 1) % n].x * ds[i].y;
    }
    return abs(s) / 2;
}

// Input: dx, dy
// Output: đa giác mới
// Thuật toán: tịnh tiến từng đỉnh
void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++)
        ds[i].TinhTien(dx, dy);
}

// Input: góc quay
// Output: đa giác sau khi quay
// Thuật toán: quay từng điểm
void cDaGiac::Quay(double goc) {
    for (int i = 0; i < n; i++)
        ds[i].Quay(goc);
}

// Input: k
// Output: đa giác phóng to
// Thuật toán: nhân từng điểm với k
void cDaGiac::PhongTo(double k) {
    for (int i = 0; i < n; i++)
        ds[i].PhongTo(k);
}

// Input: k
// Output: đa giác thu nhỏ
// Thuật toán: chia từng điểm cho k
void cDaGiac::ThuNho(double k) {
    for (int i = 0; i < n; i++)
        ds[i].ThuNho(k);
}