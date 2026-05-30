#include <iostream>
#include <vector>
#include <iomanip>
#include "cNhanVienSX.h"
#include "cNhanVienVP.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap tong so luong nhan vien: ";
    cin >> n;

    vector<cNhanVien*> danhSachNV;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---\n";
        cout << "Chon loai (1 - San xuat, 2 - Van phong): ";
        cin >> loai;

        cNhanVien* nv = NULL;
        if (loai == 1) {
            nv = new cNhanVienSX();
        } else if (loai == 2) {
            nv = new cNhanVienVP();
        } else {
            cout << "Loai khong hop le! Vui long nhap lai.\n";
            i--;
            continue;
        }

        nv->Nhap();
        nv->TinhLuong();
        danhSachNV.push_back(nv);
    }

    cout << "\nDANH SACH NHAN VIEN\n";
    double tongLuongCongTy = 0;

    for (int i = 0; i < danhSachNV.size(); i++) {
        danhSachNV[i]->Xuat();
        tongLuongCongTy += danhSachNV[i]->getLuong();
    }

    cout << "\nTONG LUONG CONG TY PHAI TRA: " << fixed << setprecision(0) << tongLuongCongTy << " VND\n";

    cNhanVien* minNVSX = NULL;
    for (int i = 0; i < danhSachNV.size(); i++) {
        if (danhSachNV[i]->isNVSX()) {
            if (minNVSX == NULL || danhSachNV[i]->getLuong() < minNVSX->getLuong()) {
                minNVSX = danhSachNV[i];
            }
        }
    }

    cout << "\nNHAN VIEN SAN XUAT CO LUONG THAP NHAT\n";
    if (minNVSX != NULL) {
        minNVSX->Xuat();
    } else {
        cout << "Khong co Nhan vien san xuat nao trong cong ty!\n";
    }

    for (int i = 0; i < danhSachNV.size(); i++) {
        delete danhSachNV[i];
    }

    return 0;
}
