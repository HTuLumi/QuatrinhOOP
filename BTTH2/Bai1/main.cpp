#include <iostream>
#include "NgayThang.h"
#include "NgayThang.cpp"

using namespace std;

int main() {
    NgayThang ngay;
    ngay.Nhap();
    cout<< "Ngay da nhap : ";
    ngay.Xuat();
    cout << "Ngay ke tiep la: ";
    NgayThang ngaytiep = ngay.NgayThangNamTiepTheo();
    ngaytiep.Xuat();
    return 0;
}
