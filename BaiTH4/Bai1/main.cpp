#include "SoPhuc.h"

int main() {

    SoPhuc a, b;

    cout << "Nhap so phuc a:\n";
    cin >> a;

    cout << "\nNhap so phuc b:\n";
    cin >> b;

    cout << "\na = " << a << endl;
    cout << "b = " << b << endl;

    cout << "\na + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    if (a == b)
        cout << "\nHai so phuc bang nhau\n";
    else
        cout << "\nHai so phuc khac nhau\n";

    // Minh họa số thực như số phức đặc biệt
    SoPhuc c(5);

    cout << "\nSo phuc c = " << c << endl;

    return 0;
}