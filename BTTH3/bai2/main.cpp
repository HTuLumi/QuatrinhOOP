#include <iostream>
#include "cDaGiac.h"

using namespace std;

int main() {
    cDaGiac dg;

    cout << "NHAP THONG TIN DA GIAC\n";
    dg.Nhap();

    cout << "\nTOA DO DA GIAC VUA NHAP:\n";
    dg.Xuat();

    cout << "Chu vi: " << dg.TinhChuVi() << "\n";
    cout << "Dien tich: " << dg.TinhDienTich() << "\n";

    cout << "\nTINH TIEN DA GIAC\n";
    double dx, dy;
    cout << "Nhap vector tinh tien (dx dy): ";
    cin >> dx >> dy;
    dg.TinhTien(dx, dy);
    cout << "Toa do sau khi tinh tien: ";
    dg.Xuat();

    cout << "\nQUAY DA GIAC\n";
    double goc;
    cout << "Nhap goc quay (do): ";
    cin >> goc;
    dg.Quay(goc);
    cout << "Toa do sau khi quay: ";
    dg.Xuat();

    cout << "\nPHONG TO THU NHO DA GIAC\n";
    double k;
    cout << "Nhap he so k: ";
    cin >> k;
    dg.PhongToThuNho(k);
    cout << "Toa do sau khi bien doi: ";
    dg.Xuat();

    return 0;
}
