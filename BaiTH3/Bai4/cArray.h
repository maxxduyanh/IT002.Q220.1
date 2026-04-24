#ifndef CARRAY_H
#define CARRAY_H

#include <vector>
#include <iostream>
using namespace std;

class cArray {
private:
    int n;
    vector<int> a;

    bool LaSoNguyenTo(int x);

public:
    void TaoNgauNhien(int n);
    void Xuat();

    int Dem(int x);
    bool KiemTraTang();

    int LeNhoNhat();
    int NguyenToMax();

    void SapXepTang();
    void SapXepGiam();
};

#endif