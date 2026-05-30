#include "cGiaoDichChungCu.h"

cGiaoDichChungCu::cGiaoDichChungCu() : maCan(""), tang(1) {}

void cGiaoDichChungCu::Nhap() {
    cout << "\nNHAP GIAO DICH CHUNG CU\n";
    cGiaoDich::Nhap();
    cout << "Nhap ma can ho: "; cin >> maCan;
    cout << "Nhap vi tri tang: "; cin >> tang;
}

void cGiaoDichChungCu::Xuat() {
    cout << "[CHUNG CU] ";
    cGiaoDich::Xuat();
    cout << " | Ma can: " << maCan << " | Tang: " << tang << "\n";
}

void cGiaoDichChungCu::TinhThanhTien() {
    if (tang == 1) {
        thanhTien = dienTich * donGia * 2;
    } else if (tang >= 15) {
        thanhTien = dienTich * donGia * 1.2;
    } else {
        thanhTien = dienTich * donGia;
    }
}

int cGiaoDichChungCu::getLoaiGD() const { return 3; }
