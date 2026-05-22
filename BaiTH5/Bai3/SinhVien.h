#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
protected:
    string maSV, hoTen, diaChi;
    int tongTinChi;
    double diemTB;
public:
    SinhVien();
    virtual ~SinhVien();
    virtual void nhap();
    virtual void xuat() const;
    virtual bool duDieuKienTotNghiep() const = 0;
    double getDiemTB() const;
};

class SinhVienCaoDang : public SinhVien {
private:
    double diemThiTotNghiep;
public:
    void nhap() override;
    void xuat() const override;
    bool duDieuKienTotNghiep() const override;
};

class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;
public:
    void nhap() override;
    void xuat() const override;
    bool duDieuKienTotNghiep() const override;
};
#endif