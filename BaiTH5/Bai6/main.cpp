#include "KhachHang.h"

int main() {
    ifstream fin("XYZ.INP");
    ofstream fout("XYZ.OUT");
    if (!fin) {
        cout << "Khong mo duoc file XYZ.INP\n";
        return 0;
    }

    int x, y, z;
    fin >> x >> y >> z;
    fin.ignore();
    fout << x << " " << y << " " << z << '\n';

    vector<KhachHang*> ds;
    for (int i = 0; i < x; i++) { KhachHang* p = new KhachHangA(); p->doc(fin); ds.push_back(p); }
    for (int i = 0; i < y; i++) { KhachHang* p = new KhachHangB(); p->doc(fin); ds.push_back(p); }
    for (int i = 0; i < z; i++) { KhachHang* p = new KhachHangC(); p->doc(fin); ds.push_back(p); }

    double tongThu = 0;
    for (auto p : ds) {
        tongThu += p->tinhTien();
        p->ghi(fout);
    }
    fout << tongThu << '\n';

    for (auto p : ds) delete p;
    fin.close();
    fout.close();
    return 0;
}