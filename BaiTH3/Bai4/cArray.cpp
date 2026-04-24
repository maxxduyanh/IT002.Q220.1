#include "cArray.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Input: số nguyên x
// Output: true nếu x là số nguyên tố
// Thuật toán: kiểm tra chia từ 2 → sqrt(x)
bool cArray::LaSoNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

// Input: n
// Output: mảng ngẫu nhiên n phần tử
// Thuật toán: sinh random từ -50 → 50
void cArray::TaoNgauNhien(int n) {
    this->n = n;
    a.resize(n);

    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 101 - 50;
    }
}

// Output: in mảng
void cArray::Xuat() {
    for (int x : a) cout << x << " ";
    cout << endl;
}

// Input: x
// Output: số lần xuất hiện
// Thuật toán: duyệt mảng và đếm
int cArray::Dem(int x) {
    int cnt = 0;
    for (int v : a)
        if (v == x) cnt++;
    return cnt;
}

// Output: true nếu tăng dần
// Thuật toán: kiểm tra a[i] <= a[i+1]
bool cArray::KiemTraTang() {
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1]) return false;
    return true;
}

// Output: số lẻ nhỏ nhất
// Thuật toán: lọc số lẻ rồi tìm min
int cArray::LeNhoNhat() {
    int res = INT_MAX;
    for (int x : a)
        if (x % 2 != 0 && x < res)
            res = x;
    return (res == INT_MAX ? -1 : res);
}

// Output: số nguyên tố lớn nhất
// Thuật toán: duyệt + kiểm tra nguyên tố
int cArray::NguyenToMax() {
    int res = -1;
    for (int x : a)
        if (LaSoNguyenTo(x) && x > res)
            res = x;
    return res;
}

// Output: mảng tăng dần
// Thuật toán: sort (có thể thay bằng bubble/selection nếu yêu cầu)
void cArray::SapXepTang() {
    sort(a.begin(), a.end());
}

// Output: mảng giảm dần
void cArray::SapXepGiam() {
    sort(a.begin(), a.end(), greater<int>());
}