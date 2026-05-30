#include <iostream>
#include <vector>
#include "cBo.h"
#include "cCuu.h"
#include "cDe.h"

using namespace std;

int main() {
    // Thiết lập seed cố định để dễ test và ra kết quả giống nhau
    srand(1);

    int soBo, soCuu, soDe;
    cout << "--- KHOI TAO NONG TRAI ---\n";
    cout << "Nhap so luong Bo ban dau: "; cin >> soBo;
    cout << "Nhap so luong Cuu ban dau: "; cin >> soCuu;
    cout << "Nhap so luong De ban dau: "; cin >> soDe;

    vector<cGiaSuc*> nongTrai;

    // 1 Vòng lặp gọn gàng nhập cả 3 loài
    for (int i = 0; i < soBo; i++) nongTrai.push_back(new cBo());
    for (int i = 0; i < soCuu; i++) nongTrai.push_back(new cCuu());
    for (int i = 0; i < soDe; i++) nongTrai.push_back(new cDe());

    cout << "\nTIENG KEU KHI DOI\n";
    // 1 Vòng lặp duy nhất phát tiếng kêu nhờ Liên kết động (Đa hình)
    for (int i = 0; i < nongTrai.size(); i++) {
        nongTrai[i]->Keu();
    }

    cout << "\nTHONG KE NONG TRAI SAU 1 LUA\n";
    int tongSuaBo = 0, tongSuaCuu = 0, tongSuaDe = 0;
    int sinhBo = 0, sinhCuu = 0, sinhDe = 0;

    // 1 Vòng lặp duy nhất để lấy số con và số sữa
    for (int i = 0; i < nongTrai.size(); i++) {
        int sua = nongTrai[i]->ChoSua();
        int con = nongTrai[i]->SinhCon();

        if (nongTrai[i]->getLoai() == "Bo") {
            tongSuaBo += sua;
            sinhBo += con;
        } else if (nongTrai[i]->getLoai() == "Cuu") {
            tongSuaCuu += sua;
            sinhCuu += con;
        } else if (nongTrai[i]->getLoai() == "De") {
            tongSuaDe += sua;
            sinhDe += con;
        }
    }

    cout << "BO\n";
    cout << " + So luong ban dau: " << soBo << " con\n";
    cout << " + Sinh them duoc: " << sinhBo << " con. Hien co: " << soBo + sinhBo << " con.\n";
    cout << " + Cho duoc " << tongSuaBo << " lit sua.\n";

    cout << "CUU\n";
    cout << " + So luong ban dau: " << soCuu << " con\n";
    cout << " + Sinh them duoc: " << sinhCuu << " con. Hien co: " << soCuu + sinhCuu << " con.\n";
    cout << " + Cho duoc " << tongSuaCuu << " lit sua.\n";

    cout << "DE\n";
    cout << " + So luong ban dau: " << soDe << " con\n";
    cout << " + Sinh them duoc: " << sinhDe << " con. Hien co: " << soDe + sinhDe << " con.\n";
    cout << " + Cho duoc " << tongSuaDe << " lit sua.\n";

    int tongTatCaGiaSuc = soBo + sinhBo + soCuu + sinhCuu + soDe + sinhDe;
    int tongTatCaLitSua = tongSuaBo + tongSuaCuu + tongSuaDe;

    cout << "\n=> TONG CON VAT TRONG NONG TRAI: " << tongTatCaGiaSuc << " con.\n";
    cout << "=> TONG LIT SUA THU DUOC: " << tongTatCaLitSua << " lit.\n";

    // Giải phóng bộ nhớ
    for (int i = 0; i < nongTrai.size(); i++) {
        delete nongTrai[i];
    }

    return 0;
}
