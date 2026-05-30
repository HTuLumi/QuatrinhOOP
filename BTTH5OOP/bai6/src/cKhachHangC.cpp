#include "cKhachHangC.h"

cKhachHangC::cKhachHangC() : cKhachHang() {}

void cKhachHangC::TinhTien() {
    // Số tiền = (Số lượng * Đơn giá) * 50% + VAT(10%)
    thanhTien = (soLuong * donGia) * 0.5 * 1.1;
}
