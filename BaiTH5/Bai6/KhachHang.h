#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class KhachHang {
protected:
    string ten;
    int soLuong;
    double donGia, soTien;
public:
    KhachHang();
    virtual ~KhachHang();
    virtual void doc(ifstream& fin);
    virtual void ghi(ofstream& fout) const;
    virtual double tinhTien() = 0;
    double getSoTien() const;
};

class KhachHangA : public KhachHang {
public:
    double tinhTien() override;
};

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;
public:
    void doc(ifstream& fin) override;
    double tinhTien() override;
};

class KhachHangC : public KhachHang {
public:
    double tinhTien() override;
};
#endif