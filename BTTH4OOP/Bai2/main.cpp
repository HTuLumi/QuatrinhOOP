#include <iostream>
#include "cPhanSo.h"

using namespace std;

int main() {
    cPhanSo ps1, ps2;

    cout << "NHAP PHAN SO 1" << endl;
    cin >> ps1;
    cout << "NHAP PHAN SO 2" << endl;
    cin >> ps2;

    cout << "\nPhan so 1 (da rut gon): " << ps1 << endl;
    cout << "Phan so 2 (da rut gon): " << ps2 << endl;

    cout << "\nKET QUA CAC PHEP TOAN" << endl;
    cout << "Tong: " << ps1 + ps2 << endl;
    cout << "Hieu: " << ps1 - ps2 << endl;
    cout << "Tich: " << ps1 * ps2 << endl;
    cout << "Thuong: " << ps1 / ps2 << endl;

    cout << "\nSO SANH" << endl;
    if (ps1 > ps2) {
        cout << ps1 << " > " << ps2 << endl;
    } else if (ps1 < ps2) {
        cout << ps1 << " < " << ps2 << endl;
    } else {
        cout << ps1 << " = " << ps2 << " (Khong lon hon, khong nho hon)" << endl;
    }

    // Test case ngoại lệ: Số nguyên như phân số
    cout << "\nTEST KHOI TAO BANG SO NGUYEN" << endl;
    cPhanSo ps3 = 10; // Constructor 1 tham số sẽ được gọi cPhanSo(10, 1)
    cout << "Phan so 3 duoc gan bang so nguyen 10: " << ps3 << endl;
    cout << "Phep cong ps1 + 5 (so nguyen): " << ps1 + 5 << endl;

    return 0;
}
