#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

public:

    /*
        INPUT:
            t: tử số
            m: mẫu số (mặc định = 1)

        OUTPUT:
            Không có

        Ý tưởng:
            - Khởi tạo phân số.
            - Nếu chỉ truyền 1 số nguyên
              thì xem như phân số đặc biệt:
                  t / 1
    */
    PhanSo(int t = 0, int m = 1);

    /*
        INPUT:
            t: tử số
            m: mẫu số

        OUTPUT:
            Không có

        Ý tưởng:
            - Gán lại giá trị cho phân số.
    */
    void set(int t, int m = 1);

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị tử số

        Ý tưởng:
            - Trả về tử số.
    */
    int getTu();

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị mẫu số

        Ý tưởng:
            - Trả về mẫu số.
    */
    int getMau();

    /*
        INPUT:
            Không có

        OUTPUT:
            Không có

        Ý tưởng:
            - Tìm UCLN của tử và mẫu.
            - Chia cả tử và mẫu cho UCLN.
    */
    void rutGon();

    /*
        INPUT:
            ps: phân số cần cộng

        OUTPUT:
            Phân số mới

        Ý tưởng:
            a/b + c/d
            = (ad + bc) / bd
    */
    PhanSo operator+(PhanSo ps);

    /*
        INPUT:
            ps: phân số cần trừ

        OUTPUT:
            Phân số mới

        Ý tưởng:
            a/b - c/d
            = (ad - bc) / bd
    */
    PhanSo operator-(PhanSo ps);

    /*
        INPUT:
            ps: phân số cần nhân

        OUTPUT:
            Phân số mới

        Ý tưởng:
            a/b * c/d
            = ac / bd
    */
    PhanSo operator*(PhanSo ps);

    /*
        INPUT:
            ps: phân số cần chia

        OUTPUT:
            Phân số mới

        Ý tưởng:
            a/b : c/d
            = ad / bc
    */
    PhanSo operator/(PhanSo ps);

    /*
        INPUT:
            ps: phân số cần so sánh

        OUTPUT:
            true hoặc false

        Ý tưởng:
            - Quy đồng rồi so sánh.
    */
    bool operator==(PhanSo ps);

    /*
        INPUT:
            ps: phân số cần so sánh

        OUTPUT:
            true hoặc false

        Ý tưởng:
            - So sánh chéo:
                a*d và c*b
    */
    bool operator>(PhanSo ps);

    /*
        INPUT:
            ps: phân số cần so sánh

        OUTPUT:
            true hoặc false

        Ý tưởng:
            - So sánh chéo:
                a*d và c*b
    */
    bool operator<(PhanSo ps);

    /*
        INPUT:
            Bàn phím:
            tử số và mẫu số

        OUTPUT:
            Đối tượng phân số

        Ý tưởng:
            - Nhập tử và mẫu.
    */
    friend istream& operator>>(istream& in,
                               PhanSo& ps);

    /*
        INPUT:
            ps: phân số cần xuất

        OUTPUT:
            Dạng tử/mẫu

        Ý tưởng:
            - Xuất theo dạng phân số.
    */
    friend ostream& operator<<(ostream& out,
                               PhanSo ps);
};

#endif