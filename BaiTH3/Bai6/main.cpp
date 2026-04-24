#include "cListCandidate.h"
#include <iostream>
using namespace std;

int main() {
    cListCandidate list;

    list.Nhap();

    cout << "\nThi sinh co tong diem > 15:\n";
    list.XuatLonHon15();

    cout << "\nThi sinh diem cao nhat:\n";
    list.Max().Xuat();

    cout << "\nSap xep giam dan:\n";
    list.SapXepGiam();
    list.XuatLonHon15(); // có thể in toàn bộ nếu muốn

    return 0;
}