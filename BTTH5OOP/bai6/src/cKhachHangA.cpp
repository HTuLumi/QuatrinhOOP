#include "cKhachHangA.h"

cKhachHangA::cKhachHangA() : cKhachHang() {}

void cKhachHangA::TinhTien() {
    // Số tiền = Số lượng * Đơn giá + VAT (10%)
    thanhTien = (soLuong * donGia) * 1.1;
}
