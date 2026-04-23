#ifndef CNHANVIENSX_H_INCLUDED
#define CNHANVIENSX_H_INCLUDED
#include <string>

using namespace std;

struct Ngay {
    int d, m, y;
};

class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    Ngay ngaySinh;
    int soSanPham;
    double donGia;

public:
    cNhanVienSX();
    ~cNhanVienSX();

    void Nhap();
    void Xuat();
    double TinhLuong();
    Ngay GetNgaySinh();
};

#endif // CNHANVIENSX_H_INCLUDED
