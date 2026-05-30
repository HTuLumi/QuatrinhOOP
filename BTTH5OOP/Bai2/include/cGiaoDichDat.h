#ifndef CGIAODICHDAT_H_INCLUDED
#define CGIAODICHDAT_H_INCLUDED
#include "cGiaoDich.h"

class cGiaoDichDat : public cGiaoDich {
private:
    char loaiDat; // 'A', 'B', 'C'
public:
    cGiaoDichDat();
    void Nhap() override;
    void Xuat() override;
    void TinhThanhTien() override;
    int getLoaiGD() const override;
};

#endif // CGIAODICHDAT_H_INCLUDED
