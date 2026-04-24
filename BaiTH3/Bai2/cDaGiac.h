#ifndef CDAGIAC_H
#define CDAGIAC_H

#include <vector>
#include <iostream>
#include "cDiem.h"
using namespace std;

class cDaGiac {
private:
    int n;
    vector<cDiem> ds;

    double DoDai(cDiem A, cDiem B);

public:
    void Nhap();
    void Xuat();

    double ChuVi();
    double DienTich();

    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongTo(double k);
    void ThuNho(double k);
};

#endif