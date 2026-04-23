#include "cNhanVienSX.h"
#include <iostream>
#include <iomanip>

using namespace std;

cNhanVienSX::cNhanVienSX() {
    maNV = "";
    hoTen = "";
    ngaySinh.d = 1;
    ngaySinh.m = 1;
    ngaySinh.y = 2000;
    soSanPham = 0;
    donGia = 0;
}

cNhanVienSX::~cNhanVienSX() {}

void cNhanVienSX::Nhap() {
    cout << "Nhap ma nhan vien: ";
    cin >> maNV;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> ngaySinh.d >> ngaySinh.m >> ngaySinh.y;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    cout << "Nhap don gia: ";
    cin >> donGia;
}

void cNhanVienSX::Xuat() {
    cout << left << setw(10) << maNV
         << setw(25) << hoTen
         << right << setw(2) << ngaySinh.d << "/" << setw(2) << ngaySinh.m << "/" << setw(4) << ngaySinh.y
         << setw(15) << soSanPham
         << setw(15) << donGia
         << setw(15) << fixed << setprecision(0) << TinhLuong() << "\n";
}

double cNhanVienSX::TinhLuong() {
    return soSanPham * donGia;
}

Ngay cNhanVienSX::GetNgaySinh() {
    return ngaySinh;
}
