#include "cTamGiac.h"
#include <iostream>
#include <cmath>

using namespace std;

// Ham ho tro tinh khoang cach
double KhoangCach(Diem p1, Diem p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

cTamGiac::cTamGiac() {
    A.x = A.y = 0;
    B.x = B.y = 0;
    C.x = C.y = 0;
}

cTamGiac::~cTamGiac() {}

void cTamGiac::Nhap() {
    cout << "Nhap toa do dinh A (x y): ";
    cin >> A.x >> A.y;
    cout << "Nhap toa do dinh B (x y): ";
    cin >> B.x >> B.y;
    cout << "Nhap toa do dinh C (x y): ";
    cin >> C.x >> C.y;
}

void cTamGiac::Xuat() {
    cout << "A(" << A.x << ", " << A.y << "), ";
    cout << "B(" << B.x << ", " << B.y << "), ";
    cout << "C(" << C.x << ", " << C.y << ")\n";
}

bool cTamGiac::KiemTraHopLe() {
    double a = KhoangCach(B, C);
    double b = KhoangCach(A, C);
    double c = KhoangCach(A, B);
    if (a + b > c && a + c > b && b + c > a) {
        return true;
    }
    return false;
}

void cTamGiac::KiemTraLoai() {
    if (!KiemTraHopLe()) {
        cout << "Day khong phai la tam giac hop le.\n";
        return;
    }
    double a = KhoangCach(B, C);
    double b = KhoangCach(A, C);
    double c = KhoangCach(A, B);

    // Dung sai so epsilon de so sanh so thuc
    double eps = 1e-5;
    bool vuong = false;

    if (abs(a*a + b*b - c*c) < eps || abs(a*a + c*c - b*b) < eps || abs(b*b + c*c - a*a) < eps) {
        vuong = true;
    }

    if (abs(a - b) < eps && abs(b - c) < eps) {
        cout << "Tam giac deu\n";
    } else if (abs(a - b) < eps || abs(b - c) < eps || abs(c - a) < eps) {
        if (vuong) cout << "Tam giac vuong can\n";
        else cout << "Tam giac can\n";
    } else if (vuong) {
        cout << "Tam giac vuong\n";
    } else {
        cout << "Tam giac thuong\n";
    }
}

double cTamGiac::TinhChuVi() {
    if (!KiemTraHopLe()) return 0;
    double a = KhoangCach(B, C);
    double b = KhoangCach(A, C);
    double c = KhoangCach(A, B);
    return a + b + c;
}

double cTamGiac::TinhDienTich() {
    if (!KiemTraHopLe()) return 0;
    double a = KhoangCach(B, C);
    double b = KhoangCach(A, C);
    double c = KhoangCach(A, B);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void cTamGiac::TinhTien(double dx, double dy) {
    A.x += dx; A.y += dy;
    B.x += dx; B.y += dy;
    C.x += dx; C.y += dy;
}

void cTamGiac::Quay(double goc) {
    // Chuyen do sang radian
    double rad = goc * M_PI / 180.0;
    double cosG = cos(rad);
    double sinG = sin(rad);

    double tempAx = A.x * cosG - A.y * sinG;
    double tempAy = A.x * sinG + A.y * cosG;
    A.x = tempAx; A.y = tempAy;

    double tempBx = B.x * cosG - B.y * sinG;
    double tempBy = B.x * sinG + B.y * cosG;
    B.x = tempBx; B.y = tempBy;

    double tempCx = C.x * cosG - C.y * sinG;
    double tempCy = C.x * sinG + C.y * cosG;
    C.x = tempCx; C.y = tempCy;
}

void cTamGiac::PhongToThuNho(double k) {
    A.x *= k; A.y *= k;
    B.x *= k; B.y *= k;
    C.x *= k; C.y *= k;
}
