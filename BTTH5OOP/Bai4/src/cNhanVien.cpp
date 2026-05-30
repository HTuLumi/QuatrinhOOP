#include "cNhanVien.h"
#include <iomanip>

cNhanVien::cNhanVien() {
    maNV = hoTen = sdt = email = "";
    tuoi = 0;
    luongCoBan = luong = 0;
}

cNhanVien::~cNhanVien() {}

void cNhanVien::Nhap() {
    cout << "Nhap ma NV: "; cin >> maNV;
    cin.ignore(); // Xóa phím Enter bị thừa để getline không bị trôi
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap tuoi: "; cin >> tuoi;
    cin.ignore();
    cout << "Nhap SDT: "; getline(cin, sdt);
    cout << "Nhap Email: "; getline(cin, email);
    cout << "Nhap luong co ban: "; cin >> luongCoBan;
}

void cNhanVien::Xuat() {
    cout << "Ma NV: " << maNV << " | Ten: " << hoTen
         << " | Tuoi: " << tuoi << " | SDT: " << sdt
         << " | Email: " << email << "\n"
         << "      Luong CB: " << fixed << setprecision(0) << luongCoBan
         << " | Luong thuc lanh: " << luong;
}

double cNhanVien::getLuong() const {
    return luong;
}
