#include <iostream>
#include <string>

using namespace std;

struct HocSinh {
    string hoTen;
    float diemToan;
    float diemVan;
    float diemTB;
};

/*
 * Tên hàm: nhapHocSinh
 * Đầu vào: Biến cấu trúc HocSinh (truyền tham chiếu &)
 * Đầu ra: Không có (void)
 * Chức năng: Nhập thông tin họ tên, điểm toán, văn của học sinh.
 */
void nhapHocSinh(HocSinh &hs) {
    cout << "Nhap ho ten hoc sinh: ";
    getline(cin, hs.hoTen);
    cout << "Nhap diem Toan: ";
    cin >> hs.diemToan;
    cout << "Nhap diem Van: ";
    cin >> hs.diemVan;
}

/*
 * Tên hàm: tinhDiemTrungBinh
 * Đầu vào: Biến cấu trúc HocSinh (truyền tham chiếu &)
 * Đầu ra: Không có (void)
 * Chức năng: Tính trung bình cộng môn Toán và Văn.
 */
void tinhDiemTrungBinh(HocSinh &hs) {
    hs.diemTB = (hs.diemToan + hs.diemVan) / 2.0;
}

/*
 * Tên hàm: xuatHocSinh
 * Đầu vào: Biến cấu trúc HocSinh (truyền tham trị)
 * Đầu ra: Không có (void)
 * Chức năng: In toàn bộ thông tin của học sinh ra màn hình.
 */
void xuatHocSinh(HocSinh hs) {
    cout << "Ho ten: " << hs.hoTen << endl;
    cout << "Diem Toan: " << hs.diemToan << " | Diem Van: " << hs.diemVan << endl;
    cout << "Diem Trung Binh: " << hs.diemTB << endl;
}

int main() {
    HocSinh hs;
    nhapHocSinh(hs);
    tinhDiemTrungBinh(hs);
    xuatHocSinh(hs);
    
    return 0;
}