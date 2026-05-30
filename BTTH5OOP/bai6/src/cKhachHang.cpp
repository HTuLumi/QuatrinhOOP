#include "cKhachHang.h"
#include <iomanip>

cKhachHang::cKhachHang() : hoTen(""), soLuong(0), donGia(0), thanhTien(0) {}

cKhachHang::~cKhachHang() {}

void cKhachHang::Nhap(ifstream& in) {
    getline(in, hoTen);
    in >> soLuong >> donGia;
    in.ignore(); // Bỏ qua ký tự xuống dòng sau khi đọc số để chuẩn bị cho getline tiếp theo
}

void cKhachHang::Xuat(ofstream& out) {
    out << hoTen << "\n";
    out << fixed << setprecision(0) << thanhTien << "\n";
}

double cKhachHang::getThanhTien() const {
    return thanhTien;
}
