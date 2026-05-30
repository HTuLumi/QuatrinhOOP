#ifndef CNHANVIEN_H_INCLUDED
#define CNHANVIEN_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class cNhanVien {
protected:
    string hoTen;
    string ngaySinh;
    double luong;

public:
    cNhanVien();
    virtual ~cNhanVien();

    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhLuong() = 0;

    double getLuong() const;
    virtual bool isNVSX() const;
};

#endif // CNHANVIEN_H_INCLUDED
