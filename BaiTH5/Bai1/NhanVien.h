#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ngay {
private:
    int ngay, thang, nam;
public:
    /* INPUT: d, m, y. OUTPUT: không có. Ý tưởng: lưu ngày sinh. */
    Ngay(int d = 1, int m = 1, int y = 2000);
    /* INPUT: không có. OUTPUT: tuổi tương đối tại năm hiện tại. */
    int tinhTuoi(int namHienTai = 2026) const;
    friend istream& operator>>(istream& in, Ngay& n);
    friend ostream& operator<<(ostream& out, const Ngay& n);
};

class NhanVien {
protected:
    string hoTen;
    Ngay ngaySinh;
    double luong;
public:
    /* INPUT: không có. OUTPUT: không có. Ý tưởng: lớp cha dùng đa hình. */
    NhanVien();
    virtual ~NhanVien();
    /* INPUT: bàn phím. OUTPUT: thông tin chung. Ý tưởng: nhập họ tên, ngày sinh. */
    virtual void nhap();
    /* INPUT: không có. OUTPUT: in thông tin. Ý tưởng: xuất dữ liệu chung. */
    virtual void xuat() const;
    /* INPUT: không có. OUTPUT: lương. Ý tưởng: hàm ảo thuần túy cho từng loại NV. */
    virtual double tinhLuong() = 0;
    double getLuong() const;
    int getTuoi() const;
};

class NhanVienSanXuat : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;
public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() override;
};

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() override;
};
#endif