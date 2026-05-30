#include "cSinhVienDH.h"

cSinhVienDH::cSinhVienDH() : cSinhVien(), tenLuanVan(""), diemLuanVan(0) {}

void cSinhVienDH::Nhap() {
    cout << "\nNHAP SINH VIEN DAI HOC\n";
    cSinhVien::Nhap();
    cin.ignore();
    cout << "Nhap ten luan van: "; getline(cin, tenLuanVan);
    cout << "Nhap diem luan van: "; cin >> diemLuanVan;
}

void cSinhVienDH::Xuat() {
    cout << "[DAI HOC]  ";
    cSinhVien::Xuat();
    cout << " | Luan van: " << tenLuanVan << " (Diem: " << diemLuanVan << ")\n";
}

bool cSinhVienDH::KiemTraTotNghiep() {
    return (tongTinChi >= 170 && diemTB >= 5.0 && diemLuanVan >= 5.0);
}

int cSinhVienDH::LoaiSV() const { return 2; }
