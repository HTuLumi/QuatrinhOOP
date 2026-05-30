#ifndef CGIAODICHNHAPHO_H_INCLUDED
#define CGIAODICHNHAPHO_H_INCLUDED
#include "cGiaoDich.h"

class cGiaoDichNhaPho : public cGiaoDich {
private:
    int loaiNha; // 1: Cao cap, 2: Thuong
    string diaChi;
public:
    cGiaoDichNhaPho();
    void Nhap() override;
    void Xuat() override;
    void TinhThanhTien() override;
    int getLoaiGD() const override;
};

#endif // CGIAODICHNHAPHO_H_INCLUDED
