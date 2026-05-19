#ifndef CDATHUC_H_INCLUDED
#define CDATHUC_H_INCLUDED
#include <iostream>

using namespace std;

class CDaThuc {
private:
    int n;       // Bậc của đa thức
    double* a;   // Con trỏ mảng động lưu các hệ số (từ a[0] đến a[n])

public:
    CDaThuc();
    CDaThuc(int bac);
    CDaThuc(const CDaThuc& other); // Copy constructor
    ~CDaThuc();                    // Destructor

    // Toán tử gán
    CDaThuc& operator=(const CDaThuc& other);

    // Các toán tử toán học
    CDaThuc operator+(const CDaThuc& other) const;
    CDaThuc operator-(const CDaThuc& other) const;

    // Nạp chồng toán tử () để tính giá trị đa thức tại x
    double operator()(double x) const;

    // Toán tử nhập xuất
    friend ostream& operator<<(ostream& os, const CDaThuc& dt);
    friend istream& operator>>(istream& is, CDaThuc& dt);
};

#endif // CDATHUC_H_INCLUDED
