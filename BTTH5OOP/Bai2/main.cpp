#include <iostream>
#include <vector>
#include <iomanip>
#include "cGiaoDichDat.h"
#include "cGiaoDichNhaPho.h"
#include "cGiaoDichChungCu.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong giao dich: ";
    cin >> n;

    vector<cGiaoDich*> danhSach;
    int countDat = 0, countNhaPho = 0, countChungCu = 0;

    for (int i = 0; i < n; i++) {
        int loai;
        cout << "\nLoai giao dich (1: Dat, 2: Nha pho, 3: Chung cu): ";
        cin >> loai;

        cGiaoDich* gd = NULL;
        if (loai == 1) {
            gd = new cGiaoDichDat();
            countDat++;
        } else if (loai == 2) {
            gd = new cGiaoDichNhaPho();
            countNhaPho++;
        } else if (loai == 3) {
            gd = new cGiaoDichChungCu();
            countChungCu++;
        } else {
            cout << "Loai khong hop le!\n";
            i--; continue;
        }

        gd->Nhap();
        gd->TinhThanhTien();
        danhSach.push_back(gd);
    }

    cout << "\nDANH SACH GIAO DICH" << endl;
    for (int i = 0; i < danhSach.size(); i++) {
        danhSach[i]->Xuat();
    }

    cout << "\nTong so GD Dat: " << countDat;
    cout << "\nTong so GD Nha Pho: " << countNhaPho;
    cout << "\nTong so GD Chung Cu: " << countChungCu << endl;

    double tongTienChungCu = 0;
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->getLoaiGD() == 3) {
            tongTienChungCu += danhSach[i]->getThanhTien();
        }
    }
    if (countChungCu > 0) {
        cout << "\nTrung binh thanh tien cua GD Chung Cu: "
             << fixed << setprecision(0) << (tongTienChungCu / countChungCu) << endl;
    } else {
        cout << "\nKhong co giao dich Chung Cu nao." << endl;
    }

    cGiaoDich* maxNhaPho = NULL;
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->getLoaiGD() == 2) {
            if (maxNhaPho == NULL || danhSach[i]->getThanhTien() > maxNhaPho->getThanhTien()) {
                maxNhaPho = danhSach[i];
            }
        }
    }

    if (maxNhaPho != NULL) {
        cout << "\nGIAO DICH NHA PHO CO TRI GIA CAO NHAT\n";
        maxNhaPho->Xuat();
    }

    cout << "\nDANH SACH GIAO DICH THANG 12 NAM 2024\n";
    bool timThay = false;
    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->getThang() == 12 && danhSach[i]->getNam() == 2024) {
            danhSach[i]->Xuat();
            timThay = true;
        }
    }
    if (!timThay) cout << "Khong co giao dich nao trong thoi gian nay.\n";

    // Giải phóng bộ nhớ
    for (int i = 0; i < danhSach.size(); i++) {
        delete danhSach[i];
    }

    return 0;
}
