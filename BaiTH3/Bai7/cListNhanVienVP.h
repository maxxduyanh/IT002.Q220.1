#ifndef CLISTNHANVIENVP_H
#define CLISTNHANVIENVP_H

#include <vector>
#include "cNhanVienVP.h"
using namespace std;

class cListNhanVienVP {
private:
    vector<cNhanVienVP> ds;

public:
    void Nhap();
    void Xuat();

    cNhanVienVP MaxLuong();
    double TongLuong();

    cNhanVienVP LonTuoiNhat();

    void SapXepTangLuong();
};

#endif