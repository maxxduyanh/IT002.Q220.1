#include "cArray.h"
#include <iostream>
using namespace std;

int main() {
    cArray arr;
    int x;

    arr.TaoNgauNhien(10);

    cout << "Mang:\n";
    arr.Xuat();

    // 🔹 nhập giá trị x từ bàn phím
    cout << "Nhap gia tri x can dem: ";
    cin >> x;

    cout << "So lan xuat hien cua " << x << ": " << arr.Dem(x) << endl;

    cout << "Tang dan? " << (arr.KiemTraTang() ? "Co" : "Khong") << endl;

    cout << "Le nho nhat: " << arr.LeNhoNhat() << endl;
    cout << "Nguyen to max: " << arr.NguyenToMax() << endl;

    cout << "\nSap xep tang:\n";
    arr.SapXepTang();
    arr.Xuat();

    cout << "\nSap xep giam:\n";
    arr.SapXepGiam();
    arr.Xuat();

    return 0;
}