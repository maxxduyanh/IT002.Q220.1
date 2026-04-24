#include "cListNhanVienSX.h"
#include <iostream>
using namespace std;

int main() {
    cListNhanVienSX list;

    list.Nhap();

    cout << "\nDanh sach:\n";
    list.Xuat();

    cout << "\nLuong thap nhat:\n";
    list.MinLuong().Xuat();

    cout << "\nTong luong: " << list.TongLuong() << endl;

    cout << "\nNhan vien lon tuoi nhat:\n";
    list.LonTuoiNhat().Xuat();

    cout << "\nSap xep tang luong:\n";
    list.SapXepTangLuong();
    list.Xuat();

    return 0;
}