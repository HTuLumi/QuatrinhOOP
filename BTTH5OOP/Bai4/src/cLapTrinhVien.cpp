#include "cLapTrinhVien.h"

cLapTrinhVien::cLapTrinhVien() : cNhanVien(), soGioOvertime(0) {}

void cLapTrinhVien::Nhap() {
    cout << "\nNHAP LAP TRINH VIEN\n";
    cNhanVien::Nhap();
    cout << "Nhap so gio overtime: "; cin >> soGioOvertime;
}

void cLapTrinhVien::Xuat() {
    cout << "[LTV] ";
    cNhanVien::Xuat();
    cout << " | OT: " << soGioOvertime << "h\n";
}

void cLapTrinhVien::TinhLuong() {
    luong = luongCoBan + soGioOvertime * 200000;
}

int cLapTrinhVien::LoaiNV() const { return 1; }
