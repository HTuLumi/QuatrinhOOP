#include "cSinhVien.h"
#include <iomanip>

cSinhVien::cSinhVien() {
    maSV = hoTen = diaChi = "";
    tongTinChi = 0;
    diemTB = 0.0;
}

cSinhVien::~cSinhVien() {}

void cSinhVien::Nhap() {
    cout << "Nhap MSSV: "; cin >> maSV;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap dia chi: "; getline(cin, diaChi);
    cout << "Nhap tong so tin chi: "; cin >> tongTinChi;
    cout << "Nhap diem trung binh: "; cin >> diemTB;
}

void cSinhVien::Xuat() {
    cout << "MSSV: " << maSV << " | Ho ten: " << hoTen
         << " | Dia chi: " << diaChi
         << " | Tin chi: " << tongTinChi
         << " | Diem TB: " << fixed << setprecision(2) << diemTB;
}

double cSinhVien::getDiemTB() const {
    return diemTB;
}
