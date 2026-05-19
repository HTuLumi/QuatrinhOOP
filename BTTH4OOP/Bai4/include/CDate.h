#ifndef CDATE_H_INCLUDED
#define CDATE_H_INCLUDED
#include <iostream>

using namespace std;

class CDate {
private:
    int ngay, thang, nam;

    // Các hàm hỗ trợ tính toán ngày tháng
    bool KiemTraNamNhuan(int y) const;
    int SoNgayTrongThang(int m, int y) const;
    int KhoangCachTuMoc() const; // Tính tổng số ngày từ 01/01/0001 để dễ trừ 2 ngày

public:
    CDate(int ngay = 1, int thang = 1, int nam = 1);

    // Toán tử cộng/trừ với số nguyên (ngày)
    CDate operator+(int soNgay) const;
    CDate operator-(int soNgay) const;

    // Toán tử trừ 2 CDate trả về khoảng cách số ngày
    int operator-(const CDate& other) const;

    // Toán tử ++, --
    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);

    // Toán tử nhập xuất
    friend ostream& operator<<(ostream& os, const CDate& d);
    friend istream& operator>>(istream& is, CDate& d);

    // Hàm ứng dụng tính lãi suất
    double TinhLaiSuat(CDate ngayRut, double tienGoi, double laiSuatNam) const;
};

#endif // CDATE_H_INCLUDED
