#include <iostream>
#include <iomanip>
#include "CDate.h"

using namespace std;

int main() {
    CDate d1;
    cout << "NHAP NGAY HIEN TAI" << endl;
    cin >> d1;

    cout << "\nNgay vua nhap: " << d1 << endl;

    int n;
    cout << "\nNhap so ngay can cong them: ";
    cin >> n;
    cout << "Sau khi cong " << n << " ngay: " << d1 + n << endl;

    cout << "Nhap so ngay can tru di: ";
    cin >> n;
    cout << "Sau khi tru " << n << " ngay: " << d1 - n << endl;

    cout << "\nTEST TOAN TU ++ va --" << endl;
    CDate d2 = d1;
    cout << "Ngay hien tai (d2): " << d2 << endl;
    cout << "d2++: " << d2++ << " (Sau do: " << d2 << ")" << endl;
    cout << "++d2: " << ++d2 << endl;
    cout << "d2--: " << d2-- << " (Sau do: " << d2 << ")" << endl;
    cout << "--d2: " << --d2 << endl;

    cout << "\nUNG DUNG: TINH LAI SUAT NGAN HANG" << endl;
    CDate ngayGoi, ngayRut;
    double tienGoi, laiSuat;

    cout << "* Nhap ngay bat dau goi tien:\n";
    cin >> ngayGoi;
    cout << "* Nhap ngay rut tien:\n";
    cin >> ngayRut;

    cout << "Nhap so tien goi (VND): ";
    cin >> tienGoi;
    cout << "Nhap lai suat (%/nam): ";
    cin >> laiSuat;

    int soNgayGui = ngayRut - ngayGoi;
    double tienLai = ngayGoi.TinhLaiSuat(ngayRut, tienGoi, laiSuat);

    cout << "Ngay gui: " << ngayGoi << endl;
    cout << "Ngay rut: " << ngayRut << endl;
    cout << "Tong thoi gian gui: " << soNgayGui << " ngay" << endl;
    cout << fixed << setprecision(0);
    cout << "Tien goc: " << tienGoi << " VND" << endl;
    cout << "Tien lai nhan duoc: " << tienLai << " VND" << endl;
    cout << "TONG TIEN NHAN VE: " << tienGoi + tienLai << " VND" << endl;


    return 0;
}
