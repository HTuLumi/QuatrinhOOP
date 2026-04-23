#include <iostream>
#include "cArray.h"

using namespace std;

int main() {
    cArray arr;

    arr.TaoMangNgauNhien();

    cout << "\nMang vua tao ngau nhien:\n";
    arr.Xuat();

    if (arr.KiemTraTangDan()) {
        cout << "\nMang dang sap xep tang dan.\n";
    } else {
        cout << "\nMang khong duoc sap xep tang dan.\n";
    }

    int x;
    cout << "Nhap gia tri can dem so lan xuat hien: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << " la: " << arr.DemSoLanXuatHien(x) << "\n";

    int leNhoNhat;
    if (arr.TimPhanTuLeNhoNhat(leNhoNhat)) {
        cout << "Phan tu le nho nhat: " << leNhoNhat << "\n";
    } else {
        cout << "Mang khong co phan tu le.\n";
    }

    int nguyenToLonNhat;
    if (arr.TimSoNguyenToLonNhat(nguyenToLonNhat)) {
        cout << "So nguyen to lon nhat: " << nguyenToLonNhat << "\n";
    } else {
        cout << "Mang khong co so nguyen to.\n";
    }

    cout << "\nMang sau khi sap xep tang dan:\n";
    arr.SapXepTangDan();
    arr.Xuat();

    cout << "\nMang sau khi sap xep giam dan:\n";
    arr.SapXepGiamDan();
    arr.Xuat();

    return 0;
}
