#include "CTime.h"
#include <windows.h>

int main() {

    CTime t;

    cout << "Nhap thoi gian:\n";
    cin >> t;

    cout << "\nThoi gian hien tai: "
         << t << endl;

    cout << "\nCong them 500 giay:\n";
    cout << t + 500 << endl;

    cout << "\nTru di 100 giay:\n";
    cout << t - 100 << endl;

    cout << "\nPrefix ++:\n";
    ++t;
    cout << t << endl;

    cout << "\nPostfix ++:\n";
    t++;
    cout << t << endl;

    cout << "\nPrefix --:\n";
    --t;
    cout << t << endl;

    cout << "\nPostfix --:\n";
    t--;
    cout << t << endl;

    /*
        Đồng hồ chạy ở góc trên bên phải

        Ý tưởng:
            - Dùng tọa độ console.
            - In thời gian liên tục.
            - Mỗi giây tăng thời gian lên 1.
    */

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;

    pos.X = 60;
    pos.Y = 0;

    while (true) {

        SetConsoleCursorPosition(h, pos);

        cout << "Clock: " << t;

        Sleep(1000);

        ++t;
    }

    return 0;
}