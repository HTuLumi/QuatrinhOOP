#include "cDaThuc.h"
#include <iostream>
#include <cmath>

using namespace std;

cDaThuc::cDaThuc() {
    n = 0;
    a = new double[1];
    a[0] = 0;
}

cDaThuc::cDaThuc(int bac) {
    n = bac;
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
    }
}

cDaThuc::cDaThuc(const cDaThuc &other) {
    n = other.n;
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = other.a[i];
    }
}

cDaThuc::~cDaThuc() {
    delete[] a;
}

void cDaThuc::Nhap() {
    do {
        cout << "Nhap bac cua da thuc: ";
        cin >> n;
    } while (n < 0);

    delete[] a;
    a = new double[n + 1];

    for (int i = n; i >= 0; i--) {
        cout << "Nhap he so cua x^" << i << ": ";
        cin >> a[i];
    }
}

void cDaThuc::Xuat() {
    bool first = true;
    for (int i = n; i >= 0; i--) {
        if (a[i] != 0) {
            if (first) {
                if (a[i] < 0) cout << "-";
                first = false;
            } else {
                if (a[i] > 0) cout << " + ";
                else cout << " - ";
            }

            double val = abs(a[i]);
            if (val != 1 || i == 0) {
                cout << val;
            }

            if (i > 0) {
                cout << "x";
                if (i > 1) cout << "^" << i;
            }
        }
    }
    if (first) cout << "0";
    cout << "\n";
}

double cDaThuc::TinhGiaTri(double x) {
    double ketQua = 0;
    for (int i = n; i >= 0; i--) {
        ketQua += a[i] * pow(x, i);
    }
    return ketQua;
}

cDaThuc cDaThuc::Cong(cDaThuc d) {
    int bacMax = (n > d.n) ? n : d.n;
    cDaThuc ketQua(bacMax);

    for (int i = 0; i <= bacMax; i++) {
        double heSo1 = (i <= n) ? a[i] : 0;
        double heSo2 = (i <= d.n) ? d.a[i] : 0;
        ketQua.a[i] = heSo1 + heSo2;
    }
    return ketQua;
}

cDaThuc cDaThuc::Tru(cDaThuc d) {
    int bacMax = (n > d.n) ? n : d.n;
    cDaThuc ketQua(bacMax);

    for (int i = 0; i <= bacMax; i++) {
        double heSo1 = (i <= n) ? a[i] : 0;
        double heSo2 = (i <= d.n) ? d.a[i] : 0;
        ketQua.a[i] = heSo1 - heSo2;
    }
    return ketQua;
}
