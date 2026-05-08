#include "PhanSo.h"

/*
    Hàm tìm UCLN

    INPUT:
        a, b: hai số nguyên

    OUTPUT:
        UCLN của a và b

    Ý tưởng:
        - Dùng thuật toán Euclid.
*/
int UCLN(int a, int b) {

    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

/*
    INPUT:
        t: tử số
        m: mẫu số

    OUTPUT:
        Không có

    Ý tưởng:
        - Khởi tạo phân số.
        - Rút gọn phân số.
*/
PhanSo::PhanSo(int t, int m) {

    tu = t;
    mau = m;

    rutGon();
}

/*
    INPUT:
        t: tử số
        m: mẫu số

    OUTPUT:
        Không có

    Ý tưởng:
        - Gán lại giá trị.
        - Rút gọn phân số.
*/
void PhanSo::set(int t, int m) {

    tu = t;
    mau = m;

    rutGon();
}

/*
    INPUT:
        Không có

    OUTPUT:
        Tử số

    Ý tưởng:
        - Trả về tử số.
*/
int PhanSo::getTu() {
    return tu;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Mẫu số

    Ý tưởng:
        - Trả về mẫu số.
*/
int PhanSo::getMau() {
    return mau;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Không có

    Ý tưởng:
        - Tìm UCLN.
        - Chia tử và mẫu cho UCLN.
        - Đưa dấu âm lên tử số.
*/
void PhanSo::rutGon() {

    int ucln = UCLN(tu, mau);

    tu /= ucln;
    mau /= ucln;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

/*
    INPUT:
        ps: phân số cần cộng

    OUTPUT:
        Phân số mới

    Ý tưởng:
        a/b + c/d
        = (ad + bc)/bd
*/
PhanSo PhanSo::operator+(PhanSo ps) {

    int t = tu * ps.mau
          + ps.tu * mau;

    int m = mau * ps.mau;

    return PhanSo(t, m);
}

/*
    INPUT:
        ps: phân số cần trừ

    OUTPUT:
        Phân số mới

    Ý tưởng:
        a/b - c/d
        = (ad - bc)/bd
*/
PhanSo PhanSo::operator-(PhanSo ps) {

    int t = tu * ps.mau
          - ps.tu * mau;

    int m = mau * ps.mau;

    return PhanSo(t, m);
}

/*
    INPUT:
        ps: phân số cần nhân

    OUTPUT:
        Phân số mới

    Ý tưởng:
        a/b * c/d
        = ac/bd
*/
PhanSo PhanSo::operator*(PhanSo ps) {

    int t = tu * ps.tu;
    int m = mau * ps.mau;

    return PhanSo(t, m);
}

/*
    INPUT:
        ps: phân số cần chia

    OUTPUT:
        Phân số mới

    Ý tưởng:
        a/b : c/d
        = ad/bc
*/
PhanSo PhanSo::operator/(PhanSo ps) {

    int t = tu * ps.mau;
    int m = mau * ps.tu;

    return PhanSo(t, m);
}

/*
    INPUT:
        ps: phân số cần so sánh

    OUTPUT:
        true hoặc false

    Ý tưởng:
        - So sánh chéo.
*/
bool PhanSo::operator==(PhanSo ps) {

    return (tu * ps.mau ==
            ps.tu * mau);
}

/*
    INPUT:
        ps: phân số cần so sánh

    OUTPUT:
        true hoặc false

    Ý tưởng:
        - So sánh chéo.
*/
bool PhanSo::operator>(PhanSo ps) {

    return (tu * ps.mau >
            ps.tu * mau);
}

/*
    INPUT:
        ps: phân số cần so sánh

    OUTPUT:
        true hoặc false

    Ý tưởng:
        - So sánh chéo.
*/
bool PhanSo::operator<(PhanSo ps) {

    return (tu * ps.mau <
            ps.tu * mau);
}

/*
    INPUT:
        Bàn phím:
        tử số và mẫu số

    OUTPUT:
        Đối tượng phân số

    Ý tưởng:
        - Nhập tử và mẫu.
        - Rút gọn phân số.
*/
istream& operator>>(istream& in,
                    PhanSo& ps) {

    cout << "Nhap tu so: ";
    in >> ps.tu;

    cout << "Nhap mau so: ";
    in >> ps.mau;

    ps.rutGon();

    return in;
}

/*
    INPUT:
        ps: phân số cần xuất

    OUTPUT:
        Dạng tử/mẫu

    Ý tưởng:
        - Xuất theo dạng phân số.
*/
ostream& operator<<(ostream& out,
                    PhanSo ps) {

    out << ps.tu << "/" << ps.mau;

    return out;
}