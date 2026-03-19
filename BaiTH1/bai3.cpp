#include <iostream>
#include <cmath>

using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

// --- CÁC HÀM HỖ TRỢ CƠ BẢN ---
int timUCLN(int a, int b) {
    a = abs(a); b = abs(b);
    if (b == 0) return a;
    return timUCLN(b, a % b);
}

void rutGonPhanSo(PhanSo &ps) {
    int ucln = timUCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
}

void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: "; cin >> ps.tu;
    do {
        cout << "Nhap mau so (khac 0): "; cin >> ps.mau;
    } while (ps.mau == 0);
}

void xuatPhanSo(PhanSo ps) {
    if (ps.mau < 0) { ps.tu = -ps.tu; ps.mau = -ps.mau; }
    if (ps.mau == 1) cout << ps.tu;
    else if (ps.tu == 0) cout << 0;
    else cout << ps.tu << "/" << ps.mau;
}

// --- CÁC HÀM TÍNH TOÁN ---
/*
 * Tên hàm: congPhanSo, truPhanSo, nhanPhanSo, chiaPhanSo
 * Đầu vào: 2 biến cấu trúc PhanSo
 * Đầu ra: Phân số kết quả (PhanSo)
 * Chức năng: Thực hiện phép toán tương ứng và trả về kết quả đã được rút gọn.
 */
PhanSo congPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutGonPhanSo(kq); return kq;
}

PhanSo truPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    kq.mau = ps1.mau * ps2.mau;
    rutGonPhanSo(kq); return kq;
}

PhanSo nhanPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.tu;
    kq.mau = ps1.mau * ps2.mau;
    rutGonPhanSo(kq); return kq;
}

PhanSo chiaPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.mau;
    kq.mau = ps1.mau * ps2.tu;
    rutGonPhanSo(kq); return kq;
}

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu 1:\n"; nhapPhanSo(ps1);
    cout << "Nhap phan so thu 2:\n"; nhapPhanSo(ps2);
    
    cout << "Tong: "; xuatPhanSo(congPhanSo(ps1, ps2)); cout << endl;
    cout << "Hieu: "; xuatPhanSo(truPhanSo(ps1, ps2)); cout << endl;
    cout << "Tich: "; xuatPhanSo(nhanPhanSo(ps1, ps2)); cout << endl;
    cout << "Thuong: "; xuatPhanSo(chiaPhanSo(ps1, ps2)); cout << endl;
    
    return 0;
}