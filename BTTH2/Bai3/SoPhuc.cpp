#include "SoPhuc.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

double nhapso(string thongBao) {
    double so;
    while (true) {
        cout << thongBao;
        if (cin >> so) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return so;
        } else {
            cout << "Sai dinh dang! Vui long chi nhap so.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void SoPhuc::Nhap()
{
    iThuc=nhapso("Nhap so thuc: ");
    iAo=nhapso("Nhap so ao: ");
}


SoPhuc SoPhuc::Tong(SoPhuc b)
{
    SoPhuc kq;
    kq.iThuc=iThuc+b.iThuc;
    kq.iAo=iAo+b.iAo;
    return kq;
}
SoPhuc SoPhuc::Hieu(SoPhuc b)
{
    SoPhuc kq;
    kq.iThuc=iThuc-b.iThuc;
    kq.iAo=iAo-b.iAo;
    return kq;
}

SoPhuc SoPhuc::Tich(SoPhuc b)
{
    SoPhuc kq;
    kq.iThuc=(iThuc*b.iThuc)-(iAo*b.iAo);
    kq.iAo=(iThuc*b.iAo)+(iAo*b.iThuc);
    return kq;
}

SoPhuc SoPhuc::Thuong(SoPhuc b)
{
    SoPhuc kq;
    double mau=(b.iThuc*b.iThuc)+(b.iAo*b.iAo);
    //Kiem tra mau bang 0
    if (mau==0){
        cout<<"\nMau so bang 0, khong chia được.\n";
        kq.iThuc=0;
        kq.iAo=0;
        return kq;
    }
    kq.iThuc = (iThuc * b.iThuc + iAo * b.iAo) / mau;
    kq.iAo = (iAo * b.iThuc - iThuc * b.iAo) / mau;
    return kq;
}
void SoPhuc::Xuat() {
    //Thuc va Ao deu bang 0
    if (iThuc == 0 && iAo == 0) {
        cout << 0;
        return;
    }

    // In phan thuc khac 0
    if (iThuc != 0) {
        if (iThuc == (int)iThuc) {
            cout << (int)iThuc;
        } else {
            cout << fixed << setprecision(2) << iThuc << defaultfloat; // La so thap phan thi in 2 chu so
        }
    }

    if (iAo != 0) {
        //In dau cong tru
        if (iThuc != 0) {
            cout << (iAo > 0 ? " + " : " - ");
        } else if (iAo < 0) {
            cout << "-"; //Khong co thuc
        }

        double absAo = abs(iAo);

        //In phan ao
        if (absAo == (int)absAo) {
            cout << (int)absAo;
        } else {
            cout << fixed << setprecision(2) << absAo << defaultfloat;
        }
        cout << "i";
    }
}
