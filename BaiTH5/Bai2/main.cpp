#include "GiaoDich.h"

int main() {
    int nDat, nNha, nCanHo;
    vector<GiaoDichDat> dsDat;
    vector<GiaoDichNhaPho> dsNha;
    vector<GiaoDichCanHo> dsCanHo;

    cout << "Nhap so giao dich Dat: "; cin >> nDat; dsDat.resize(nDat);
    for (int i = 0; i < nDat; i++) { cout << "\nGD Dat " << i + 1 << endl; dsDat[i].nhap(); }
    cout << "Nhap so giao dich Nha pho: "; cin >> nNha; dsNha.resize(nNha);
    for (int i = 0; i < nNha; i++) { cout << "\nGD Nha pho " << i + 1 << endl; dsNha[i].nhap(); }
    cout << "Nhap so giao dich Can ho: "; cin >> nCanHo; dsCanHo.resize(nCanHo);
    for (int i = 0; i < nCanHo; i++) { cout << "\nGD Can ho " << i + 1 << endl; dsCanHo[i].nhap(); }

    cout << "\nTong so luong giao dich Dat: " << dsDat.size();
    cout << "\nTong so luong giao dich Nha pho: " << dsNha.size();
    cout << "\nTong so luong giao dich Can ho: " << dsCanHo.size() << endl;

    double tongCanHo = 0;
    for (auto &x : dsCanHo) tongCanHo += x.getThanhTien();
    if (!dsCanHo.empty()) cout << "Trung binh thanh tien can ho: " << tongCanHo / dsCanHo.size() << endl;

    if (!dsNha.empty()) {
        int vt = 0;
        for (int i = 1; i < dsNha.size(); i++)
            if (dsNha[i].getThanhTien() > dsNha[vt].getThanhTien()) vt = i;
        cout << "\nGiao dich nha pho co tri gia cao nhat:\n";
        dsNha[vt].xuat();
    }

    cout << "\n===== GIAO DICH THANG 12/2024 =====\n";
    for (auto &x : dsDat) if (x.giaoDichThang12Nam2024()) x.xuat();
    for (auto &x : dsNha) if (x.giaoDichThang12Nam2024()) x.xuat();
    for (auto &x : dsCanHo) if (x.giaoDichThang12Nam2024()) x.xuat();
    return 0;
}