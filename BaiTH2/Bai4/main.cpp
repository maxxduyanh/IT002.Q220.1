#include "ThoiGian.h"
#include <iostream>

int main() {
    ThoiGian tg;

    std::cout << "--- Nhap thoi gian ---\n";
    tg.Nhap();

    std::cout << "Thoi gian hien tai: ";
    tg.Xuat();

    tg.TinhCongThemMotGiay();

    return 0;
}