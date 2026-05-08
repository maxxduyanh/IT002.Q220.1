#include "PhanSo.h"

int main() {

    PhanSo a, b;

    cout << "Nhap phan so a:\n";
    cin >> a;

    cout << "\nNhap phan so b:\n";
    cin >> b;

    cout << "\na = " << a << endl;
    cout << "b = " << b << endl;

    cout << "\na + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    if (a == b)
        cout << "\nHai phan so bang nhau\n";

    if (a > b)
        cout << "a lon hon b\n";

    if (a < b)
        cout << "a nho hon b\n";

    // Minh họa số nguyên như phân số đặc biệt
    PhanSo c(5);

    cout << "\nPhan so c = " << c << endl;

    return 0;
}