#ifndef CNHANVIENSX_H_INCLUDED
#define CNHANVIENSX_H_INCLUDED
#include "cNhanVien.h"

class cNhanVienSX : public cNhanVien {
private:
    double luongCanBan;
    int soSanPham;

public:
    cNhanVienSX();
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
    bool isNVSX() const override;
};

#endif // CNHANVIENSX_H_INCLUDED
