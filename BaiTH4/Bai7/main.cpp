#include "CMatrix.h"

int main() {

    CMatrix A, B;

    std::cout << "Nhap ma tran A:\n";
    std::cin >> A;

    std::cout << "\nNhap ma tran B:\n";
    std::cin >> B;

    std::cout << "\nMa tran A:\n";
    std::cout << A << std::endl;

    std::cout << "\nMa tran B:\n";
    std::cout << B << std::endl;

    std::cout << "\nTong hai ma tran:\n";
    std::cout << A + B << std::endl;

    std::cout << "\nHieu hai ma tran:\n";
    std::cout << A - B << std::endl;

    std::cout << "\nTich hai ma tran:\n";
    std::cout << A * B << std::endl;

    CVector v;

    std::cout << "\nNhap vector:\n";
    std::cin >> v;

    std::cout << "\nVector:\n";
    std::cout << v << std::endl;

    std::cout << "\nTich ma tran A va vector:\n";
    std::cout << A * v << std::endl;

    return 0;
}