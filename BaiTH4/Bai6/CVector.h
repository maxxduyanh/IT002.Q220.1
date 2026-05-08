#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>

class CVector {
private:
    int soChieu;
    float* data;

public:

    /*
        INPUT:
            n: số chiều vector

        OUTPUT:
            Không có

        Ý tưởng:
            - Cấp phát mảng động.
            - Khởi tạo các phần tử = 0.
    */
    CVector(int n = 0);

    /*
        INPUT:
            v: vector khác

        OUTPUT:
            Không có

        Ý tưởng:
            - Sao chép dữ liệu vector.
    */
    CVector(const CVector& v);

    /*
        INPUT:
            Không có

        OUTPUT:
            Không có

        Ý tưởng:
            - Giải phóng bộ nhớ động.
    */
    ~CVector();

    /*
        INPUT:
            n: số chiều mới

        OUTPUT:
            Không có

        Ý tưởng:
            - Cấp phát lại vector.
    */
    void setSoChieu(int n);

    /*
        INPUT:
            Không có

        OUTPUT:
            Số chiều vector
    */
    int getSoChieu();

    /*
        INPUT:
            Không có

        OUTPUT:
            Độ dài vector

        Ý tưởng:
            - Tính:
                sqrt(x1^2 + x2^2 + ...)
    */
    float doDai();

    /*
        INPUT:
            v: vector khác

        OUTPUT:
            Tích vô hướng

        Ý tưởng:
            - Nhân từng phần tử tương ứng.
            - Cộng lại.
    */
    float tichVoHuong(CVector v);

    /*
        INPUT:
            v: vector cần cộng

        OUTPUT:
            Vector mới

        Ý tưởng:
            - Cộng từng tọa độ.
    */
    CVector operator+(CVector v);

    /*
        INPUT:
            v: vector cần trừ

        OUTPUT:
            Vector mới

        Ý tưởng:
            - Trừ từng tọa độ.
    */
    CVector operator-(CVector v);

    /*
        INPUT:
            k: số thực

        OUTPUT:
            Vector mới

        Ý tưởng:
            - Nhân từng phần tử với k.
    */
    CVector operator*(float k);

    /*
        INPUT:
            v: vector cần gán

        OUTPUT:
            Chính đối tượng hiện tại

        Ý tưởng:
            - Giải phóng dữ liệu cũ.
            - Sao chép dữ liệu mới.
    */
    CVector& operator=(CVector v);

    /*
        INPUT:
            Bàn phím:
            số chiều và tọa độ

        OUTPUT:
            Đối tượng vector

        Ý tưởng:
            - Nhập số chiều.
            - Nhập từng tọa độ.
    */
    friend std::istream& operator>>(std::istream& in,
                                    CVector& v);

    /*
        INPUT:
            v: vector cần xuất

        OUTPUT:
            Dạng vector

        Ý tưởng:
            - Xuất các tọa độ.
    */
    friend std::ostream& operator<<(std::ostream& out,
                                    CVector v);
};

#endif