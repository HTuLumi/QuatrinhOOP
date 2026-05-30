#ifndef CNHANVIENVP_H_INCLUDED
#define CNHANVIENVP_H_INCLUDED
#include "cNhanVien.h"

class cNhanVienVP : public cNhanVien {
private:
    int soNgayLamViec;

public:
    cNhanVienVP();
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
    bool isNVSX() const override;
};

#endif // CNHANVIENVP_H_INCLUDED
