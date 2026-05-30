#ifndef CSINHVIEN_H_INCLUDED
#define CSINHVIEN_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class cSinhVien {
protected:
    string maSV;
    string hoTen;
    string diaChi;
    int tongTinChi;
    double diemTB;

public:
    cSinhVien();
    virtual ~cSinhVien();

    virtual void Nhap();
    virtual void Xuat();
    virtual bool KiemTraTotNghiep() = 0; // Phương thức thuần ảo

    double getDiemTB() const;
    // Quy ước: 1 là Cao đẳng, 2 là Đại học
    virtual int LoaiSV() const = 0;
};

#endif // CSINHVIEN_H_INCLUDED
