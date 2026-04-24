#ifndef CNHANVIENVP_H
#define CNHANVIENVP_H

#include <iostream>
#include <string>
using namespace std;

class cNhanVienVP {
private:
    string ma, ten;
    int ngay, thang, nam;
    double luong;

public:
    // constructor
    cNhanVienVP();
    cNhanVienVP(string ma, string ten, int d, int m, int y, double luong);

    // getter
    string getMa();
    string getTen();
    double getLuong();

    int getNamSinh();

    // setter
    void setLuong(double l);

    void Nhap();
    void Xuat();

    int Tuoi();
};

#endif