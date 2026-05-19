#include <iostream>
#include "cSoPhuc.h"

using namespace std;

int main() {
    cSoPhuc sp1, sp2;

    cout << "--- NHAP SO PHUC 1 ---" << endl;
    cin >> sp1;
    cout << "--- NHAP SO PHUC 2 ---" << endl;
    cin >> sp2;

    cout << "\nSo phuc 1: " << sp1 << endl;
    cout << "So phuc 2: " << sp2 << endl;

    cout << "\n--- KET QUA CAC PHEP TOAN ---" << endl;
    cout << "Tong: " << sp1 + sp2 << endl;
    cout << "Hieu: " << sp1 - sp2 << endl;
    cout << "Tich: " << sp1 * sp2 << endl;
    cout << "Thuong: " << sp1 / sp2 << endl;

    if (sp1 != sp2) {
        cout << "Hai so phuc khac nhau!" << endl;
    } else {
        cout << "Hai so phuc bang nhau!" << endl;
    }

    // Kiểm thử việc coi số thực như số phức đặc biệt
    cSoPhuc sp3 = 10.5; // Tự động gọi cSoPhuc(10.5, 0)
    cout << "\nSo phuc dac biet (tu so thuc 10.5): " << sp3 << endl;
    cout << "Phep cong sp1 voi so thuc 10.5: " << sp1 + sp3 << endl;

    return 0;
}
