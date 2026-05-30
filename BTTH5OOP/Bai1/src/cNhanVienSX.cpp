#include "cNhanVienSX.h"

cNhanVienSX::cNhanVienSX() : cNhanVien() {
    luongCanBan = 0;
    soSanPham = 0;
}

void cNhanVienSX::Nhap() {
    cout << "[NHAP NHAN VIEN SAN XUAT]\n";
    cNhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

void cNhanVienSX::Xuat() {
    cout << "[NVSX] ";
    cNhanVien::Xuat();
    cout << " (SP: " << soSanPham << ")\n";
}

void cNhanVienSX::TinhLuong() {
    luong = luongCanBan + soSanPham * 5000;
}

bool cNhanVienSX::isNVSX() const {
    return true;
}
