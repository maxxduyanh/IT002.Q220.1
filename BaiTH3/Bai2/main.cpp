#include "cDaGiac.h"
#include <iostream>
using namespace std;

int main() {
    cDaGiac dg;

    dg.Nhap();

    cout << "\nDa giac:\n";
    dg.Xuat();

    cout << "Chu vi: " << dg.ChuVi() << endl;
    cout << "Dien tich: " << dg.DienTich() << endl;

    cout << "\nTinh tien (1,1):\n";
    dg.TinhTien(1, 1);
    dg.Xuat();

    cout << "\nQuay 90 do:\n";
    dg.Quay(90);
    dg.Xuat();

    return 0;
}