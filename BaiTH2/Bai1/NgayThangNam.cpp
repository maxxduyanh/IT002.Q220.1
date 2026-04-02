#include "NgayThangNam.h"
#include <iostream>
using namespace std;

// Tác dụng: Kiểm tra một năm có phải năm nhuận hay không
// Input: Biến nguyên nam
// Output: true nếu là năm nhuận, false nếu ngược lại
bool NgayThangNam::laNamNhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

// Tác dụng: Trả về số ngày tối đa trong một tháng cụ thể
// Input: Biến nguyên thang và nam
// Output: Số ngày (28, 29, 30 hoặc 31)
int NgayThangNam::tinhSoNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return laNamNhuan(nam) ? 29 : 28;
        default:
            return 31;
    }
}

// Tác dụng: Nhập dữ liệu ngày tháng năm từ bàn phím và kiểm tra tính hợp lệ
// Input: Nhập từ bàn phím thông qua cin
// Output: Gán giá trị hợp lệ vào iNgay, iThang, iNam
void NgayThangNam::Nhap() {
    do {
        cout << "Nhap ngay, thang, nam: ";
        cin >> iNgay >> iThang >> iNam;
        if (iThang < 1 || iThang > 12 || iNgay < 1 || iNgay > tinhSoNgayTrongThang(iThang, iNam)) {
            cout << "Du lieu khong hop le. Vui long nhap lai!\n";
        }
    } while (iThang < 1 || iThang > 12 || iNgay < 1 || iNgay > tinhSoNgayTrongThang(iThang, iNam));
}

// Tác dụng: Xuất thông tin ngày tháng năm ra màn hình
// Input: Thuộc tính nội bộ của lớp
// Output: In ra màn hình định dạng dd/mm/yyyy
void NgayThangNam::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

// Tác dụng: Tìm và cập nhật ngày tiếp theo của ngày hiện tại
// Input: Dữ liệu hiện có của đối tượng
// Output: Cập nhật iNgay, iThang, iNam mới và in kết quả
void NgayThangNam::NgayThangNamTiepTheo() {
    int ngayTrongThang = tinhSoNgayTrongThang(iThang, iNam);
    iNgay++;
    if (iNgay > ngayTrongThang) {
        iNgay = 1;
        iThang++;
        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
    cout << "Ngay tiep theo la: ";
    Xuat();
}