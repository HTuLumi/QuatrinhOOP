#include <iostream>
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
            cout << "Sai dinh dang! Vui long chi nhap so.\n";
            cin.clear(); cin.ignore(256, '\n');
        }
    }
}

//Nhap PS
void input(ps &a) {
    a.tu = nhapSoNguyen("Nhap tu so: ");
    do {
        a.mau = nhapSoNguyen("Nhap mau so: ");
        if (a.mau == 0) cout << "-> Mau so phai khac 0!\n";
    } while (a.mau == 0);
}

//Ham tim PS lon nhat
ps findMax(ps a, ps b) {
    float valA = (float)a.tu / a.mau;
    float valB = (float)b.tu / b.mau;
    if (valA > valB) return a;
    return b;
}


void output(ps a)
{
    cout << a.tu << "/" << a.mau << endl;
}

int main() {
    ps a, b;
    cout << "--- Nhap phan so thu nhat ---\n"; input(a);
    cout << "--- Nhap phan so thu hai ---\n"; input(b);

    cout << "Phan so lon nhat la: ";
    output(findMax(a, b));
    return 0;
}
