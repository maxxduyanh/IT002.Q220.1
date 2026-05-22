#ifndef NONGTRAI_H
#define NONGTRAI_H
#include <iostream>
#include <vector>
using namespace std;

class GiaSuc {
protected:
    int soLuong;
public:
    GiaSuc(int sl = 0);
    virtual ~GiaSuc();
    virtual void nhap();
    virtual void keu() const = 0;
    virtual int sinhCon() const = 0;
    virtual int choSua() const = 0;
    int getSoLuong() const;
    void capNhatSoLuong(int them);
};

class Bo : public GiaSuc {
public:
    using GiaSuc::GiaSuc;
    void keu() const override;
    int sinhCon() const override;
    int choSua() const override;
};
class Cuu : public GiaSuc {
public:
    using GiaSuc::GiaSuc;
    void keu() const override;
    int sinhCon() const override;
    int choSua() const override;
};
class De : public GiaSuc {
public:
    using GiaSuc::GiaSuc;
    void keu() const override;
    int sinhCon() const override;
    int choSua() const override;
};
#endif