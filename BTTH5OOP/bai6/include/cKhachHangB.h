#ifndef CKHACHHANGB_H_INCLUDED
#define CKHACHHANGB_H_INCLUDED
#include "cKhachHang.h"

class cKhachHangB : public cKhachHang {
private:
    int soNam;
public:
    cKhachHangB();
    void Nhap(ifstream& in) override;
    void TinhTien() override;
};

#endif // CKHACHHANGB_H_INCLUDED
