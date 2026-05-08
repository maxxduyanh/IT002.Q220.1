#include "CDate.h"

int main() {

    CDate d1, d2;

    std::cout << "Nhap ngay thu nhat:\n";
    std::cin >> d1;

    std::cout << "\nNhap ngay thu hai:\n";
    std::cin >> d2;

    std::cout << "\nNgay thu nhat: "
              << d1 << std::endl;

    std::cout << "Ngay thu hai: "
              << d2 << std::endl;

    std::cout << "\nCong 10 ngay:\n";
    std::cout << d1 + 10 << std::endl;

    std::cout << "\nTru 5 ngay:\n";
    std::cout << d1 - 5 << std::endl;

    std::cout << "\nPrefix ++:\n";
    ++d1;
    std::cout << d1 << std::endl;

    std::cout << "\nPostfix ++:\n";
    d1++;
    std::cout << d1 << std::endl;

    std::cout << "\nPrefix --:\n";
    --d1;
    std::cout << d1 << std::endl;

    std::cout << "\nPostfix --:\n";
    d1--;
    std::cout << d1 << std::endl;

    std::cout << "\nKhoang cach giua 2 ngay: ";

    std::cout << d1 - d2
              << " ngay\n";

    /*
        Ứng dụng tính lãi suất ngân hàng

        Công thức:
            tienLai =
            tienGui * laiSuat * soNgay
            / 365
    */

    double tienGui;
    double laiSuat;

    std::cout << "\n===== TINH LAI NGAN HANG =====\n";

    std::cout << "Nhap so tien gui: ";
    std::cin >> tienGui;

    std::cout << "Nhap lai suat nam (%): ";
    std::cin >> laiSuat;

    int soNgay = d2 - d1;

    double tienLai =
        tienGui *
        (laiSuat / 100) *
        soNgay / 365;

    std::cout << "\nSo ngay gui: "
              << soNgay << std::endl;

    std::cout << "Tien lai: "
              << tienLai << std::endl;

    return 0;
}