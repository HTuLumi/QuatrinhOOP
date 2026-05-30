#include <iostream>
#include <vector>
#include "cSinhVienCD.h"
#include "cSinhVienDH.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    vector<cSinhVien*> dsSV;

    // a. Nhập danh sách
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nChon he dao tao (1: Cao dang, 2: Dai hoc) cho SV thu " << i + 1 << ": ";
        cin >> loai;

        cSinhVien* sv = NULL;
        if (loai == 1) sv = new cSinhVienCD();
        else if (loai == 2) sv = new cSinhVienDH();
        else {
            cout << "He dao tao khong hop le!\n";
            i--; continue;
        }

        sv->Nhap();
        dsSV.push_back(sv);
    }

    // b. Xuất danh sách
    cout << "\nDANH SACH TONG HOP" << endl;
    for (int i = 0; i < dsSV.size(); i++) {
        dsSV[i]->Xuat();
    }

    // c & d. Phân loại tốt nghiệp
    cout << "\nDANH SACH DU DIEU KIEN TOT NGHIEP" << endl;
    for (int i = 0; i < dsSV.size(); i++) {
        if (dsSV[i]->KiemTraTotNghiep()) dsSV[i]->Xuat();
    }

    cout << "\nDANH SACH KHONG DU DIEU KIEN TOT NGHIEP" << endl;
    for (int i = 0; i < dsSV.size(); i++) {
        if (!dsSV[i]->KiemTraTotNghiep()) dsSV[i]->Xuat();
    }

    // e & f & g. Xử lý Thống kê
    cSinhVien* maxDiemCD = NULL;
    cSinhVien* maxDiemDH = NULL;
    int rotCD = 0, rotDH = 0;

    for (int i = 0; i < dsSV.size(); i++) {
        if (dsSV[i]->LoaiSV() == 1) { // Cao Đẳng
            if (!dsSV[i]->KiemTraTotNghiep()) rotCD++;
            if (maxDiemCD == NULL || dsSV[i]->getDiemTB() > maxDiemCD->getDiemTB()) {
                maxDiemCD = dsSV[i];
            }
        } else { // Đại Học
            if (!dsSV[i]->KiemTraTotNghiep()) rotDH++;
            if (maxDiemDH == NULL || dsSV[i]->getDiemTB() > maxDiemDH->getDiemTB()) {
                maxDiemDH = dsSV[i];
            }
        }
    }

    cout << "\nTHONG KE" << endl;
    if (maxDiemCD != NULL) {
        cout << "* Sinh vien CAO DANG co diem TB cao nhat:\n  ";
        maxDiemCD->Xuat();
    }

    if (maxDiemDH != NULL) {
        cout << "* Sinh vien DAI HOC co diem TB cao nhat:\n  ";
        maxDiemDH->Xuat();
    }

    cout << "\n* So luong sinh vien KHONG du dieu kien tot nghiep:\n";
    cout << "  - He Cao Dang: " << rotCD << " sinh vien\n";
    cout << "  - He Dai Hoc: " << rotDH << " sinh vien\n";

    for (int i = 0; i < dsSV.size(); i++) {
        delete dsSV[i];
    }

    return 0;
}
