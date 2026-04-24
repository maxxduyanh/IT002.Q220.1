#include "cCandidate.h"

// Input: thông tin thí sinh
// Output: lưu vào đối tượng
// Thuật toán: nhập từng thuộc tính
void cCandidate::Nhap() {
    cin.ignore();
    cout << "Ma: "; getline(cin, ma);
    cout << "Ten: "; getline(cin, ten);
    cout << "Ngay sinh (d m y): ";
    cin >> ngay >> thang >> nam;
    cout << "Diem Toan Van Anh: ";
    cin >> toan >> van >> anh;
}

// Output: in thông tin thí sinh
void cCandidate::Xuat() {
    cout << ma << " | " << ten << " | "
         << ngay << "/" << thang << "/" << nam << " | "
         << "Toan: " << toan
         << " Van: " << van
         << " Anh: " << anh
         << " Tong: " << TongDiem()
         << endl;
}

// Output: tổng điểm
// Thuật toán: cộng 3 môn
double cCandidate::TongDiem() {
    return toan + van + anh;
}