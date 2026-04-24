#ifndef CDATHUC_H
#define CDATHUC_H

#include <vector>
#include <iostream>
using namespace std;

class cDaThuc {
private:
    int bac;
    vector<double> a; // hệ số từ a0 → an

public:
    void Nhap();
    void Xuat();

    double GiaTri(double x);

    cDaThuc Cong(const cDaThuc& dt);
    cDaThuc Tru(const cDaThuc& dt);
};

#endif