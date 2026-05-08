#ifndef CDATE_H
#define CDATE_H

#include <iostream>

class CDate {
private:
    int ngay;
    int thang;
    int nam;

public:

    /*
        INPUT:
            d: ngày
            m: tháng
            y: năm

        OUTPUT:
            Không có

        Ý tưởng:
            - Khởi tạo ngày tháng năm.
    */
    CDate(int d = 1, int m = 1, int y = 2000);

    /*
        INPUT:
            d: ngày
            m: tháng
            y: năm

        OUTPUT:
            Không có

        Ý tưởng:
            - Gán lại ngày tháng năm.
    */
    void setDate(int d, int m, int y);

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị ngày
    */
    int getNgay();

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị tháng
    */
    int getThang();

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị năm
    */
    int getNam();

    /*
        INPUT:
            y: năm cần kiểm tra

        OUTPUT:
            true nếu năm nhuận
            false nếu không

        Ý tưởng:
            - Kiểm tra quy tắc năm nhuận.
    */
    bool namNhuan(int y);

    /*
        INPUT:
            m: tháng
            y: năm

        OUTPUT:
            Số ngày trong tháng

        Ý tưởng:
            - Xét tháng đặc biệt.
            - Tháng 2 kiểm tra năm nhuận.
    */
    int soNgayTrongThang(int m, int y);

    /*
        INPUT:
            Không có

        OUTPUT:
            Tổng số ngày tính từ mốc 1/1/1

        Ý tưởng:
            - Cộng tất cả số ngày
              của các năm và tháng trước.
    */
    int toDays();

    /*
        INPUT:
            x: số ngày cần cộng

        OUTPUT:
            Ngày mới

        Ý tưởng:
            - Tăng ngày từng bước.
    */
    CDate operator+(int x);

    /*
        INPUT:
            x: số ngày cần trừ

        OUTPUT:
            Ngày mới

        Ý tưởng:
            - Giảm ngày từng bước.
    */
    CDate operator-(int x);

    /*
        INPUT:
            other: ngày khác

        OUTPUT:
            Khoảng cách ngày

        Ý tưởng:
            - Đổi cả hai về tổng số ngày.
            - Lấy hiệu.
    */
    int operator-(CDate other);

    /*
        INPUT:
            Không có

        OUTPUT:
            Ngày sau khi tăng 1

        Ý tưởng:
            - Tăng thêm 1 ngày.
    */
    CDate& operator++();

    /*
        INPUT:
            int giả

        OUTPUT:
            Giá trị cũ

        Ý tưởng:
            - Lưu bản sao.
            - Tăng 1 ngày.
    */
    CDate operator++(int);

    /*
        INPUT:
            Không có

        OUTPUT:
            Ngày sau khi giảm 1

        Ý tưởng:
            - Giảm 1 ngày.
    */
    CDate& operator--();

    /*
        INPUT:
            int giả

        OUTPUT:
            Giá trị cũ

        Ý tưởng:
            - Lưu bản sao.
            - Giảm 1 ngày.
    */
    CDate operator--(int);

    /*
        INPUT:
            Bàn phím:
            ngày tháng năm

        OUTPUT:
            Đối tượng ngày

        Ý tưởng:
            - Nhập dữ liệu ngày tháng năm.
    */
    friend std::istream& operator>>(std::istream& in,
                                    CDate& d);

    /*
        INPUT:
            d: ngày cần xuất

        OUTPUT:
            Dạng dd/mm/yyyy

        Ý tưởng:
            - Xuất đúng định dạng ngày.
    */
    friend std::ostream& operator<<(std::ostream& out,
                                    CDate d);
};

#endif