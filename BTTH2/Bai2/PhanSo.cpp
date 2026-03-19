#include "PhanSo.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

// Ham kiem tra nhap chu
int nhapSoNguyen(string thongBao) {
    int so;
    while (true) {
        cout << thongBao;
        if (cin >> so) {
            cin.ignore(256, '\n');
            return so;
        } else {
            cout << "Sai dinh dang! Vui long chi nhap so.\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}

void PhanSo::Nhap() {
    iTu = nhapSoNguyen("Nhap tu so: ");
    do {
        iMau = nhapSoNguyen("Nhap mau so: ");
        if (iMau == 0) cout << "-> Mau so phai khac 0!\n";
    } while (iMau == 0);
}

void PhanSo::Xuat() {
    if (iMau != 1)
    cout << iTu << "/" << iMau;
    else cout << iTu;
}

void PhanSo::RutGon() {
    int g = std::__gcd(abs(iTu), abs(iMau));
    iTu /= g;
    iMau /= g;
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

PhanSo PhanSo::Tong(PhanSo b) {
    PhanSo res;
    res.iTu = iTu * b.iMau + b.iTu * iMau;
    res.iMau = iMau * b.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Hieu(PhanSo b) {
    PhanSo res;
    res.iTu = iTu * b.iMau - b.iTu * iMau;
    res.iMau = iMau * b.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Tich(PhanSo b) {
    PhanSo res;
    res.iTu = iTu * b.iTu;
    res.iMau = iMau * b.iMau;
    res.RutGon();
    return res;
}

PhanSo PhanSo::Thuong(PhanSo b) {
    PhanSo res;
    res.iTu = iTu * b.iMau;
    res.iMau = iMau * b.iTu;
    res.RutGon();
    return res;
}

int PhanSo::SoSanh(PhanSo b) {
    int t1 = iTu * b.iMau;
    int t2 = b.iTu * iMau;
    if (t1 < t2) return 1;
    if (t1 > t2) return -1;
    return 0;
}
