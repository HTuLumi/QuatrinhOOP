#ifndef CPHANSO_H_INCLUDED
#define CPHANSO_H_INCLUDED
#include <iostream>

using namespace std;

class cPhanSo {
private:
    int tu;
    int mau;
    void RutGon(); // Hàm hỗ trợ rút gọn và chuẩn hóa dấu

public:
    // Phương thức thiết lập cho phép số nguyên làm phân số (mẫu = 1)
    cPhanSo(int tu = 0, int mau = 1);

    // Các phép toán số học
    cPhanSo operator+(const cPhanSo& other) const;
    cPhanSo operator-(const cPhanSo& other) const;
    cPhanSo operator*(const cPhanSo& other) const;
    cPhanSo operator/(const cPhanSo& other) const;

    // Các phép toán gán và so sánh
    cPhanSo& operator=(const cPhanSo& other);
    bool operator>(const cPhanSo& other) const;
    bool operator<(const cPhanSo& other) const;

    // Các phép toán nhập xuất
    friend ostream& operator<<(ostream& os, const cPhanSo& ps);
    friend istream& operator>>(istream& is, cPhanSo& ps);
};

#endif // CPHANSO_H_INCLUDED
