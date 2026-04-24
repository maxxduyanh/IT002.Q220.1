#ifndef CCANDIDATE_H
#define CCANDIDATE_H

#include <iostream>
#include <string>
using namespace std;

class cCandidate {
private:
    string ma, ten;
    int ngay, thang, nam;
    double toan, van, anh;

public:
    void Nhap();
    void Xuat();

    double TongDiem();
};

#endif