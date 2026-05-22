#ifndef NHANVIENPM_H
#define NHANVIENPM_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVienPM {
protected:
    string maNV, hoTen, soDienThoai, email;
    int tuoi;
    double luongCoBan, luong;
public:
    NhanVienPM();
    virtual ~NhanVienPM();
    virtual void nhap();
    virtual void xuat() const;
    virtual double tinhLuong() = 0;
    double getLuong() const;
};

class LapTrinhVien : public NhanVienPM {
private:
    int soGioOvertime;
public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() override;
};

class KiemChungVien : public NhanVienPM {
private:
    int soLoiPhatHien;
public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() override;
};
#endif