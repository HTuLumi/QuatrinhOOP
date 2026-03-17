#include <iostream>
#include <string>
using namespace std;

struct HocSinh {
    string ten;
    float toan, van, dtb;
};

// Ham chong nhap chu cho so thuc (Float)
float nhapSoThuc(string thongBao) {
    float so;
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

//Ham nhat thong tin HS
void input(HocSinh &hs) {
    cout << "Nhap ho ten: ";
    getline(cin, hs.ten);

    // Ép nhập điểm từ 0 đến 10
    do {
        hs.toan = nhapSoThuc("Nhap diem toan (0-10): ");
        if (hs.toan < 0 || hs.toan > 10) cout << "-> Diem khong hop le!\n";
    } while (hs.toan < 0 || hs.toan > 10);

    do {
        hs.van = nhapSoThuc("Nhap diem van (0-10): ");
        if (hs.van < 0 || hs.van > 10) cout << "-> Diem khong hop le!\n";
    } while (hs.van < 0 || hs.van > 10);
}

//Ham tinh DTB
void calDTB(HocSinh &hs) {
    hs.dtb = (hs.toan + hs.van) / 2;
}

void output(HocSinh hs) {
    cout << "\n--- Thong tin hoc sinh ---\n";
    cout << "Ho ten: " << hs.ten << endl;
    cout << "Diem toan: " << hs.toan << endl;
    cout << "Diem van: " << hs.van << endl;
    cout << "Diem trung binh: " << hs.dtb << endl;
}

int main() {
    HocSinh hs;
    input(hs);
    calDTB(hs);
    output(hs);
    return 0;
}
