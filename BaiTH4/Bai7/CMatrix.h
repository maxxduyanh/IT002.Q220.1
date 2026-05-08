#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include "CVector.h"

class CMatrix {
private:
    int dong;
    int cot;
    float** data;

public:

    /*
        INPUT:
            d: số dòng
            c: số cột

        OUTPUT:
            Không có

        Ý tưởng:
            - Cấp phát ma trận động.
            - Gán tất cả phần tử = 0.
    */
    CMatrix(int d = 0, int c = 0);

    /*
        INPUT:
            m: ma trận khác

        OUTPUT:
            Không có

        Ý tưởng:
            - Copy dữ liệu ma trận.
    */
    CMatrix(const CMatrix& m);

    /*
        INPUT:
            Không có

        OUTPUT:
            Không có

        Ý tưởng:
            - Giải phóng bộ nhớ.
    */
    ~CMatrix();

    /*
        INPUT:
            d: số dòng mới
            c: số cột mới

        OUTPUT:
            Không có

        Ý tưởng:
            - Xóa ma trận cũ.
            - Cấp phát ma trận mới.
    */
    void setKichThuoc(int d, int c);

    /*
        INPUT:
            Không có

        OUTPUT:
            Số dòng
    */
    int getDong();

    /*
        INPUT:
            Không có

        OUTPUT:
            Số cột
    */
    int getCot();

    /*
        INPUT:
            m: ma trận cần cộng

        OUTPUT:
            Ma trận kết quả

        Ý tưởng:
            - Cộng từng phần tử.
    */
    CMatrix operator+(const CMatrix& m);

    /*
        INPUT:
            m: ma trận cần trừ

        OUTPUT:
            Ma trận kết quả

        Ý tưởng:
            - Trừ từng phần tử.
    */
    CMatrix operator-(const CMatrix& m);

    /*
        INPUT:
            m: ma trận cần nhân

        OUTPUT:
            Ma trận kết quả

        Ý tưởng:
            - Nhân ma trận theo công thức.
    */
    CMatrix operator*(const CMatrix& m);

    /*
        INPUT:
            v: vector cần nhân

        OUTPUT:
            Vector kết quả

        Ý tưởng:
            - Nhân từng hàng với vector.
    */
    CVector operator*(const CVector& v);

    /*
        INPUT:
            m: ma trận cần gán

        OUTPUT:
            Chính đối tượng hiện tại
    */
    CMatrix& operator=(const CMatrix& m);

    /*
        INPUT:
            Bàn phím:
            kích thước và phần tử

        OUTPUT:
            Đối tượng ma trận
    */
    friend std::istream& operator>>(std::istream& in,
                                    CMatrix& m);

    /*
        INPUT:
            m: ma trận cần xuất

        OUTPUT:
            Dạng ma trận
    */
    friend std::ostream& operator<<(std::ostream& out,
                                    const CMatrix& m);
};

#endif