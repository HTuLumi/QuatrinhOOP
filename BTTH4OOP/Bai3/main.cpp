#include <iostream>
#include "CTime.h"

using namespace std;

int main() {
    CTime t1;
    cout << "--- NHAP THOI GIAN ---" << endl;
    cin >> t1;

    cout << "\nThoi gian vua nhap: " << t1 << endl;

    int s_add, s_sub;
    cout << "\nNhap so giay can cong them: ";
    cin >> s_add;
    cout << "Sau khi cong " << s_add << " giay: " << t1 + s_add << endl;

    cout << "\nNhap so giay can tru di: ";
    cin >> s_sub;
    cout << "Sau khi tru " << s_sub << " giay: " << t1 - s_sub << endl;

    cout << "\n--- TEST TOAN TU ++ va -- ---" << endl;
    CTime t2 = t1;
    cout << "Thoi gian hien tai (t2): " << t2 << endl;

    cout << "t2++ (in ra truoc, tang sau): " << t2++ << endl;
    cout << "Sau t2++: " << t2 << endl;

    cout << "++t2 (tang truoc, in ra sau): " << ++t2 << endl;

    cout << "t2-- (in ra truoc, giam sau): " << t2-- << endl;
    cout << "Sau t2--: " << t2 << endl;

    cout << "--t2 (giam truoc, in ra sau): " << --t2 << endl;

    cout << "\n--- TEST DONG HO GOC TREN BEN PHAI ---" << endl;
    cout << "(Hay nhin len goc tren cung ben phai cua cua so Console)" << endl;
    t1.InDongHo();

    return 0;
}
