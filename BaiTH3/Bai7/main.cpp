#include "cListNhanVienVP.h"
#include <iostream>
using namespace std;

int main() {
    cListNhanVienVP list;

    list.Nhap();

    cout << "\nDanh sach:\n";
    list.Xuat();

    cout << "\nLuong cao nhat:\n";
    list.MaxLuong().Xuat();

    cout << "\nTong luong: " << list.TongLuong() << endl;

    cout << "\nNhan vien lon tuoi nhat:\n";
    list.LonTuoiNhat().Xuat();

    cout << "\nSap xep tang luong:\n";
    list.SapXepTangLuong();
    list.Xuat();

    return 0;
}