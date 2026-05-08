#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc;
    double ao;

public:

    /*
        INPUT:
            t: phần thực
            a: phần ảo (mặc định = 0)

        OUTPUT:
            Không có

        Ý tưởng:
            - Khởi tạo số phức.
            - Nếu chỉ truyền 1 số thì xem như
              số thực đặc biệt.
    */
    SoPhuc(double t = 0, double a = 0);

    /*
        INPUT:
            t: phần thực
            a: phần ảo

        OUTPUT:
            Không có

        Ý tưởng:
            - Gán lại giá trị cho số phức.
    */
    void set(double t, double a = 0);

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị phần thực

        Ý tưởng:
            - Trả về phần thực.
    */
    double getThuc();

    /*
        INPUT:
            Không có

        OUTPUT:
            Giá trị phần ảo

        Ý tưởng:
            - Trả về phần ảo.
    */
    double getAo();

    /*
        INPUT:
            sp: số phức cần cộng

        OUTPUT:
            Số phức mới

        Ý tưởng:
            - Cộng từng phần tương ứng.
    */
    SoPhuc operator+(SoPhuc sp);

    /*
        INPUT:
            sp: số phức cần trừ

        OUTPUT:
            Số phức mới

        Ý tưởng:
            - Trừ từng phần tương ứng.
    */
    SoPhuc operator-(SoPhuc sp);

    /*
        INPUT:
            sp: số phức cần nhân

        OUTPUT:
            Số phức mới

        Ý tưởng:
            Dùng công thức nhân số phức.
    */
    SoPhuc operator*(SoPhuc sp);

    /*
        INPUT:
            sp: số phức cần chia

        OUTPUT:
            Số phức mới

        Ý tưởng:
            - Nhân liên hợp để khử mẫu ảo.
    */
    SoPhuc operator/(SoPhuc sp);

    /*
        INPUT:
            sp: số phức cần so sánh

        OUTPUT:
            true hoặc false

        Ý tưởng:
            - So sánh phần thực và phần ảo.
    */
    bool operator==(SoPhuc sp);

    /*
        INPUT:
            sp: số phức cần so sánh

        OUTPUT:
            true hoặc false

        Ý tưởng:
            - Phủ định kết quả ==.
    */
    bool operator!=(SoPhuc sp);

    /*
        INPUT:
            Bàn phím:
            phần thực và phần ảo

        OUTPUT:
            Đối tượng số phức

        Ý tưởng:
            - Nhập dữ liệu cho số phức.
    */
    friend istream& operator>>(istream& in,
                               SoPhuc& sp);

    /*
        INPUT:
            sp: số phức cần xuất

        OUTPUT:
            Dạng a + bi

        Ý tưởng:
            - Xuất đúng dấu của phần ảo.
    */
    friend ostream& operator<<(ostream& out,
                               SoPhuc sp);
};

#endif