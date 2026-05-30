#ifndef CKHACHHANG_H_INCLUDED
#define CKHACHHANG_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream> // Thư viện để xử lý file

using namespace std;

class cKhachHang {
protected:
    string hoTen;
    int soLuong;
    double donGia;
    double thanhTien;

public:
    cKhachHang();
    virtual ~cKhachHang();

    // Truyền tham chiếu file vào để Đọc/Ghi trực tiếp
    virtual void Nhap(ifstream& in);
    virtual void Xuat(ofstream& out);
    virtual void TinhTien() = 0; // Phương thức thuần ảo

    double getThanhTien() const;
};

#endif // CKHACHHANG_H_INCLUDED
