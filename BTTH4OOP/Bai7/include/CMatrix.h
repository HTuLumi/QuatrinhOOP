#ifndef CMATRIX_H_INCLUDED
#define CMATRIX_H_INCLUDED
#include <iostream>
#include "CVector.h" // Nhúng thư viện Vector từ Bài 6 vào để nhân

using namespace std;

class CMatrix {
private:
    int rows;
    int cols;
    double** data;

public:
    CMatrix();
    CMatrix(int r, int c);
    CMatrix(const CMatrix& other); // Copy constructor
    ~CMatrix();                    // Destructor

    // Toán tử gán
    CMatrix& operator=(const CMatrix& other);

    // Toán tử với Ma trận
    CMatrix operator+(const CMatrix& other) const;
    CMatrix operator-(const CMatrix& other) const;
    CMatrix operator*(const CMatrix& other) const;

    // Tích Ma trận và Vector
    CVector operator*(const CVector& v) const;

    // Toán tử nhập xuất
    friend ostream& operator<<(ostream& os, const CMatrix& m);
    friend istream& operator>>(istream& is, CMatrix& m);
};

#endif // CMATRIX_H_INCLUDED
