#ifndef CSINHVIENDH_H_INCLUDED
#define CSINHVIENDH_H_INCLUDED
#include "cSinhVien.h"

class cSinhVienDH : public cSinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;
public:
    cSinhVienDH();
    void Nhap() override;
    void Xuat() override;
    bool KiemTraTotNghiep() override;
    int LoaiSV() const override;
};

#endif // CSINHVIENDH_H_INCLUDED
