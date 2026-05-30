#include "cBo.h"

cBo::cBo() : cGiaSuc() { loai = "Bo"; }

void cBo::Keu() {
    cout << "Bo: Um boooo! Um boooo!\n";
}

int cBo::SinhCon() {
    return rand() % 4 + 1; // Sinh 1 đến 4 con
}

int cBo::ChoSua() {
    return rand() % 21; // Cho 0 đến 20 lít sữa
}
