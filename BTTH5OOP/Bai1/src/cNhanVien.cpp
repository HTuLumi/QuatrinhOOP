#include "cNhanVien.h"
#include <iomanip>

cNhanVien::cNhanVien() {
    hoTen = "";
    ngaySinh = "";
    luong = 0;
}

cNhanVien::~cNhanVien() {}

void cNhanVien::Nhap() {
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
}

void cNhanVien::Xuat() {
    cout << "Ho ten: " << hoTen << " | Ngay sinh: " << ngaySinh
         << " | Luong: " << fixed << setprecision(0) << luong << " VND";
}

double cNhanVien::getLuong() const {
    return luong;
}

bool cNhanVien::isNVSX() const {
    return false;
}
