#include "cDe.h"

cDe::cDe() : cGiaSuc() { loai = "De"; }

void cDe::Keu() {
    cout << "De: Eeeeeee! Eeeeeee!\n";
}

int cDe::SinhCon() {
    return rand() % 4 + 1; // Sinh 1 đến 4 con
}

int cDe::ChoSua() {
    return rand() % 11; // Cho 0 đến 10 lít sữa
}
