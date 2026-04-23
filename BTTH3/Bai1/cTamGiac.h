#ifndef CTAMGIAC_H_INCLUDED
#define CTAMGIAC_H_INCLUDED

struct Diem {
    double x, y;
};

class cTamGiac {
private:
    Diem A, B, C;
public:
    cTamGiac();
    ~cTamGiac();

    void Nhap();
    void Xuat();
    bool KiemTraHopLe();
    void KiemTraLoai();
    double TinhChuVi();
    double TinhDienTich();
    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongToThuNho(double k);
};

#endif // CTAMGIAC_H_INCLUDED
