#include "CDate.h"
#include <iomanip>
#include <cmath>

/*
    INPUT:
        d: ngày
        m: tháng
        y: năm

    OUTPUT:
        Không có
*/
CDate::CDate(int d, int m, int y) {
    ngay = d;
    thang = m;
    nam = y;
}

/*
    INPUT:
        d: ngày
        m: tháng
        y: năm

    OUTPUT:
        Không có
*/
void CDate::setDate(int d, int m, int y) {
    ngay = d;
    thang = m;
    nam = y;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Ngày
*/
int CDate::getNgay() {
    return ngay;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Tháng
*/
int CDate::getThang() {
    return thang;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Năm
*/
int CDate::getNam() {
    return nam;
}

/*
    INPUT:
        y: năm

    OUTPUT:
        true hoặc false

    Ý tưởng:
        - Năm chia hết cho 400
        hoặc:
        - Chia hết cho 4 nhưng
          không chia hết cho 100
*/
bool CDate::namNhuan(int y) {

    return (y % 400 == 0) ||
           (y % 4 == 0 &&
            y % 100 != 0);
}

/*
    INPUT:
        m: tháng
        y: năm

    OUTPUT:
        Số ngày trong tháng
*/
int CDate::soNgayTrongThang(int m,
                            int y) {

    int ngayThang[] =
    {31,28,31,30,31,30,
     31,31,30,31,30,31};

    if (m == 2 && namNhuan(y))
        return 29;

    return ngayThang[m - 1];
}

/*
    INPUT:
        Không có

    OUTPUT:
        Tổng số ngày

    Ý tưởng:
        - Cộng toàn bộ ngày
          từ năm 1 đến hiện tại.
*/
int CDate::toDays() {

    int tong = 0;

    for (int y = 1; y < nam; y++) {

        if (namNhuan(y))
            tong += 366;
        else
            tong += 365;
    }

    for (int m = 1; m < thang; m++) {
        tong += soNgayTrongThang(m, nam);
    }

    tong += ngay;

    return tong;
}

/*
    INPUT:
        x: số ngày cần cộng

    OUTPUT:
        Ngày mới
*/
CDate CDate::operator+(int x) {

    CDate temp = *this;

    while (x--) {

        temp.ngay++;

        if (temp.ngay >
            temp.soNgayTrongThang(
            temp.thang,
            temp.nam)) {

            temp.ngay = 1;
            temp.thang++;

            if (temp.thang > 12) {
                temp.thang = 1;
                temp.nam++;
            }
        }
    }

    return temp;
}

/*
    INPUT:
        x: số ngày cần trừ

    OUTPUT:
        Ngày mới
*/
CDate CDate::operator-(int x) {

    CDate temp = *this;

    while (x--) {

        temp.ngay--;

        if (temp.ngay < 1) {

            temp.thang--;

            if (temp.thang < 1) {
                temp.thang = 12;
                temp.nam--;
            }

            temp.ngay =
            temp.soNgayTrongThang(
            temp.thang,
            temp.nam);
        }
    }

    return temp;
}

/*
    INPUT:
        other: ngày khác

    OUTPUT:
        Khoảng cách ngày
*/
int CDate::operator-(CDate other) {

    return abs(toDays()
             - other.toDays());
}

/*
    INPUT:
        Không có

    OUTPUT:
        Chính đối tượng hiện tại
*/
CDate& CDate::operator++() {

    *this = *this + 1;

    return *this;
}

/*
    INPUT:
        int giả

    OUTPUT:
        Giá trị cũ
*/
CDate CDate::operator++(int) {

    CDate temp = *this;

    *this = *this + 1;

    return temp;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Chính đối tượng hiện tại
*/
CDate& CDate::operator--() {

    *this = *this - 1;

    return *this;
}

/*
    INPUT:
        int giả

    OUTPUT:
        Giá trị cũ
*/
CDate CDate::operator--(int) {

    CDate temp = *this;

    *this = *this - 1;

    return temp;
}

/*
    INPUT:
        ngày tháng năm

    OUTPUT:
        Đối tượng ngày
*/
std::istream& operator>>(std::istream& in,
                         CDate& d) {

    std::cout << "Nhap ngay: ";
    in >> d.ngay;

    std::cout << "Nhap thang: ";
    in >> d.thang;

    std::cout << "Nhap nam: ";
    in >> d.nam;

    return in;
}

/*
    INPUT:
        d: ngày cần xuất

    OUTPUT:
        dd/mm/yyyy
*/
std::ostream& operator<<(std::ostream& out,
                         CDate d) {

    out << std::setw(2)
        << std::setfill('0')
        << d.ngay << "/";

    out << std::setw(2)
        << std::setfill('0')
        << d.thang << "/";

    out << d.nam;

    return out;
}