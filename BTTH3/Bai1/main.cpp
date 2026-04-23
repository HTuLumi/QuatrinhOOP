#include <iostream>
#include "cTamGiac.h"

using namespace std;

int main() {
    cTamGiac tg;
    cout << "NHAP TAM GIAC\n";
    tg.Nhap();

    if (tg.KiemTraHopLe()) {
        cout << "\nToa do tam giac: ";
        tg.Xuat();

        cout << "Loai tam giac: ";
        tg.KiemTraLoai();

        cout << "Chu vi: " << tg.TinhChuVi() << "\n";
        cout << "Dien tich: " << tg.TinhDienTich() << "\n";

        cout << "\nTINH TIEN TAM GIAC\n";
        double dx, dy;
        cout << "Nhap vector tinh tien (dx dy): ";
        cin >> dx >> dy;
        tg.TinhTien(dx, dy);
        cout << "Sau khi tinh tien: ";
        tg.Xuat();

        cout << "\nQUAY TAM GIAC\n";
        double goc;
        cout << "Nhap goc quay (do): ";
        cin >> goc;
        tg.Quay(goc);
        cout << "Sau khi quay: ";
        tg.Xuat();

        cout << "\nPHONG TO / THU NHO\n";
        double k;
        cout << "Nhap he so k: ";
        cin >> k;
        tg.PhongToThuNho(k);
        cout << "Sau khi phong to/thu nho: ";
        tg.Xuat();
    } else {
        cout << "\nBa diem khong tao thanh mot tam giac!\n";
    }

    return 0;
}

