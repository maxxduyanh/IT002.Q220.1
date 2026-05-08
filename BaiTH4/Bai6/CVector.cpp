#include "CVector.h"
#include <cmath>

/*
    INPUT:
        n: số chiều

    OUTPUT:
        Không có
*/
CVector::CVector(int n) {

    soChieu = n;

    data = new float[soChieu];

    for (int i = 0; i < soChieu; i++) {
        data[i] = 0;
    }
}

/*
    INPUT:
        v: vector khác

    OUTPUT:
        Không có
*/
CVector::CVector(const CVector& v) {

    soChieu = v.soChieu;

    data = new float[soChieu];

    for (int i = 0; i < soChieu; i++) {
        data[i] = v.data[i];
    }
}

/*
    INPUT:
        Không có

    OUTPUT:
        Không có
*/
CVector::~CVector() {

    delete[] data;
}

/*
    INPUT:
        n: số chiều mới

    OUTPUT:
        Không có
*/
void CVector::setSoChieu(int n) {

    delete[] data;

    soChieu = n;

    data = new float[soChieu];

    for (int i = 0; i < soChieu; i++) {
        data[i] = 0;
    }
}

/*
    INPUT:
        Không có

    OUTPUT:
        Số chiều vector
*/
int CVector::getSoChieu() {

    return soChieu;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Độ dài vector
*/
float CVector::doDai() {

    float tong = 0;

    for (int i = 0; i < soChieu; i++) {

        tong += data[i] * data[i];
    }

    return sqrt(tong);
}

/*
    INPUT:
        v: vector khác

    OUTPUT:
        Tích vô hướng
*/
float CVector::tichVoHuong(CVector v) {

    float tong = 0;

    for (int i = 0; i < soChieu; i++) {

        tong += data[i] * v.data[i];
    }

    return tong;
}

/*
    INPUT:
        v: vector cần cộng

    OUTPUT:
        Vector mới
*/
CVector CVector::operator+(CVector v) {

    CVector kq(soChieu);

    for (int i = 0; i < soChieu; i++) {

        kq.data[i] =
            data[i] + v.data[i];
    }

    return kq;
}

/*
    INPUT:
        v: vector cần trừ

    OUTPUT:
        Vector mới
*/
CVector CVector::operator-(CVector v) {

    CVector kq(soChieu);

    for (int i = 0; i < soChieu; i++) {

        kq.data[i] =
            data[i] - v.data[i];
    }

    return kq;
}

/*
    INPUT:
        k: số thực

    OUTPUT:
        Vector mới
*/
CVector CVector::operator*(float k) {

    CVector kq(soChieu);

    for (int i = 0; i < soChieu; i++) {

        kq.data[i] =
            data[i] * k;
    }

    return kq;
}

/*
    INPUT:
        v: vector cần gán

    OUTPUT:
        Chính đối tượng hiện tại
*/
CVector& CVector::operator=(CVector v) {

    if (this != &v) {

        delete[] data;

        soChieu = v.soChieu;

        data = new float[soChieu];

        for (int i = 0; i < soChieu; i++) {

            data[i] = v.data[i];
        }
    }

    return *this;
}

/*
    INPUT:
        Bàn phím:
        số chiều và tọa độ

    OUTPUT:
        Đối tượng vector
*/
std::istream& operator>>(std::istream& in,
                         CVector& v) {

    std::cout << "Nhap so chieu: ";
    in >> v.soChieu;

    delete[] v.data;

    v.data = new float[v.soChieu];

    for (int i = 0; i < v.soChieu; i++) {

        std::cout
        << "Nhap toa do thu "
        << i + 1 << ": ";

        in >> v.data[i];
    }

    return in;
}

/*
    INPUT:
        v: vector cần xuất

    OUTPUT:
        Dạng vector
*/
std::ostream& operator<<(std::ostream& out,
                         CVector v) {

    out << "(";

    for (int i = 0; i < v.soChieu; i++) {

        out << v.data[i];

        if (i != v.soChieu - 1)
            out << ", ";
    }

    out << ")";

    return out;
}