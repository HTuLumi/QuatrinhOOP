#include <iostream>
#include "CMatrix.h"
#include "CVector.h" // Nhúng class CVector từ Bài 6 sang

using namespace std;

int main() {
    CMatrix m1, m2;

    cout << "NHAP MA TRAN 1" << endl;
    cin >> m1;
    cout << "\nNHAP MA TRAN 2" << endl;
    cin >> m2;

    cout << "\nMa tran 1:\n" << m1;
    cout << "\nMa tran 2:\n" << m2;

    cout << "\nTEST TINH TICH HAI MA TRAN" << endl;
    CMatrix m_tich = m1 * m2;
    cout << "Ket qua Ma tran 1 * Ma tran 2:\n" << m_tich;

    cout << "\nTEST TINH TICH MA TRAN VA VECTOR" << endl;
    CVector vec;
    cout << "Nhap mot Vector de nhan voi Ma tran 1:\n";
    cin >> vec;
    cout << "\nVector vua nhap: " << vec << endl;

    CVector vec_res = m1 * vec;
    cout << "Ket qua Ma tran 1 * Vector: " << vec_res << endl;

    return 0;
}
