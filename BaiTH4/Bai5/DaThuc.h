#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>

class DaThuc {
private:
    int bac;
    float* heSo;

public:

    /*
        INPUT:
            b: bậc đa thức

        OUTPUT:
            Không có

        Ý tưởng:
            - Cấp phát mảng hệ số.
            - Khởi tạo các hệ số bằng 0.
    */
    DaThuc(int b = 0);

    /*
        INPUT:
            dt: đa thức khác

        OUTPUT:
            Không có

        Ý tưởng:
            - Sao chép dữ liệu từ đa thức khác.
    */
    DaThuc(const DaThuc& dt);

    /*
        INPUT:
            Không có

        OUTPUT:
            Không có

        Ý tưởng:
            - Giải phóng vùng nhớ động.
    */
    ~DaThuc();

    /*
        INPUT:
            b: bậc mới

        OUTPUT:
            Không có

        Ý tưởng:
            - Cấp phát lại mảng hệ số.
    */
    void setBac(int b);

    /*
        INPUT:
            Không có

        OUTPUT:
            Bậc đa thức
    */
    int getBac();

    /*
        INPUT:
            x: giá trị cần thay

        OUTPUT:
            Giá trị đa thức tại x

        Ý tưởng:
            - Tính:
                a0 + a1*x + ...
    */
    float tinhGiaTri(float x);

    /*
        INPUT:
            dt: đa thức cần cộng

        OUTPUT:
            Đa thức mới

        Ý tưởng:
            - Cộng từng hệ số cùng bậc.
    */
    DaThuc operator+(DaThuc dt);

    /*
        INPUT:
            dt: đa thức cần trừ

        OUTPUT:
            Đa thức mới

        Ý tưởng:
            - Trừ từng hệ số cùng bậc.
    */
    DaThuc operator-(DaThuc dt);

    /*
        INPUT:
            dt: đa thức cần nhân

        OUTPUT:
            Đa thức mới

        Ý tưởng:
            - Nhân từng hạng tử.
    */
    DaThuc operator*(DaThuc dt);

    /*
        INPUT:
            dt: đa thức cần gán

        OUTPUT:
            Chính đối tượng hiện tại

        Ý tưởng:
            - Giải phóng dữ liệu cũ.
            - Sao chép dữ liệu mới.
    */
    DaThuc& operator=(DaThuc dt);

    /*
        INPUT:
            Bàn phím:
            bậc và hệ số

        OUTPUT:
            Đối tượng đa thức

        Ý tưởng:
            - Nhập bậc.
            - Nhập các hệ số.
    */
    friend std::istream& operator>>(std::istream& in,
                                    DaThuc& dt);

    /*
        INPUT:
            dt: đa thức cần xuất

        OUTPUT:
            Dạng đa thức

        Ý tưởng:
            - Xuất từng hạng tử.
    */
    friend std::ostream& operator<<(std::ostream& out,
                                    DaThuc dt);
};

#endif