#include "cCuu.h"

cCuu::cCuu() : cGiaSuc() { loai = "Cuu"; }

void cCuu::Keu() {
    cout << "Cuu: Beeeee! Beeeee!\n";
}

int cCuu::SinhCon() {
    return rand() % 4 + 1; // Sinh 1 đến 4 con
}

int cCuu::ChoSua() {
    return rand() % 6; // Cho 0 đến 5 lít sữa
}
