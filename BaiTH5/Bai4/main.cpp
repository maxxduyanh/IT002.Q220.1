#include "NhanVienPM.h"

int main() {
    vector<NhanVienPM*> ds;
    int n, loai;
    cout << "Nhap so nhan vien: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap loai NV (1-LTV, 2-KCV): "; cin >> loai;
        NhanVienPM* p = nullptr;
        if (loai == 1) p = new LapTrinhVien();
        else p = new KiemChungVien();
        p->nhap();
        ds.push_back(p);
    }

    double tong = 0;
    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    for (auto p : ds) { p->xuat(); tong += p->getLuong(); }
    double tb = (n > 0) ? tong / n : 0;
    cout << "\nLuong trung binh: " << tb << endl;

    cout << "\nNhan vien co luong thap hon trung binh:\n";
    for (auto p : ds) if (p->getLuong() < tb) p->xuat();

    if (!ds.empty()) {
        int maxPos = 0, minPos = 0;
        for (int i = 1; i < ds.size(); i++) {
            if (ds[i]->getLuong() > ds[maxPos]->getLuong()) maxPos = i;
            if (ds[i]->getLuong() < ds[minPos]->getLuong()) minPos = i;
        }
        cout << "\nNhan vien luong cao nhat:\n"; ds[maxPos]->xuat();
        cout << "Nhan vien luong thap nhat:\n"; ds[minPos]->xuat();
    }

    LapTrinhVien* maxLTV = nullptr;
    KiemChungVien* minKCV = nullptr;
    for (auto p : ds) {
        if (auto ltv = dynamic_cast<LapTrinhVien*>(p))
            if (maxLTV == nullptr || ltv->getLuong() > maxLTV->getLuong()) maxLTV = ltv;
        if (auto kcv = dynamic_cast<KiemChungVien*>(p))
            if (minKCV == nullptr || kcv->getLuong() < minKCV->getLuong()) minKCV = kcv;
    }
    if (maxLTV) { cout << "\nLap trinh vien luong cao nhat:\n"; maxLTV->xuat(); }
    if (minKCV) { cout << "Kiem chung vien luong thap nhat:\n"; minKCV->xuat(); }

    for (auto p : ds) delete p;
    return 0;
}