#ifndef CDAGIAC_H_INCLUDED
#define CDAGIAC_H_INCLUDED

struct Diem {
    double x, y;
};

class cDaGiac {
private:
    int n;
    Diem *Dinh;
public:
    cDaGiac();
    ~cDaGiac();

    void Nhap();
    void Xuat();
    double TinhChuVi();
    double TinhDienTich();
    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongToThuNho(double k);
};

#endif // CDAGIAC_H_INCLUDED
