#include "DaThuc.h"

int main() {

    DaThuc dt1, dt2;

    std::cout << "Nhap da thuc thu nhat:\n";
    std::cin >> dt1;

    std::cout << "\nNhap da thuc thu hai:\n";
    std::cin >> dt2;

    std::cout << "\nDa thuc 1:\n";
    std::cout << dt1 << std::endl;

    std::cout << "\nDa thuc 2:\n";
    std::cout << dt2 << std::endl;

    std::cout << "\nTong hai da thuc:\n";
    std::cout << dt1 + dt2 << std::endl;

    std::cout << "\nHieu hai da thuc:\n";
    std::cout << dt1 - dt2 << std::endl;

    std::cout << "\nTich hai da thuc:\n";
    std::cout << dt1 * dt2 << std::endl;

    float x;

    std::cout << "\nNhap gia tri x: ";
    std::cin >> x;

    std::cout << "\nGia tri da thuc 1 tai x = "
              << x << " la: ";

    std::cout << dt1.tinhGiaTri(x)
              << std::endl;

    return 0;
}