#ifndef CTIME_H
#define CTIME_H

#include <iostream>
using namespace std;

class CTime {
private:
    int gio;
    int phut;
    int giay;

public:

    /*
        INPUT:
            h: giờ
            p: phút
            s: giây

        OUTPUT:
            Không có

        Ý tưởng:
            - Khởi tạo thời gian.
            - Chuẩn hóa thời gian.
    */
    CTime(int h = 0, int p = 0, int s = 0);

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
    void setTime(int h, int p, int s);

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị giờ

        Ý tưởng:
            - Trả về giờ.
    */
    int getGio();

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị phút

        Ý tưởng:
            - Trả về phút.
    */
    int getPhut();

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị giây

        Ý tưởng:
            - Trả về giây.
    */
    int getGiay();

    /*
        INPUT:
            Không có

        OUTPUT:
            Không có

        Ý tưởng:
            - Đưa thời gian về dạng hợp lệ:
                0 <= giây < 60
                0 <= phút < 60
                0 <= giờ < 24
    */
    void chuanHoa();

    /*
        INPUT:
            x: số giây cần cộng

        OUTPUT:
            Đối tượng thời gian mới

        Ý tưởng:
            - Đổi toàn bộ sang giây.
            - Cộng thêm x giây.
            - Chuyển ngược về giờ phút giây.
    */
    CTime operator+(int x);

    /*
        INPUT:
            x: số giây cần trừ

        OUTPUT:
            Đối tượng thời gian mới

        Ý tưởng:
            - Đổi toàn bộ sang giây.
            - Trừ đi x giây.
            - Chuyển ngược về giờ phút giây.
    */
    CTime operator-(int x);

    /*
        INPUT:
            Không có

        OUTPUT:
            Thời gian sau khi tăng 1 giây

        Ý tưởng:
            - Tăng giây rồi chuẩn hóa.
    */
    CTime& operator++();

    /*
        INPUT:
            int giả

        OUTPUT:
            Giá trị cũ trước khi tăng

        Ý tưởng:
            - Lưu bản sao cũ.
            - Tăng 1 giây.
            - Trả về giá trị cũ.
    */
    CTime operator++(int);

    /*
        INPUT:
            Không có

        OUTPUT:
            Thời gian sau khi giảm 1 giây

        Ý tưởng:
            - Giảm giây rồi chuẩn hóa.
    */
    CTime& operator--();

    /*
        INPUT:
            int giả

        OUTPUT:
            Giá trị cũ trước khi giảm

        Ý tưởng:
            - Lưu bản sao cũ.
            - Giảm 1 giây.
            - Trả về giá trị cũ.
    */
    CTime operator--(int);

    /*
        INPUT:
            Bàn phím:
            giờ phút giây

        OUTPUT:
            Đối tượng thời gian

        Ý tưởng:
            - Nhập dữ liệu cho thời gian.
            - Chuẩn hóa dữ liệu.
    */
    friend istream& operator>>(istream& in,
                               CTime& t);

    /*
        INPUT:
            t: thời gian cần xuất

        OUTPUT:
            Dạng hh:mm:ss

        Ý tưởng:
            - Xuất đúng định dạng đồng hồ.
    */
    friend ostream& operator<<(ostream& out,
                               CTime t);
};

#endif