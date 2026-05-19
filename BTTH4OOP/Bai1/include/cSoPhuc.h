#ifndef CSOPHUC_H_INCLUDED
#define CSOPHUC_H_INCLUDED
#include <iostream>

using namespace std;

class cSoPhuc {
private:
    double thuc;
    double ao;
public:
    // Phương thức thiết lập duy nhất có tham số mặc định
    cSoPhuc(double thuc = 0, double ao = 0);

    // Toán tử toán học
    cSoPhuc operator+(const cSoPhuc& other) const;
    cSoPhuc operator-(const cSoPhuc& other) const;
    cSoPhuc operator*(const cSoPhuc& other) const;
    cSoPhuc operator/(const cSoPhuc& other) const;

    // Toán tử gán và so sánh
    cSoPhuc& operator=(const cSoPhuc& other);
    bool operator!=(const cSoPhuc& other) const;

    // Toán tử xuất/nhập
    friend ostream& operator<<(ostream& os, const cSoPhuc& sp);
    friend istream& operator>>(istream& is, cSoPhuc& sp);
};

#endif // CSOPHUC_H_INCLUDED
