#include "cNhanVienVP.h"

cNhanVienVP::cNhanVienVP() : cNhanVien() {
    soNgayLamViec = 0;
}

void cNhanVienVP::Nhap() {
    cout << "[NHAP NHAN VIEN VAN PHONG]\n";
    cNhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
}

void cNhanVienVP::Xuat() {
    cout << "[NVVP] ";
    cNhanVien::Xuat();
    cout << " (Ngay lam: " << soNgayLamViec << ")\n";
}

void cNhanVienVP::TinhLuong() {
    luong = soNgayLamViec * 100000;
}

bool cNhanVienVP::isNVSX() const {
    return false;
}
