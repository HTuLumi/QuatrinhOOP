#include <iostream>
#include <iomanip>
#include "cNhanVienSX.h"

using namespace std;

bool LonTuoiHon(Ngay a, Ngay b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n;

    cNhanVienSX* ds = new cNhanVienSX[n];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }

    cout << "\nDANH SACH NHAN VIEN SAN XUAT:\n";
    cout << left << setw(10) << "Ma NV" << setw(25) << "Ho ten"
         << right << setw(10) << "Ngay sinh" << setw(15) << "So SP"
         << setw(15) << "Don gia" << setw(15) << "Luong" << "\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    double minLuong = ds[0].TinhLuong();
    for (int i = 1; i < n; i++) {
        if (ds[i].TinhLuong() < minLuong) {
            minLuong = ds[i].TinhLuong();
        }
    }

    cout << "\nNHAN VIEN CO LUONG THAP NHAT:\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhLuong() == minLuong) {
            ds[i].Xuat();
        }
    }

    double tongLuong = 0;
    for (int i = 0; i < n; i++) {
        tongLuong += ds[i].TinhLuong();
    }
    cout << "\nTong luong cong ty phai tra: " << fixed << setprecision(0) << tongLuong << "\n";

    int indexLonTuoiNhat = 0;
    for (int i = 1; i < n; i++) {
        if (LonTuoiHon(ds[i].GetNgaySinh(), ds[indexLonTuoiNhat].GetNgaySinh())) {
            indexLonTuoiNhat = i;
        }
    }
    cout << "\nNHAN VIEN CO TUOI CAO NHAT:\n";
    ds[indexLonTuoiNhat].Xuat();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].TinhLuong() > ds[j].TinhLuong()) {
                swap(ds[i], ds[j]);
            }
        }
    }

    cout << "\nDANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG:\n";
    cout << left << setw(10) << "Ma NV" << setw(25) << "Ho ten"
         << right << setw(10) << "Ngay sinh" << setw(15) << "So SP"
         << setw(15) << "Don gia" << setw(15) << "Luong" << "\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
    }

    delete[] ds;
    return 0;
}
