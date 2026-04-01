#include "NgayThang.h"
#include <iostream>

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

//Check nam nhuan de xem thang 2 co nbao nhieu ngay
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}



//Tim so ngay trong thang de kiem tra dieu kien nhap ngay
int daysInMonth(int m, int y) {
    switch (m) {
        case 2: return isLeapYear(y) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}


//Ham nhap Ngay Thang Nam, input a kieu NgayThang
void NgayThang::Nhap() {
    do {iNam = nhapSoNguyen("Nhap nam (>0): "); } while (iNam <= 0);
    do {iThang = nhapSoNguyen("Nhap thang (1-12): "); } while (iThang < 1 || iThang > 12);
    int maxday = daysInMonth(iThang, iNam);
    do
    {
        cout << "Nhap ngay (1-" << maxday << "): ";
        iNgay = nhapSoNguyen("");
    } while (iNgay < 1 || iNgay > maxday);
}

//Ham Xuat ngay thang nam
void NgayThang::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

//Ham tim ngay tiep theo
NgayThang NgayThang::NgayThangNamTiepTheo()
{
    NgayThang a;
    a.iNgay = iNgay;
    a.iThang = iThang;
    a.iNam = iNam;

    a.iNgay++;
    if (a.iNgay > daysInMonth(a.iThang, a.iNam))
    {
        a.iNgay = 1; a.iThang++;
        if (a.iThang > 12)
        {
            a.iThang = 1; a.iNam++;
        }
    }
    return a;
}
