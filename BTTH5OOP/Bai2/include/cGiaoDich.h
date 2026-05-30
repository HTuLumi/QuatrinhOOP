#ifndef CGIAODICH_H_INCLUDED
#define CGIAODICH_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class cGiaoDich {
protected:
    string maGD;
    int ngay, thang, nam;
    double donGia;
    double dienTich;
    double thanhTien;

public:
    cGiaoDich();
    virtual ~cGiaoDich();

    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhThanhTien() = 0;

    double getThanhTien() const;
    int getThang() const;
    int getNam() const;

    // 1: Đất, 2: Nhà Phố, 3: Chung Cư
    virtual int getLoaiGD() const = 0;
};

#endif // CGIAODICH_H_INCLUDED
