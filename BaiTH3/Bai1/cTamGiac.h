#ifndef CTAMGIAC_H
#define CTAMGIAC_H

#include "cDiem.h"
#include <string>
using namespace std;

class cTamGiac {
private:
    cDiem A, B, C;

    double DoDai(cDiem P, cDiem Q);

public:
    void Nhap();
    void Xuat();

    double ChuVi();
    double DienTich();
    string LoaiTamGiac();

    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongTo(double k);
    void ThuNho(double k);
};

#endif