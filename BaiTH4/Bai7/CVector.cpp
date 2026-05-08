#include "CVector.h"

/*
    INPUT:
        n: số chiều

    OUTPUT:
        Không có
*/
CVector::CVector(int n) {

    soChieu = n;

    if (soChieu == 0) {
        data = nullptr;
        return;
    }

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

    if (soChieu == 0) {
        data = nullptr;
        return;
    }

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

    if (data != nullptr) {
        delete[] data;
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
        v: vector cần gán

    OUTPUT:
        Chính đối tượng hiện tại
*/
CVector& CVector::operator=(const CVector& v) {

    if (this != &v) {

        delete[] data;

        soChieu = v.soChieu;

        if (soChieu == 0) {
            data = nullptr;
            return *this;
        }

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
        số chiều và phần tử

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

        std::cout << "Nhap phan tu "
                  << i << ": ";

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
                         const CVector& v) {

    out << "(";

    for (int i = 0; i < v.soChieu; i++) {

        out << v.data[i];

        if (i != v.soChieu - 1)
            out << ", ";
    }

    out << ")";

    return out;
}