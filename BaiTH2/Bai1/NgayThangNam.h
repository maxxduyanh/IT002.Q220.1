#pragma once

#include <iostream>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

    // Hàm bổ trợ kiểm tra năm nhuận và số ngày trong tháng
    bool laNamNhuan(int nam);
    int tinhSoNgayTrongThang(int thang, int nam);

public:
    void Nhap();
    void Xuat();
    void NgayThangNamTiepTheo();
};

