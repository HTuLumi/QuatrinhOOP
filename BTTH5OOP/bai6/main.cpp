#include <iostream>
#include <vector>
#include <iomanip>
#include "cKhachHangA.h"
#include "cKhachHangB.h"
#include "cKhachHangC.h"

using namespace std;

int main() {
    // 1. Mở file INP để đọc
    ifstream inFile("XYZ.INP");
    if (!inFile.is_open()) {
        cout << "Khong the mo file XYZ.INP de doc du lieu!" << endl;
        return 1;
    }

    int x, y, z;
    inFile >> x >> y >> z;
    inFile.ignore(); // Xóa ký tự xuống dòng sau khi đọc số

    vector<cKhachHang*> danhSach;

    // Đọc x khách hàng loại A
    for (int i = 0; i < x; i++) {
        cKhachHang* kh = new cKhachHangA();
        kh->Nhap(inFile);
        kh->TinhTien();
        danhSach.push_back(kh);
    }

    // Đọc y khách hàng loại B
    for (int i = 0; i < y; i++) {
        cKhachHang* kh = new cKhachHangB();
        kh->Nhap(inFile);
        kh->TinhTien();
        danhSach.push_back(kh);
    }

    // Đọc z khách hàng loại C
    for (int i = 0; i < z; i++) {
        cKhachHang* kh = new cKhachHangC();
        kh->Nhap(inFile);
        kh->TinhTien();
        danhSach.push_back(kh);
    }

    inFile.close(); // Đóng file sau khi đọc xong

    // 2. Mở file OUT để ghi kết quả
    ofstream outFile("XYZ.OUT");
    if (!outFile.is_open()) {
        cout << "Khong the tao file XYZ.OUT de ghi ket qua!" << endl;
        return 1;
    }

    outFile << x << " " << y << " " << z << "\n";

    double tongThuGom = 0;
    // Dùng Đa hình để ghi kết quả của từng khách hàng ra file
    for (int i = 0; i < danhSach.size(); i++) {
        danhSach[i]->Xuat(outFile);
        tongThuGom += danhSach[i]->getThanhTien();
    }

    // In tổng doanh thu
    outFile << fixed << setprecision(0) << tongThuGom << "\n";

    outFile.close(); // Đóng file

    // Giải phóng bộ nhớ
    for (int i = 0; i < danhSach.size(); i++) {
        delete danhSach[i];
    }

    cout << "Da xu ly thanh cong! Kiem tra ket qua trong file XYZ.OUT" << endl;

    return 0;
}
