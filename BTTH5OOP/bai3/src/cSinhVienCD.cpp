#include "cSinhVienCD.h"

cSinhVienCD::cSinhVienCD() : cSinhVien(), diemThiTotNghiep(0) {}

void cSinhVienCD::Nhap() {
    cout << "\nNHAP SINH VIEN CAO DANG\n";
    cSinhVien::Nhap();
    cout << "Nhap diem thi tot nghiep: "; cin >> diemThiTotNghiep;
}

void cSinhVienCD::Xuat() {
    cout << "[CAO DANG] ";
    cSinhVien::Xuat();
    cout << " | Diem thi TN: " << diemThiTotNghiep << "\n";
}

bool cSinhVienCD::KiemTraTotNghiep() {
    return (tongTinChi >= 120 && diemTB >= 5.0 && diemThiTotNghiep >= 5.0);
}

int cSinhVienCD::LoaiSV() const { return 1; }
