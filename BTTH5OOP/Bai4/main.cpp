#include <iostream>
#include <vector>
#include <iomanip>
#include "cLapTrinhVien.h"
#include "cKiemChungVien.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    vector<cNhanVien*> dsNV;
    double tongLuong = 0;

    // a. Nhập danh sách
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon loai NV (1: Lap Trinh Vien, 2: Kiem Chung Vien) cho NV thu " << i + 1 << ": ";
        cin >> loai;

        cNhanVien* nv = NULL;
        if (loai == 1) nv = new cLapTrinhVien();
        else if (loai == 2) nv = new cKiemChungVien();
        else {
            cout << "Loai khong hop le!\n";
            i--; continue;
        }

        nv->Nhap();
        nv->TinhLuong();
        dsNV.push_back(nv);
        tongLuong += nv->getLuong();
    }

    // b. Xuất danh sách
    cout << "\nDANH SACH NHAN VIEN" << endl;
    for (int i = 0; i < dsNV.size(); i++) {
        dsNV[i]->Xuat();
    }

    // c. Danh sách NV có lương < Lương TB
    double luongTB = (dsNV.size() > 0) ? (tongLuong / dsNV.size()) : 0;
    cout << "\n* Muc luong trung binh toan cong ty: " << fixed << setprecision(0) << luongTB << " VND";
    cout << "\nNV CO LUONG THAP HON TB" << endl;
    bool coNVThapHonTB = false;
    for (int i = 0; i < dsNV.size(); i++) {
        if (dsNV[i]->getLuong() < luongTB) {
            dsNV[i]->Xuat();
            coNVThapHonTB = true;
        }
    }
    if (!coNVThapHonTB) cout << "Khong co nhan vien nao co luong thap hon trung binh.\n";

    // d, e, f, g. Thống kê chi tiết
    cNhanVien* maxNV = NULL;
    cNhanVien* minNV = NULL;
    cNhanVien* maxLTV = NULL;
    cNhanVien* minKCV = NULL;

    for (int i = 0; i < dsNV.size(); i++) {
        // Xét max/min toàn công ty
        if (maxNV == NULL || dsNV[i]->getLuong() > maxNV->getLuong()) maxNV = dsNV[i];
        if (minNV == NULL || dsNV[i]->getLuong() < minNV->getLuong()) minNV = dsNV[i];

        // Xét LTV max
        if (dsNV[i]->LoaiNV() == 1) {
            if (maxLTV == NULL || dsNV[i]->getLuong() > maxLTV->getLuong()) maxLTV = dsNV[i];
        }
        // Xét KCV min
        else if (dsNV[i]->LoaiNV() == 2) {
            if (minKCV == NULL || dsNV[i]->getLuong() < minKCV->getLuong()) minKCV = dsNV[i];
        }
    }

    if (maxNV) { cout << "* NV luong cao nhat cong ty:\n  "; maxNV->Xuat(); }
    if (minNV) { cout << "* NV luong thap nhat cong ty:\n  "; minNV->Xuat(); }


    if (maxLTV) { cout << "* Lap Trinh Vien luong cao nhat:\n  "; maxLTV->Xuat(); }
    else { cout << "* Khong co Lap Trinh Vien nao!\n"; }

    if (minKCV) { cout << "* Kiem Chung Vien luong thap nhat:\n  "; minKCV->Xuat(); }
    else { cout << "* Khong co Kiem Chung Vien nao!\n"; }

    // Giải phóng bộ nhớ
    for (int i = 0; i < dsNV.size(); i++) {
        delete dsNV[i];
    }

    return 0;
}
