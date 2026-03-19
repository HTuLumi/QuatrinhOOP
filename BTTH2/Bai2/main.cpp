#include <iostream>
#include "PhanSo.h"

using namespace std;

int main()
{
    // Nhap xuat rut gon phan so
    PhanSo a,b;
    cout << "Nhap phan so a: \n";
    a.Nhap();
    cout << "\nNhap phan so b: \n";
    b.Nhap();

    cout << "\nPhan so a: ";
    a.RutGon();
    a.Xuat();

    cout << "\nPhan so b: ";
    b.RutGon();
    b.Xuat();

    //Tinh toan phan so
    PhanSo tong = a.Tong(b);
    PhanSo hieu = a.Hieu(b);
    PhanSo tich = a.Tich(b);
    PhanSo thuong = a.Thuong(b);

    cout <<"\nTong: ";
    tong.Xuat();

    cout <<"\nHieu: ";
    hieu.Xuat();

    cout <<"\nTich: ";
    tich.Xuat();

    cout <<"\nThuong: ";
    thuong.Xuat();

    cout << "\n";
    //So sanh phan so
    if (a.SoSanh(b) == 1)
        cout << "a < b";
    else if (a.SoSanh(b) == 0)
        cout << "a = b";
    else cout << "a > b";

    return 0;

}
