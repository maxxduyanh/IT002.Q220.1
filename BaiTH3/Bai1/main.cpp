#include "cTamGiac.h"
#include <iostream>
using namespace std;

int main() {
    cTamGiac tg;

    tg.Nhap();

    cout << "\nTam giac:\n";
    tg.Xuat();

    cout << "Chu vi: " << tg.ChuVi() << endl;
    cout << "Dien tich: " << tg.DienTich() << endl;
    cout << "Loai: " << tg.LoaiTamGiac() << endl;

    cout << "\nTinh tien (1,1):\n";
    tg.TinhTien(1, 1);
    tg.Xuat();

    cout << "\nQuay 90 do:\n";
    tg.Quay(90);
    tg.Xuat();

    return 0;
}