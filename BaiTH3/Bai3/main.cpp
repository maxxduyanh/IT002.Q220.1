#include "cDSPhanSo.h"
#include <iostream>
using namespace std;

int main() {
    cDSPhanSo ds;

    ds.Nhap();

    cout << "\nDanh sach:\n";
    ds.Xuat();

    cout << "Tong: ";
    ds.Tong().Xuat(); cout << endl;

    cout << "Max: ";
    ds.Max().Xuat(); cout << endl;

    cout << "Min: ";
    ds.Min().Xuat(); cout << endl;

    cout << "Tu nguyen to max: ";
    ds.TuNguyenToMax().Xuat(); cout << endl;

    cout << "\nSap xep tang:\n";
    ds.SapXepTang();
    ds.Xuat();

    cout << "\nSap xep giam:\n";
    ds.SapXepGiam();
    ds.Xuat();

    return 0;
}