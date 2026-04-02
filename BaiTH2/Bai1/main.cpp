#include "NgayThangNam.h"
#include <iostream>
using namespace std;

int main() {
    NgayThangNam dt;
    
    dt.Nhap();
    cout << "Ngay vua nhap: ";
    dt.Xuat();
    
    dt.NgayThangNamTiepTheo();

    return 0;
}
