#include <iostream>
#include "CDaThuc.h"

using namespace std;

int main() {
    CDaThuc dt1, dt2;

    cout << "NHAP DA THUC 1" << endl;
    cin >> dt1;
    cout << "\nNHAP DA THUC 2" << endl;
    cin >> dt2;

    cout << "\nDa thuc 1: P(x) = " << dt1 << endl;
    cout << "Da thuc 2: Q(x) = " << dt2 << endl;

    cout << "\nCAC PHEP TOAN" << endl;
    CDaThuc tong = dt1 + dt2; // Gọi copy constructor lúc return và operator=
    CDaThuc hieu = dt1 - dt2;

    cout << "P(x) + Q(x) = " << tong << endl;
    cout << "P(x) - Q(x) = " << hieu << endl;

    double x;
    cout << "\nNhap gia tri x de tinh P(x): ";
    cin >> x;
    // Gọi nạp chồng toán tử ()
    cout << "P(" << x << ") = " << dt1(x) << endl;

    return 0;
}
