#include "DaThuc.h"
#include <cmath>

/*
    INPUT:
        b: bậc đa thức

    OUTPUT:
        Không có
*/
DaThuc::DaThuc(int b) {

    bac = b;

    heSo = new float[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = 0;
    }
}

/*
    INPUT:
        dt: đa thức khác

    OUTPUT:
        Không có
*/
DaThuc::DaThuc(const DaThuc& dt) {

    bac = dt.bac;

    heSo = new float[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = dt.heSo[i];
    }
}

/*
    INPUT:
        Không có

    OUTPUT:
        Không có
*/
DaThuc::~DaThuc() {

    delete[] heSo;
}

/*
    INPUT:
        b: bậc mới

    OUTPUT:
        Không có
*/
void DaThuc::setBac(int b) {

    delete[] heSo;

    bac = b;

    heSo = new float[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = 0;
    }
}

/*
    INPUT:
        Không có

    OUTPUT:
        Bậc đa thức
*/
int DaThuc::getBac() {

    return bac;
}

/*
    INPUT:
        x: giá trị cần thay

    OUTPUT:
        Giá trị đa thức

    Ý tưởng:
        - Tính tổng:
            ai * x^i
*/
float DaThuc::tinhGiaTri(float x) {

    float tong = 0;

    for (int i = 0; i <= bac; i++) {

        tong += heSo[i] * pow(x, i);
    }

    return tong;
}

/*
    INPUT:
        dt: đa thức cần cộng

    OUTPUT:
        Đa thức mới
*/
DaThuc DaThuc::operator+(DaThuc dt) {

    int maxBac =
        (bac > dt.bac) ? bac : dt.bac;

    DaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {

        float hs1 =
            (i <= bac) ? heSo[i] : 0;

        float hs2 =
            (i <= dt.bac) ? dt.heSo[i] : 0;

        kq.heSo[i] = hs1 + hs2;
    }

    return kq;
}

/*
    INPUT:
        dt: đa thức cần trừ

    OUTPUT:
        Đa thức mới
*/
DaThuc DaThuc::operator-(DaThuc dt) {

    int maxBac =
        (bac > dt.bac) ? bac : dt.bac;

    DaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {

        float hs1 =
            (i <= bac) ? heSo[i] : 0;

        float hs2 =
            (i <= dt.bac) ? dt.heSo[i] : 0;

        kq.heSo[i] = hs1 - hs2;
    }

    return kq;
}

/*
    INPUT:
        dt: đa thức cần nhân

    OUTPUT:
        Đa thức mới

    Ý tưởng:
        - Nhân từng hạng tử:
            x^i * x^j = x^(i+j)
*/
DaThuc DaThuc::operator*(DaThuc dt) {

    DaThuc kq(bac + dt.bac);

    for (int i = 0; i <= bac; i++) {

        for (int j = 0;
             j <= dt.bac;
             j++) {

            kq.heSo[i + j]
            += heSo[i] * dt.heSo[j];
        }
    }

    return kq;
}

/*
    INPUT:
        dt: đa thức cần gán

    OUTPUT:
        Chính đối tượng hiện tại
*/
DaThuc& DaThuc::operator=(DaThuc dt) {

    if (this != &dt) {

        delete[] heSo;

        bac = dt.bac;

        heSo = new float[bac + 1];

        for (int i = 0; i <= bac; i++) {

            heSo[i] = dt.heSo[i];
        }
    }

    return *this;
}

/*
    INPUT:
        Bàn phím:
        bậc và hệ số

    OUTPUT:
        Đối tượng đa thức
*/
std::istream& operator>>(std::istream& in,
                         DaThuc& dt) {

    std::cout << "Nhap bac da thuc: ";
    in >> dt.bac;

    delete[] dt.heSo;

    dt.heSo =
        new float[dt.bac + 1];

    for (int i = dt.bac; i >= 0; i--) {

        std::cout
        << "Nhap he so bac "
        << i << ": ";

        in >> dt.heSo[i];
    }

    return in;
}

/*
    INPUT:
        dt: đa thức cần xuất

    OUTPUT:
        Dạng đa thức
*/
std::ostream& operator<<(std::ostream& out,
                         DaThuc dt) {

    bool first = true;

    for (int i = dt.bac; i >= 0; i--) {

        if (dt.heSo[i] == 0)
            continue;

        if (!first &&
            dt.heSo[i] > 0) {

            out << " + ";
        }

        if (dt.heSo[i] < 0) {

            out << " - ";
        }

        out << abs(dt.heSo[i]);

        if (i > 0)
            out << "x";

        if (i > 1)
            out << "^" << i;

        first = false;
    }

    if (first)
        out << "0";

    return out;
}