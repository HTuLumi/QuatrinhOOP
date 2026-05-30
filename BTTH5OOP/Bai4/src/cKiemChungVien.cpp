#include "cKiemChungVien.h"

cKiemChungVien::cKiemChungVien() : cNhanVien(), soLoi(0) {}

void cKiemChungVien::Nhap() {
    cout << "\nNHAP KIEM CHUNG VIEN\n";
    cNhanVien::Nhap();
    cout << "Nhap so loi phat hien: "; cin >> soLoi;
}

void cKiemChungVien::Xuat() {
    cout << "[KCV] ";
    cNhanVien::Xuat();
    cout << " | So loi: " << soLoi << "\n";
}

void cKiemChungVien::TinhLuong() {
    luong = luongCoBan + soLoi * 50000;
}

int cKiemChungVien::LoaiNV() const { return 2; }
