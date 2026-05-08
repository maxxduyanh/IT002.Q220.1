#include "CTime.h"
#include <iomanip>

/*
    INPUT:
        h: giờ
        p: phút
        s: giây

    OUTPUT:
        Không có

    Ý tưởng:
        - Khởi tạo thời gian.
        - Chuẩn hóa dữ liệu.
*/
CTime::CTime(int h, int p, int s) {

    gio = h;
    phut = p;
    giay = s;

    chuanHoa();
}

/*
    INPUT:
        h: giờ
        p: phút
        s: giây

    OUTPUT:
        Không có

    Ý tưởng:
        - Gán lại thời gian mới.
        - Chuẩn hóa dữ liệu.
*/
void CTime::setTime(int h, int p, int s) {

    gio = h;
    phut = p;
    giay = s;

    chuanHoa();
}

/*
    INPUT:
        Không có

    OUTPUT:
        Giá trị giờ
*/
int CTime::getGio() {
    return gio;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Giá trị phút
*/
int CTime::getPhut() {
    return phut;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Giá trị giây
*/
int CTime::getGiay() {
    return giay;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Không có

    Ý tưởng:
        - Chuyển toàn bộ sang giây.
        - Đưa về khoảng 1 ngày.
        - Chuyển lại sang giờ phút giây.
*/
void CTime::chuanHoa() {

    int tongGiay = gio * 3600
                 + phut * 60
                 + giay;

    tongGiay = (tongGiay % 86400 + 86400)
             % 86400;

    gio = tongGiay / 3600;

    tongGiay %= 3600;

    phut = tongGiay / 60;

    giay = tongGiay % 60;
}

/*
    INPUT:
        x: số giây cần cộng

    OUTPUT:
        Thời gian mới

    Ý tưởng:
        - Cộng thêm giây.
*/
CTime CTime::operator+(int x) {

    CTime temp(gio, phut, giay);

    temp.giay += x;

    temp.chuanHoa();

    return temp;
}

/*
    INPUT:
        x: số giây cần trừ

    OUTPUT:
        Thời gian mới

    Ý tưởng:
        - Trừ giây.
*/
CTime CTime::operator-(int x) {

    CTime temp(gio, phut, giay);

    temp.giay -= x;

    temp.chuanHoa();

    return temp;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Chính đối tượng hiện tại

    Ý tưởng:
        - Tăng 1 giây.
*/
CTime& CTime::operator++() {

    giay++;

    chuanHoa();

    return *this;
}

/*
    INPUT:
        int giả

    OUTPUT:
        Giá trị cũ

    Ý tưởng:
        - Lưu giá trị cũ.
        - Tăng 1 giây.
*/
CTime CTime::operator++(int) {

    CTime temp = *this;

    giay++;

    chuanHoa();

    return temp;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Chính đối tượng hiện tại

    Ý tưởng:
        - Giảm 1 giây.
*/
CTime& CTime::operator--() {

    giay--;

    chuanHoa();

    return *this;
}

/*
    INPUT:
        int giả

    OUTPUT:
        Giá trị cũ

    Ý tưởng:
        - Lưu giá trị cũ.
        - Giảm 1 giây.
*/
CTime CTime::operator--(int) {

    CTime temp = *this;

    giay--;

    chuanHoa();

    return temp;
}

/*
    INPUT:
        Bàn phím:
        giờ phút giây

    OUTPUT:
        Đối tượng thời gian
*/
istream& operator>>(istream& in,
                    CTime& t) {

    cout << "Nhap gio: ";
    in >> t.gio;

    cout << "Nhap phut: ";
    in >> t.phut;

    cout << "Nhap giay: ";
    in >> t.giay;

    t.chuanHoa();

    return in;
}

/*
    INPUT:
        t: thời gian cần xuất

    OUTPUT:
        Dạng hh:mm:ss

    Ý tưởng:
        - Thêm số 0 phía trước nếu cần.
*/
ostream& operator<<(ostream& out,
                    CTime t) {

    out << setw(2) << setfill('0')
        << t.gio << ":";

    out << setw(2) << setfill('0')
        << t.phut << ":";

    out << setw(2) << setfill('0')
        << t.giay;

    return out;
}