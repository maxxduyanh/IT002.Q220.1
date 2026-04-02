#pragma once
#include <iostream>

class SoPhuc {
private:
    double iThuc;
    double iAo;

public:
    void Nhap();
    void Xuat();
    
    SoPhuc Tong(SoPhuc b);
    SoPhuc Hieu(SoPhuc b);
    SoPhuc Tich(SoPhuc b);
    SoPhuc Thuong(SoPhuc b);
};