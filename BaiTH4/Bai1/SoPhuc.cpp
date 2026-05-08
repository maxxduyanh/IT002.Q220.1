#include "SoPhuc.h"

/*
    INPUT:
        t: phần thực
        a: phần ảo

    OUTPUT:
        Không có

    Ý tưởng:
        - Khởi tạo số phức.
*/
SoPhuc::SoPhuc(double t, double a) {
    thuc = t;
    ao = a;
}

/*
    INPUT:
        t: phần thực
        a: phần ảo

    OUTPUT:
        Không có

    Ý tưởng:
        - Gán lại giá trị cho số phức.
*/
void SoPhuc::set(double t, double a) {
    thuc = t;
    ao = a;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Phần thực

    Ý tưởng:
        - Trả về phần thực.
*/
double SoPhuc::getThuc() {
    return thuc;
}

/*
    INPUT:
        Không có

    OUTPUT:
        Phần ảo

    Ý tưởng:
        - Trả về phần ảo.
*/
double SoPhuc::getAo() {
    return ao;
}

/*
    INPUT:
        sp: số phức cần cộng

    OUTPUT:
        Số phức mới

    Ý tưởng:
        - Cộng từng phần tương ứng.
*/
SoPhuc SoPhuc::operator+(SoPhuc sp) {
    return SoPhuc(thuc + sp.thuc,
                  ao + sp.ao);
}

/*
    INPUT:
        sp: số phức cần trừ

    OUTPUT:
        Số phức mới

    Ý tưởng:
        - Trừ từng phần tương ứng.
*/
SoPhuc SoPhuc::operator-(SoPhuc sp) {
    return SoPhuc(thuc - sp.thuc,
                  ao - sp.ao);
}

/*
    INPUT:
        sp: số phức cần nhân

    OUTPUT:
        Số phức mới

    Ý tưởng:
        (a + bi)(c + di)
        = (ac - bd) + (ad + bc)i
*/
SoPhuc SoPhuc::operator*(SoPhuc sp) {

    double t = thuc * sp.thuc
             - ao * sp.ao;

    double a = thuc * sp.ao
             + ao * sp.thuc;

    return SoPhuc(t, a);
}

/*
    INPUT:
        sp: số phức cần chia

    OUTPUT:
        Số phức mới

    Ý tưởng:
        - Nhân liên hợp để khử mẫu.
*/
SoPhuc SoPhuc::operator/(SoPhuc sp) {

    double mau = sp.thuc * sp.thuc
               + sp.ao * sp.ao;

    double t = (thuc * sp.thuc
              + ao * sp.ao) / mau;

    double a = (ao * sp.thuc
              - thuc * sp.ao) / mau;

    return SoPhuc(t, a);
}

/*
    INPUT:
        sp: số phức cần so sánh

    OUTPUT:
        true hoặc false

    Ý tưởng:
        - So sánh phần thực và phần ảo.
*/
bool SoPhuc::operator==(SoPhuc sp) {

    return (thuc == sp.thuc &&
            ao == sp.ao);
}

/*
    INPUT:
        sp: số phức cần so sánh

    OUTPUT:
        true hoặc false

    Ý tưởng:
        - Phủ định toán tử ==.
*/
bool SoPhuc::operator!=(SoPhuc sp) {

    return !(*this == sp);
}

/*
    INPUT:
        Bàn phím:
        phần thực và phần ảo

    OUTPUT:
        Đối tượng số phức

    Ý tưởng:
        - Nhập dữ liệu cho số phức.
*/
istream& operator>>(istream& in,
                    SoPhuc& sp) {

    cout << "Nhap phan thuc: ";
    in >> sp.thuc;

    cout << "Nhap phan ao: ";
    in >> sp.ao;

    return in;
}

/*
    INPUT:
        sp: số phức cần xuất

    OUTPUT:
        Dạng a + bi

    Ý tưởng:
        - Kiểm tra dấu phần ảo.
*/
ostream& operator<<(ostream& out,
                    SoPhuc sp) {

    out << sp.thuc;

    if (sp.ao >= 0)
        out << " + " << sp.ao << "i";
    else
        out << " - " << -sp.ao << "i";

    return out;
}