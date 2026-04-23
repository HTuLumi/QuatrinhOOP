#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main() {
    cDaThuc dt1, dt2;

    cout << "NHAP DA THUC 1\n";
    dt1.Nhap();

    cout << "\nNHAP DA THUC 2\n";
    dt2.Nhap();

    cout << "\nDA THUC 1: ";
    dt1.Xuat();

    cout << "DA THUC 2: ";
    dt2.Xuat();

    double x;
    cout << "\nNhap gia tri x de tinh P(x) cho DA THUC 1: ";
    cin >> x;
    cout << "Gia tri P(" << x << ") = " << dt1.TinhGiaTri(x) << "\n";

    cDaThuc tong = dt1.Cong(dt2);
    cout << "\nTONG HAI DA THUC: ";
    tong.Xuat();

    cDaThuc hieu = dt1.Tru(dt2);
    cout << "HIEU HAI DA THUC: ";
    hieu.Xuat();

    return 0;
}
