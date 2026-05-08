#include "CMatrix.h"

/*
    INPUT:
        d: số dòng
        c: số cột

    OUTPUT:
        Không có
*/
CMatrix::CMatrix(int d, int c) {

    dong = d;
    cot = c;

    if (dong == 0 || cot == 0) {
        data = nullptr;
        return;
    }

    data = new float*[dong];

    for (int i = 0; i < dong; i++) {

        data[i] = new float[cot];

        for (int j = 0; j < cot; j++) {
            data[i][j] = 0;
        }
    }
}

/*
    INPUT:
        m: ma trận khác

    OUTPUT:
        Không có
*/
CMatrix::CMatrix(const CMatrix& m) {

    dong = m.dong;
    cot = m.cot;

    if (dong == 0 || cot == 0) {
        data = nullptr;
        return;
    }

    data = new float*[dong];

    for (int i = 0; i < dong; i++) {

        data[i] = new float[cot];

        for (int j = 0; j < cot; j++) {
            data[i][j] = m.data[i][j];
        }
    }
}

/*
    INPUT:
        Không có

    OUTPUT:
        Không có
*/
CMatrix::~CMatrix() {

    if (data != nullptr) {

        for (int i = 0; i < dong; i++) {
            delete[] data[i];
        }

        delete[] data;
    }
}

/*
    INPUT:
        d: số dòng
        c: số cột

    OUTPUT:
        Không có
*/
void CMatrix::setKichThuoc(int d,
                           int c) {

    if (data != nullptr) {

        for (int i = 0; i < dong; i++) {
            delete[] data[i];
        }

        delete[] data;
    }

    dong = d;
    cot = c;

    data = new float*[dong];

    for (int i = 0; i < dong; i++) {

        data[i] = new float[cot];

        for (int j = 0; j < cot; j++) {
            data[i][j] = 0;
        }
    }
}

/*
    INPUT:
        Không có

    OUTPUT:
        Số dòng
*/
int CMatrix::getDong() {

    return dong;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Số cột
*/
int CMatrix::getCot() {

    return cot;
}

/*
    INPUT:
        m: ma trận cần cộng

    OUTPUT:
        Ma trận kết quả
*/
CMatrix CMatrix::operator+(const CMatrix& m) {

    if (dong != m.dong ||
        cot != m.cot) {

        std::cout
        << "Khong cung kich thuoc!\n";

        return CMatrix();
    }

    CMatrix kq(dong, cot);

    for (int i = 0; i < dong; i++) {

        for (int j = 0; j < cot; j++) {

            kq.data[i][j]
            = data[i][j]
            + m.data[i][j];
        }
    }

    return kq;
}

/*
    INPUT:
        m: ma trận cần trừ

    OUTPUT:
        Ma trận kết quả
*/
CMatrix CMatrix::operator-(const CMatrix& m) {

    if (dong != m.dong ||
        cot != m.cot) {

        std::cout
        << "Khong cung kich thuoc!\n";

        return CMatrix();
    }

    CMatrix kq(dong, cot);

    for (int i = 0; i < dong; i++) {

        for (int j = 0; j < cot; j++) {

            kq.data[i][j]
            = data[i][j]
            - m.data[i][j];
        }
    }

    return kq;
}

/*
    INPUT:
        m: ma trận cần nhân

    OUTPUT:
        Ma trận kết quả
*/
CMatrix CMatrix::operator*(const CMatrix& m) {

    if (cot != m.dong) {

        std::cout
        << "Khong the nhan!\n";

        return CMatrix();
    }

    CMatrix kq(dong, m.cot);

    for (int i = 0; i < dong; i++) {

        for (int j = 0; j < m.cot; j++) {

            for (int k = 0; k < cot; k++) {

                kq.data[i][j]
                += data[i][k]
                 * m.data[k][j];
            }
        }
    }

    return kq;
}

/*
    INPUT:
        v: vector cần nhân

    OUTPUT:
        Vector kết quả
*/
CVector CMatrix::operator*(const CVector& v) {

    if (cot != v.soChieu) {

        std::cout
        << "Khong the nhan!\n";

        return CVector();
    }

    CVector kq(dong);

    for (int i = 0; i < dong; i++) {

        for (int j = 0; j < cot; j++) {

            kq.data[i]
            += data[i][j]
             * v.data[j];
        }
    }

    return kq;
}

/*
    INPUT:
        m: ma trận cần gán

    OUTPUT:
        Chính đối tượng hiện tại
*/
CMatrix& CMatrix::operator=(const CMatrix& m) {

    if (this != &m) {

        if (data != nullptr) {

            for (int i = 0; i < dong; i++) {
                delete[] data[i];
            }

            delete[] data;
        }

        dong = m.dong;
        cot = m.cot;

        if (dong == 0 || cot == 0) {
            data = nullptr;
            return *this;
        }

        data = new float*[dong];

        for (int i = 0; i < dong; i++) {

            data[i] = new float[cot];

            for (int j = 0; j < cot; j++) {

                data[i][j]
                = m.data[i][j];
            }
        }
    }

    return *this;
}

/*
    INPUT:
        Bàn phím:
        kích thước và phần tử

    OUTPUT:
        Đối tượng ma trận
*/
std::istream& operator>>(std::istream& in,
                         CMatrix& m) {

    int d, c;

    std::cout << "Nhap so dong: ";
    in >> d;

    std::cout << "Nhap so cot: ";
    in >> c;

    if (m.data != nullptr) {

        for (int i = 0; i < m.dong; i++) {
            delete[] m.data[i];
        }

        delete[] m.data;
    }

    m.dong = d;
    m.cot = c;

    m.data = new float*[m.dong];

    for (int i = 0; i < m.dong; i++) {

        m.data[i] =
        new float[m.cot];

        for (int j = 0; j < m.cot; j++) {

            std::cout
            << "a[" << i
            << "][" << j
            << "] = ";

            in >> m.data[i][j];
        }
    }

    return in;
}

/*
    INPUT:
        m: ma trận cần xuất

    OUTPUT:
        Dạng ma trận
*/
std::ostream& operator<<(std::ostream& out,
                         const CMatrix& m) {

    for (int i = 0; i < m.dong; i++) {

        for (int j = 0; j < m.cot; j++) {

            out << m.data[i][j]
                << "\t";
        }

        out << std::endl;
    }

    return out;
}