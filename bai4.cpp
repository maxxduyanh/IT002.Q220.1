#include <iostream>

using namespace std;

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

/*
 * Tên hàm: laNamNhuan
 * Đầu vào: Năm cần kiểm tra (int)
 * Đầu ra: True nếu là năm nhuận, False nếu không (bool)
 * Chức năng: Kiểm tra năm nhuận theo lịch Gregory.
 */
bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

/*
 * Tên hàm: soNgayTrongThang
 * Đầu vào: Tháng và năm (int)
 * Đầu ra: Số ngày của tháng đó (int)
 * Chức năng: Trả về số ngày tối đa của một tháng cụ thể.
 */
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return laNamNhuan(nam) ? 29 : 28;
        default: return 31;
    }
}

/*
 * Tên hàm: timNgayKeTiep
 * Đầu vào: Biến cấu trúc Ngay hiện tại (truyền tham trị)
 * Đầu ra: Biến cấu trúc Ngay của ngày kế tiếp (Ngay)
 * Chức năng: Tính toán và cập nhật ngày, tháng, năm cho ngày hôm sau.
 */
Ngay timNgayKeTiep(Ngay ht) {
    Ngay kt = ht;
    kt.ngay++;
    if (kt.ngay > soNgayTrongThang(ht.thang, ht.nam)) {
        kt.ngay = 1;
        kt.thang++;
        if (kt.thang > 12) {
            kt.thang = 1;
            kt.nam++;
        }
    }
    return kt;
}

int main() {
    Ngay ht;
    cout << "Nhap ngay, thang, nam (cach nhau boi khoang trang): ";
    cin >> ht.ngay >> ht.thang >> ht.nam;
    
    Ngay kt = timNgayKeTiep(ht);
    cout << "Ngay ke tiep la: " << kt.ngay << "/" << kt.thang << "/" << kt.nam << endl;
    
    return 0;
}