#ifndef CDSPHANSO_H
#define CDSPHANSO_H

#include <vector>
#include "cPhanSo.h"
using namespace std;

class cDSPhanSo {
private:
    vector<cPhanSo> ds;

    bool LaSoNguyenTo(int n);

public:
    void Nhap();
    void Xuat();

    cPhanSo Tong();
    cPhanSo Max();
    cPhanSo Min();

    cPhanSo TuNguyenToMax();

    void SapXepTang();
    void SapXepGiam();
};

#endif