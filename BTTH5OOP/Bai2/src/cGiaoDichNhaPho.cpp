#include "cGiaoDichNhaPho.h"

cGiaoDichNhaPho::cGiaoDichNhaPho() : loaiNha(2), diaChi("") {}

void cGiaoDichNhaPho::Nhap() {
    cout << "\nNHAP GIAO DICH NHA PHO\n";
    cGiaoDich::Nhap();
    cout << "Nhap loai nha (1: Cao cap, 2: Thuong): "; cin >> loaiNha;
    cin.ignore();
    cout << "Nhap dia chi: "; getline(cin, diaChi);
}

void cGiaoDichNhaPho::Xuat() {
    cout << "[NHA PHO] ";
    cGiaoDich::Xuat();
    cout << " | Loai: " << (loaiNha == 1 ? "Cao cap" : "Thuong")
         << " | Dia chi: " << diaChi << "\n";
}

void cGiaoDichNhaPho::TinhThanhTien() {
    if (loaiNha == 1) {
        thanhTien = dienTich * donGia;
    } else {
        thanhTien = dienTich * donGia * 0.9;
    }
}

int cGiaoDichNhaPho::getLoaiGD() const { return 2; }
