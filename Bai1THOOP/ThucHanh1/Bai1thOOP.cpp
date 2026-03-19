#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct ps { int tu, mau; };

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

//Tim ucln
int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) { int t = b; b = a % b; a = t; }
    return a;
}

//nhap PS
void input(ps &a) {
    a.tu = nhapSoNguyen("Nhap tu so: ");
    do {
        a.mau = nhapSoNguyen("Nhap mau so: ");
        if (a.mau == 0) cout << "-> Mau so phai khac 0!\n";
    } while (a.mau == 0);
}


//rut gon PS
void simplify(ps &a) {
    int ucln = gcd(a.tu, a.mau);
    a.tu /= ucln; a.mau /= ucln;
    if (a.mau < 0) { a.tu = -a.tu; a.mau = -a.mau; }
}


//Xuat PS
void output(ps a) {
    if (a.tu == 0) cout << 0;
    else if (a.mau == 1) cout << a.tu;
    else cout << a.tu << "/" << a.mau;
    cout << endl;
}

//Main nhap xuat, thuc hien bai
int main() {
    ps a;
    input(a);
    simplify(a);
    cout << "Phan so rut gon la: "; output(a);
    return 0;
}
