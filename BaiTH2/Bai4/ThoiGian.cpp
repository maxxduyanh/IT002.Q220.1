#include "ThoiGian.h"
#include <iostream>
#include <iomanip> // Để dùng hàm setfill, setw cho đẹp
using namespace std;

// Tác dụng: Nhập và kiểm tra tính hợp lệ của thời gian
// Input: Nhập từ bàn phím
// Output: Gán giá trị cho iGio, iPhut, iGiay
void ThoiGian::Nhap() {
    do {
        cout << "Nhap Gio (0-23): "; cin >> iGio;
        cout << "Nhap Phut (0-59): "; cin >> iPhut;
        cout << "Nhap Giay (0-59): "; cin >> iGiay;
        if (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59) {
            cout << "Thoi gian khong hop le! Vui long nhap lai.\n";
        }
    } while (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59);
}

// Tác dụng: Xuất thời gian định dạng hh:mm:ss
// Input: Thuộc tính lớp
// Output: In ra màn hình (VD: 09:05:01)
void ThoiGian::Xuat() {
    // setfill('0') << setw(2) giúp in số 5 thành "05"
    cout << setfill('0') << setw(2) << iGio << ":"
         << setfill('0') << setw(2) << iPhut << ":"
         << setfill('0') << setw(2) << iGiay << endl;
}

// Tác dụng: Cộng thêm 1 giây và xử lý tràn 
// Input: iGio, iPhut, iGiay hiện tại
// Output: Cập nhật giá trị mới
void ThoiGian::TinhCongThemMotGiay() {
    iGiay++;
    if (iGiay >= 60) {
        iGiay = 0;
        iPhut++;
        if (iPhut >= 60) {
            iPhut = 0;
            iGio++;
            if (iGio >= 24) {
                iGio = 0; // Quay về 00:00:00 nếu qua 23:59:59
            }
        }
    }
    cout << "Thoi gian sau khi cong 1 giay: ";
    Xuat();
}