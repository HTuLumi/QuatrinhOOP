#include <iostream>
#include "SoPhuc.h"
#include "SoPhuc.cpp"
using namespace std;

int main()
{
    SoPhuc sp1, sp2;
    cout<<"Nhap so phuc 1: \n"; sp1.Nhap();
    cout<<"Nhap so phuc 2: \n"; sp2.Nhap();
    cout<<"So phuc 1: "; sp1.Xuat();
    cout<<"\nSo phuc 2: "; sp2.Xuat();

    SoPhuc tong=sp1.Tong(sp2);
    SoPhuc hieu=sp1.Hieu(sp2);
    SoPhuc tich=sp1.Tich(sp2);
    SoPhuc thuong=sp1.Thuong(sp2);

    cout<<"\nTong: "; tong.Xuat();
    cout<<"\nHieu: ";hieu.Xuat();
    cout<<"\nTich: "; tich.Xuat();
    cout<<"\nThuong: ";thuong.Xuat();
    return 0;
}
