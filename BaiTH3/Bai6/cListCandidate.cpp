#include "cListCandidate.h"
#include <algorithm>

// Input: n và n thí sinh
// Output: danh sách
void cListCandidate::Nhap() {
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    ds.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "\nThi sinh " << i+1 << ":\n";
        ds[i].Nhap();
    }
}

// Output: các thí sinh có tổng > 15
// Thuật toán: duyệt và lọc
void cListCandidate::XuatLonHon15() {
    for (auto x : ds)
        if (x.TongDiem() > 15)
            x.Xuat();
}

// Output: thí sinh có tổng điểm cao nhất
// Thuật toán: max_element
cCandidate cListCandidate::Max() {
    return *max_element(ds.begin(), ds.end(), [](cCandidate a, cCandidate b){
        return a.TongDiem() < b.TongDiem();
    });
}

// Output: sắp xếp giảm dần theo tổng điểm
void cListCandidate::SapXepGiam() {
    sort(ds.begin(), ds.end(), [](cCandidate a, cCandidate b){
        return a.TongDiem() > b.TongDiem();
    });
}