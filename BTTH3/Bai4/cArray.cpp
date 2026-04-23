#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

cArray::cArray() {
    n = 0;
    a = NULL;
}

cArray::~cArray() {
    if (a != NULL) {
        delete[] a;
    }
}

bool cArray::KiemTraNguyenTo(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void cArray::TaoMangNgauNhien() {
    do {
        cout << "Nhap so luong phan tu cua mang: ";
        cin >> n;
    } while (n <= 0);

    if (a != NULL) {
        delete[] a;
    }
    a = new int[n];

    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void cArray::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int cArray::DemSoLanXuatHien(int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) count++;
    }
    return count;
}

bool cArray::KiemTraTangDan() {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool cArray::TimPhanTuLeNhoNhat(int &res) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            if (!found || a[i] < res) {
                res = a[i];
                found = true;
            }
        }
    }
    return found;
}

bool cArray::TimSoNguyenToLonNhat(int &res) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (KiemTraNguyenTo(a[i])) {
            if (!found || a[i] > res) {
                res = a[i];
                found = true;
            }
        }
    }
    return found;
}

void cArray::SapXepTangDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void cArray::SapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}
