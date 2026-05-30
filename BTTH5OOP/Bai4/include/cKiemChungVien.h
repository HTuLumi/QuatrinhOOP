#ifndef CKIEMCHUNGVIEN_H_INCLUDED
#define CKIEMCHUNGVIEN_H_INCLUDED
#include "cNhanVien.h"

class cKiemChungVien : public cNhanVien {
private:
    int soLoi;
public:
    cKiemChungVien();
    void Nhap() override;
    void Xuat() override;
    void TinhLuong() override;
    int LoaiNV() const override;
};

#endif // CKIEMCHUNGVIEN_H_INCLUDED
