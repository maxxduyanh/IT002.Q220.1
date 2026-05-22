#include "NongTrai.h"
#include <cstdlib>
#include <ctime>

GiaSuc::GiaSuc(int sl) : soLuong(sl) {}
GiaSuc::~GiaSuc() {}
void GiaSuc::nhap() { cout << "Nhap so luong: "; cin >> soLuong; }
int GiaSuc::getSoLuong() const { return soLuong; }
void GiaSuc::capNhatSoLuong(int them) { soLuong += them; }

void Bo::keu() const { cout << "Bo keu: Um bo!\n"; }
int Bo::sinhCon() const { return soLuong * (rand() % 2 + 1); }
int Bo::choSua() const { return soLuong * (rand() % 21); }

void Cuu::keu() const { cout << "Cuu keu: Be be!\n"; }
int Cuu::sinhCon() const { return soLuong * (rand() % 2 + 1); }
int Cuu::choSua() const { return soLuong * (rand() % 6); }

void De::keu() const { cout << "De keu: Beee!\n"; }
int De::sinhCon() const { return soLuong * (rand() % 2 + 1); }
int De::choSua() const { return soLuong * (rand() % 11); }