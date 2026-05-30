#ifndef CNHANVIEN_H_INCLUDED
#define CNHANVIEN_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class cNhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;
    double luong;

public:
    cNhanVien();
    virtual ~cNhanVien();

    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhLuong() = 0; // Phương thức thuần ảo

    double getLuong() const;
    virtual int LoaiNV() const = 0; // 1: LTV, 2: KCV
};

#endif // CNHANVIEN_H_INCLUDED
