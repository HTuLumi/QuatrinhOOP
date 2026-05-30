#include "cKhachHangB.h"
#include <algorithm> // Thư viện dùng hàm max()

cKhachHangB::cKhachHangB() : cKhachHang(), soNam(0) {}

void cKhachHangB::Nhap(ifstream& in) {
    getline(in, hoTen);
    in >> soLuong >> donGia >> soNam;
    in.ignore(); // Bỏ qua ký tự xuống dòng
}

void cKhachHangB::TinhTien() {
    // Công thức đề bài: KhuyenMai = MAX(soNam * 5%, 50%)
    double khuyenMai = max(soNam * 0.05, 0.50);
    thanhTien = (soLuong * donGia) * (1.0 - khuyenMai) * 1.1;
}
