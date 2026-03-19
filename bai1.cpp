#include <iostream>
#include <cmath>

using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

/*
 * Tên hàm: timUCLN
 * Đầu vào: 2 số nguyên a, b (int)
 * Đầu ra: Ước chung lớn nhất của a và b (int)
 * Chức năng: Tìm ước chung lớn nhất phục vụ việc rút gọn phân số.
 */
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    return timUCLN(b, a % b);
}

/*
 * Tên hàm: nhapPhanSo
 * Đầu vào: Biến cấu trúc PhanSo (truyền tham chiếu &)
 * Đầu ra: Không có (void)
 * Chức năng: Nhận giá trị tử số và mẫu số từ người dùng, yêu cầu nhập lại nếu mẫu = 0.
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
 * Tên hàm: rutGonPhanSo
 * Đầu vào: Biến cấu trúc PhanSo (truyền tham chiếu &)
 * Đầu ra: Không có (void)
 * Chức năng: Rút gọn phân số bằng cách chia cả tử và mẫu cho UCLN.
 */
void rutGonPhanSo(PhanSo &ps) {
    int ucln = timUCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
}

/*
 * Tên hàm: xuatPhanSo
 * Đầu vào: Biến cấu trúc PhanSo (truyền tham trị)
 * Đầu ra: Không có (void)
 * Chức năng: In phân số ra màn hình. Xử lý dấu trừ ở mẫu số.
 */
void xuatPhanSo(PhanSo ps) {
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    if (ps.mau == 1) {
        cout << ps.tu;
    } else if (ps.tu == 0) {
        cout << 0;
    } else {
        cout << ps.tu << "/" << ps.mau;
    }
}

int main() {
    PhanSo ps;

    nhapPhanSo(ps);
    rutGonPhanSo(ps);
    cout << "Phan so sau khi rut gon: ";
    xuatPhanSo(ps);
    cout << endl;
    return 0;
}