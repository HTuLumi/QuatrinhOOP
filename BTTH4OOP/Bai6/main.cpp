#include <iostream>
#include "CVector.h"

using namespace std;

int main() {
    CVector v1, v2;

    cout << "NHAP VECTOR 1" << endl;
    cin >> v1;
    cout << "\nNHAP VECTOR 2" << endl;
    cin >> v2;

    cout << "\nVector 1: V1 = " << v1 << endl;
    cout << "Vector 2: V2 = " << v2 << endl;

    cout << "\nCAC PHEP TOAN" << endl;
    CVector tong = v1 + v2;
    CVector hieu = v1 - v2;

    cout << "V1 + V2 = " << tong << endl;
    cout << "V1 - V2 = " << hieu << endl;
    cout << "Tich vo huong V1 * V2 = " << v1 * v2 << endl;

    double k;
    cout << "\nNhap mot so thuc k de nhan voi V1: ";
    cin >> k;
    cout << "k * V1 = " << v1 * k << endl;

    return 0;
}
