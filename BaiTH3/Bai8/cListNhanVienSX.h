#ifndef CLISTNHANVIENSX_H
#define CLISTNHANVIENSX_H

#include <vector>
#include "cNhanVienSX.h"
using namespace std;

class cListNhanVienSX {
private:
    vector<cNhanVienSX> ds;

public:
    void Nhap();
    void Xuat();

    cNhanVienSX MinLuong();
    double TongLuong();

    cNhanVienSX LonTuoiNhat();

    void SapXepTangLuong();
};

#endif