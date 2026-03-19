#include <iostream>
#include <string>
using namespace std;

struct Ngay { int d, m, y; };

//Kiem tra nhap
int nhapSoNguyen(string thongBao) {
    int so;
    while (true) {
        cout << thongBao;
        if (cin >> so) {
            cin.ignore(256, '\n'); return so;
        } else {
            cout << "-> Sai dinh dang! Vui long chi nhap so.\n";
            cin.clear(); cin.ignore(256, '\n');
        }
    }
}

//Kiem tra nam nhuan
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//Tim so ngay trong thang
int daysInMonth(int m, int y) {
    switch (m) {
        case 2: return isLeapYear(y) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

void input(Ngay &ng) {
    do { ng.y = nhapSoNguyen("Nhap nam (>0): "); } while (ng.y <= 0);
    do { ng.m = nhapSoNguyen("Nhap thang (1-12): "); } while (ng.m < 1 || ng.m > 12);
    int maxDay = daysInMonth(ng.m, ng.y);
    do {
        cout << "Nhap ngay (1-" << maxDay << "): ";
        ng.d = nhapSoNguyen("");
    } while (ng.d < 1 || ng.d > maxDay);
}

//Tim ngay tiep theo
Ngay nextDay(Ngay ng) {
    ng.d++;
    if (ng.d > daysInMonth(ng.m, ng.y)) {
        ng.d = 1; ng.m++;
        if (ng.m > 12) { ng.m = 1; ng.y++; }
    }
    return ng;
}

//Xuat ngay thang
void output(Ngay ng) {
    cout << ng.d << "/" << ng.m << "/" << ng.y << endl;
}

//Ham main nhap xuat thuc hien yeu cau
int main() {
    Ngay nay;
    input(nay);
    cout << "Ngay ke tiep la: ";
    output(nextDay(nay));
    return 0;
}
