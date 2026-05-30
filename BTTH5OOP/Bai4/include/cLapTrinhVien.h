#ifndef CLAPTRINHVIEN_H_INCLUDED
#define CLAPTRINHVIEN_H_INCLUDED
#include "cNhanVien.h"

class cLapTrinhVien : public cNhanVien {
private:
    int soGioOvertime;
public:
    cLapTrinhVien();
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
    int LoaiNV() const override;
};

#endif // CLAPTRINHVIEN_H_INCLUDED
