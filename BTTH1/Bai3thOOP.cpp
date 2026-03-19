#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct ps { int tu, mau; };

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

//Tim UCLN
int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) { int t = b; b = a % b; a = t; }
    return a;
}

//Nhap PS
void input(ps &a) {
    a.tu = nhapSoNguyen("Nhap tu so: ");
    do {
        a.mau = nhapSoNguyen("Nhap mau so: ");
        if (a.mau == 0) cout << "-> Mau so phai khac 0!\n";
    } while (a.mau == 0);
}

//Rut gon PS
void simplify(ps &a) {
    int ucln = gcd(a.tu, a.mau);
    a.tu /= ucln; a.mau /= ucln;
    if (a.mau < 0) { a.tu = -a.tu; a.mau = -a.mau; }
}

//Xuat PS
void output(ps a) {
    if (a.mau == 0) cout << "Khong xac dinh";
    else if (a.tu == 0) cout << 0;
    else if (a.mau == 1) cout << a.tu;
    else cout << a.tu << "/" << a.mau;
    cout << endl;
}

//Tinh tong hieu tich thuong
void cal(ps a, ps b) {
    ps tong, hieu, tich, thuong;

    tong.tu = a.tu*b.mau + b.tu*a.mau; tong.mau = a.mau*b.mau; simplify(tong);
    hieu.tu = a.tu*b.mau - b.tu*a.mau; hieu.mau = a.mau*b.mau; simplify(hieu);
    tich.tu = a.tu*b.tu;               tich.mau = a.mau*b.mau; simplify(tich);

    cout << "Tong : "; output(tong);
    cout << "Hieu : "; output(hieu);
    cout << "Tich : "; output(tich);

    if (b.tu == 0) {
        cout << "Thuong : Khong the chia vi phan so thu 2 bang 0\n";
    } else {
        thuong.tu = a.tu*b.mau; thuong.mau = a.mau*b.tu; simplify(thuong);
        cout << "Thuong : "; output(thuong);
    }
}

int main() {
    ps a, b;
    cout << "--- Nhap phan so a ---\n"; input(a);
    cout << "--- Nhap phan so b ---\n"; input(b);
    cal(a, b);
    return 0;
}
