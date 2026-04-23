#include "cDaGiac.h"
#include <iostream>
#include <cmath>

using namespace std;

double KhoangCachDG(Diem p1, Diem p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

cDaGiac::cDaGiac() {
    n = 0;
    Dinh = NULL;
}

cDaGiac::~cDaGiac() {
    if (Dinh != NULL) {
        delete[] Dinh;
    }
}

void cDaGiac::Nhap() {
    do {
        cout << "Nhap so dinh cua da giac (n >= 3): ";
        cin >> n;
    } while (n < 3);

    Dinh = new Diem[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh " << i + 1 << " (x y): ";
        cin >> Dinh[i].x >> Dinh[i].y;
    }
}

void cDaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << "(" << Dinh[i].x << ", " << Dinh[i].y << ")";
        if (i < n - 1) cout << ", ";
    }
    cout << "\n";
}

double cDaGiac::TinhChuVi() {
    if (n < 3) return 0;
    double chuVi = 0;
    for (int i = 0; i < n - 1; i++) {
        chuVi += KhoangCachDG(Dinh[i], Dinh[i+1]);
    }
    chuVi += KhoangCachDG(Dinh[n-1], Dinh[0]);
    return chuVi;
}

double cDaGiac::TinhDienTich() {
    if (n < 3) return 0;
    double dienTich = 0;
    for (int i = 0; i < n - 1; i++) {
        dienTich += (Dinh[i].x * Dinh[i+1].y) - (Dinh[i+1].x * Dinh[i].y);
    }
    dienTich += (Dinh[n-1].x * Dinh[0].y) - (Dinh[0].x * Dinh[n-1].y);
    return abs(dienTich) / 2.0;
}

void cDaGiac::TinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        Dinh[i].x += dx;
        Dinh[i].y += dy;
    }
}

void cDaGiac::Quay(double goc) {
    double rad = goc * M_PI / 180.0;
    double cosG = cos(rad);
    double sinG = sin(rad);

    for (int i = 0; i < n; i++) {
        double tempX = Dinh[i].x * cosG - Dinh[i].y * sinG;
        double tempY = Dinh[i].x * sinG + Dinh[i].y * cosG;
        Dinh[i].x = tempX;
        Dinh[i].y = tempY;
    }
}

void cDaGiac::PhongToThuNho(double k) {
    for (int i = 0; i < n; i++) {
        Dinh[i].x *= k;
        Dinh[i].y *= k;
    }
}
