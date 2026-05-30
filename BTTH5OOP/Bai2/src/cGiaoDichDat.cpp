#include "cGiaoDichDat.h"

cGiaoDichDat::cGiaoDichDat() : loaiDat('B') {}

void cGiaoDichDat::Nhap() {
    cout << "\nNHAP GIAO DICH DAT\n";
    cGiaoDich::Nhap();
    cout << "Nhap loai dat (A, B, C): "; cin >> loaiDat;
}

void cGiaoDichDat::Xuat() {
    cout << "[DAT] ";
    cGiaoDich::Xuat();
    cout << " | Loai dat: " << loaiDat << "\n";
}

void cGiaoDichDat::TinhThanhTien() {
    if (loaiDat == 'A' || loaiDat == 'a') {
        thanhTien = dienTich * donGia * 1.5;
    } else {
        thanhTien = dienTich * donGia;
    }
}

int cGiaoDichDat::getLoaiGD() const { return 1; }
