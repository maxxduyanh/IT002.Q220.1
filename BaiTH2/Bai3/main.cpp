#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main() {
    SoPhuc sp1, sp2;
    
    cout << "Nhap so phuc thu nhat:\n";
    sp1.Nhap();
    cout << "Nhap so phuc thu hai:\n";
    sp2.Nhap();

    cout << "\nKet qua cac phep tinh:\n";
    
    cout << "Tong: "; sp1.Tong(sp2).Xuat();
    cout << "Hieu: "; sp1.Hieu(sp2).Xuat();
    cout << "Tich: "; sp1.Tich(sp2).Xuat();
    cout << "Thuong: "; sp1.Thuong(sp2).Xuat();

    return 0;
}