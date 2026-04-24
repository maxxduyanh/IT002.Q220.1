#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <iostream>
#include <string>
using namespace std;

class cNhanVienSX {
private:
    string ma, ten;
    int ngay, thang, nam;
    int soSP;
    double donGia;

public:
    cNhanVienSX();
    cNhanVienSX(string, string, int, int, int, int, double);

    double getLuong();
    int Tuoi();

    void Nhap();
    void Xuat();
};

#endif