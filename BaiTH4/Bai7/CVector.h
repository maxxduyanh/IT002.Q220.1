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
            - Khởi tạo giá trị = 0.
    */
    CVector(int n = 0);

    /*
        INPUT:
            v: vector khác

        OUTPUT:
            Không có

        Ý tưởng:
            - Copy dữ liệu từ vector khác.
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
            Không có

        OUTPUT:
            Số chiều vector.
    */
    int getSoChieu();

    /*
        INPUT:
            v: vector cần gán

        OUTPUT:
            Chính đối tượng hiện tại

        Ý tưởng:
            - Xóa dữ liệu cũ.
            - Copy dữ liệu mới.
    */
    CVector& operator=(const CVector& v);

    /*
        INPUT:
            Bàn phím:
            số chiều và các phần tử

        OUTPUT:
            Đối tượng vector
    */
    friend std::istream& operator>>(std::istream& in,
                                    CVector& v);

    /*
        INPUT:
            v: vector cần xuất

        OUTPUT:
            Dạng vector
    */
    friend std::ostream& operator<<(std::ostream& out,
                                    const CVector& v);

    friend class CMatrix;
};

#endif