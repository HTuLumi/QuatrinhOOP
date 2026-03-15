#include <iostream>
#include <cmath>
using namespace std;

//Tao cau truc kieu phan so
struct PhanSo{
    int tu,mau;
};

//input bien a kieu PS, Chuc nang nhap phan so;
void NhapPS(PhanSo &a)
{
    cout << "Nhap tu so: ";
    cin >> a.tu;
    cout << "Nhap mau so: ";
    cin >> a.mau;
    while (a.mau == 0)
    {
        cout <<"Nhap sai quy dinh, mau phai khac 0, moi nhap lai: ";
        cin >> a.mau;
    }
}

//Ham giup tim UCLN, input la phan so a tu mau
int UCLN(PhanSo a)
{
    a.tu = abs(a.tu); a.mau = abs(a.mau);
    while (a.tu * a.mau != 0) {
        if (a.tu > a.mau) a.tu %= a.mau;
        else a.mau %= a.tu;
    }
    return a.tu + a.mau;
}

//Ham rut gon phan so, input bien a kieu PhanSo
void RutgonPS(PhanSo &a)
{
    int UC= UCLN(a);
    a.tu /= UC;
    a.mau /= UC;
}

//Xuat PS a
void XuatPS(PhanSo a)
{
    if (a.mau < 0)
    {
        cout << -a.tu << "/" << abs(a.mau) << endl;
    } else cout << a.tu << "/" << a.mau << endl;
}

int main()
{
    //bai1
    PhanSo a;
    NhapPS(a);
    XuatPS(a);
    RutgonPS(a);
    cout << "Phan so sau khi rut gon la: ";
    XuatPS(a);

    return 0;
}
