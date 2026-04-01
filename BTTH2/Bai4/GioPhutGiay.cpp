#include "GioPhutGiay.h"
#include <iostream>
#include <limits>

using namespace std;

int NhapSoNguyen(string thongBao) {
    int so;
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

void Time::Nhap()
{
    do{
        iGio=NhapSoNguyen("Nhap gio (0-23): ");
    }while(iGio<0||iGio>23);

    do{
        iPhut=NhapSoNguyen("Nhap phut (0-59): ");
    }while(iPhut<0||iPhut>59);
    //Nhap va kiem tra giay
    do{
        iGiay=NhapSoNguyen("Nhap giay (0-59): ");
    }while(iGiay<0||iGiay>59);
}


Time Time::TinhCongThemMotGiay()
{
    Time next = *this;
    next.iGiay++;
    if (next.iGiay == 60){
        next.iGiay=0;
        next.iPhut++;
        if(next.iPhut == 60){
            next.iPhut=0;
            next.iGio++;
            if(next.iGio == 24)
                next.iGio = 0;
        }
    }
    return next;
}

void Time::Xuat()
{
    cout << iGio << ":" << iPhut << ":" << iGiay << "\n";
}
