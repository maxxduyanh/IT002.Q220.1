#ifndef GIAODICH_H
#define GIAODICH_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NgayGD {
private:
    int ngay, thang, nam;
public:
    NgayGD(int d = 1, int m = 1, int y = 2024);
    bool laThang12Nam2024() const;
    friend istream& operator>>(istream& in, NgayGD& n);
    friend ostream& operator<<(ostream& out, const NgayGD& n);
};

class GiaoDich {
protected:
    string maGD;
    NgayGD ngayGD;
    double donGia, dienTich, thanhTien;
public:
    GiaoDich();
    virtual ~GiaoDich();
    virtual void nhap();
    virtual void xuat() const;
    virtual double tinhThanhTien() = 0;
    double getThanhTien() const;
    bool giaoDichThang12Nam2024() const;
};

class GiaoDichDat : public GiaoDich {
private:
    char loaiDat;
public:
    void nhap() override;
    void xuat() const override;
    double tinhThanhTien() override;
};

class GiaoDichNhaPho : public GiaoDich {
private:
    string loaiNha, diaChi;
public:
    void nhap() override;
    void xuat() const override;
    double tinhThanhTien() override;
};

class GiaoDichCanHo : public GiaoDich {
private:
    string maCan;
    int viTriTang;
public:
    void nhap() override;
    void xuat() const override;
    double tinhThanhTien() override;
};

#endif