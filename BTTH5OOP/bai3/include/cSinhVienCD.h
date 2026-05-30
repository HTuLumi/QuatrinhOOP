#ifndef CSINHVIENCD_H_INCLUDED
#define CSINHVIENCD_H_INCLUDED
#include "cSinhVien.h"

class cSinhVienCD : public cSinhVien {
private:
    double diemThiTotNghiep;
public:
    cSinhVienCD();
    void Nhap() override;
    void Xuat() override;
    bool KiemTraTotNghiep() override;
    int LoaiSV() const override;
};

#endif // CSINHVIENCD_H_INCLUDED
