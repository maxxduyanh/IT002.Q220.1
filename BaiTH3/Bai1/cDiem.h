#ifndef CDIEM_H
#define CDIEM_H

#include <iostream>
#include <cmath>
using namespace std;

class cDiem {
public:
    double x, y;

    // Nhập tọa độ điểm
    void Nhap();

    // Xuất tọa độ điểm
    void Xuat();

    // Tịnh tiến điểm
    void TinhTien(double dx, double dy);

    // Quay điểm quanh gốc O
    void Quay(double goc);

    // Phóng to điểm
    void PhongTo(double k);

    // Thu nhỏ điểm
    void ThuNho(double k);
};

#endif