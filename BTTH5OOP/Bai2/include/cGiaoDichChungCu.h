#ifndef CGIAODICHCHUNGCU_H_INCLUDED
#define CGIAODICHCHUNGCU_H_INCLUDED
#include "cGiaoDich.h"

class cGiaoDichChungCu : public cGiaoDich {
private:
    string maCan;
    int tang;
public:
    cGiaoDichChungCu();
    void Nhap() override;
    void Xuat() override;
    void TinhThanhTien() override;
    int getLoaiGD() const override;
};

#endif // CGIAODICHCHUNGCU_H_INCLUDED
