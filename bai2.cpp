#include <iostream>

using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

/*
 * Tên hàm: nhapPhanSo
 * Đầu vào: Biến cấu trúc PhanSo (truyền tham chiếu &)
 * Đầu ra: Không có (void)
 * Chức năng: Nhận giá trị tử và mẫu, đảm bảo mẫu khác 0.
 */
void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    do {
        cout << "Nhap mau so (khac 0): ";
        cin >> ps.mau;
        if (ps.mau == 0) cout << "Mau so phai khac 0. Vui long nhap lai!\n";
    } while (ps.mau == 0);
}

/*
 * Tên hàm: timPhanSoLonNhat
 * Đầu vào: 2 biến cấu trúc PhanSo (ps1, ps2)
 * Đầu ra: Phân số lớn hơn (PhanSo)
 * Chức năng: So sánh giá trị thực của 2 phân số và trả về phân số lớn nhất.
 */
PhanSo timPhanSoLonNhat(PhanSo ps1, PhanSo ps2) {
    float giaTri1 = (float)ps1.tu / ps1.mau;
    float giaTri2 = (float)ps2.tu / ps2.mau;
    return (giaTri1 > giaTri2) ? ps1 : ps2;
}

/*
 * Tên hàm: xuatPhanSo
 * Đầu vào: Biến cấu trúc PhanSo (truyền tham trị)
 * Đầu ra: Không có (void)
 * Chức năng: In phân số ra màn hình.
 */
void xuatPhanSo(PhanSo ps) {
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    if (ps.mau == 1) cout << ps.tu;
    else if (ps.tu == 0) cout << 0;
    else cout << ps.tu << "/" << ps.mau;
}

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu 1:\n"; nhapPhanSo(ps1);
    cout << "Nhap phan so thu 2:\n"; nhapPhanSo(ps2);
    
    PhanSo maxPS = timPhanSoLonNhat(ps1, ps2);
    cout << "Phan so lon nhat la: "; 
    xuatPhanSo(maxPS); 
    cout << endl;
    return 0;
}