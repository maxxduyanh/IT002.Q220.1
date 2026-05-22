#include "NongTrai.h"
#include <ctime>

int main() {
    srand(time(nullptr));
    Bo bo; Cuu cuu; De de;
    cout << "Nhap so bo\n"; bo.nhap();
    cout << "Nhap so cuu\n"; cuu.nhap();
    cout << "Nhap so de\n"; de.nhap();

    vector<GiaSuc*> nongTrai = { &bo, &cuu, &de };

    cout << "\nKhi chu nong trai di vang, gia suc doi va keu:\n";
    for (auto p : nongTrai) p->keu();

    int tongCon = 0, tongSua = 0;
    for (auto p : nongTrai) {
        int con = p->sinhCon();
        int sua = p->choSua();
        p->capNhatSoLuong(con);
        tongCon += con;
        tongSua += sua;
    }

    cout << "\nTong so gia suc con sinh ra: " << tongCon;
    cout << "\nTong so lit sua: " << tongSua;
    cout << "\nSo bo sau dot sinh: " << bo.getSoLuong();
    cout << "\nSo cuu sau dot sinh: " << cuu.getSoLuong();
    cout << "\nSo de sau dot sinh: " << de.getSoLuong() << endl;
    return 0;
}