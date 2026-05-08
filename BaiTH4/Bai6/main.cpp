#include "CVector.h"

int main() {

    CVector v1, v2;

    std::cout << "Nhap vector thu nhat:\n";
    std::cin >> v1;

    std::cout << "\nNhap vector thu hai:\n";
    std::cin >> v2;

    std::cout << "\nVector 1: "
              << v1 << std::endl;

    std::cout << "Vector 2: "
              << v2 << std::endl;

    std::cout << "\nTong hai vector:\n";
    std::cout << v1 + v2 << std::endl;

    std::cout << "\nHieu hai vector:\n";
    std::cout << v1 - v2 << std::endl;

    std::cout << "\nNhan vector voi 2:\n";
    std::cout << v1 * 2 << std::endl;

    std::cout << "\nDo dai vector 1:\n";
    std::cout << v1.doDai()
              << std::endl;

    std::cout << "\nTich vo huong:\n";
    std::cout << v1.tichVoHuong(v2)
              << std::endl;

    return 0;
}