#ifndef CVECTOR_H_INCLUDED
#define CVECTOR_H_INCLUDED
#include <iostream>

using namespace std;

class CVector {
private:
    int n;       // Số chiều của vector
    double* v;   // Mảng động lưu các thành phần

public:
    int getKichThuoc() const;
    double operator[](int i) const;
    void setPhanTu(int i, double val);
    CVector();
    CVector(int n);
    CVector(const CVector& other); // Copy constructor
    ~CVector();                    // Destructor

    // Toán tử gán
    CVector& operator=(const CVector& other);

    // Các toán tử toán học
    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;

    // Tích vô hướng của 2 vector
    double operator*(const CVector& other) const;

    // Nhân vector với một số thực (k * V)
    CVector operator*(double k) const;

    // Toán tử nhập xuất
    friend ostream& operator<<(ostream& os, const CVector& vec);
    friend istream& operator>>(istream& is, CVector& vec);
};

#endif // CVECTOR_H_INCLUDED
