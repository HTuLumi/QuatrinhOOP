#include "cGiaoDich.h"
#include <iomanip>

cGiaoDich::cGiaoDich() : ngay(1), thang(1), nam(2000), donGia(0), dienTich(0), thanhTien(0) {}

cGiaoDich::~cGiaoDich() {}

void cGiaoDich::Nhap() {
    cout << "Nhap ma GD: "; cin >> maGD;
    cout << "Nhap ngay, thang, nam giao dich: "; cin >> ngay >> thang >> nam;
    cout << "Nhap don gia: "; cin >> donGia;
    cout << "Nhap dien tich: "; cin >> dienTich;
}

void cGiaoDich::Xuat() {
    cout << "Ma GD: " << maGD << " | Ngay: " << ngay << "/" << thang << "/" << nam
         << " | Don gia: " << fixed << setprecision(0) << donGia
         << " | Dien tich: " << dienTich
         << " | Thanh tien: " << thanhTien;
}

double cGiaoDich::getThanhTien() const { return thanhTien; }
int cGiaoDich::getThang() const { return thang; }
int cGiaoDich::getNam() const { return nam; }
