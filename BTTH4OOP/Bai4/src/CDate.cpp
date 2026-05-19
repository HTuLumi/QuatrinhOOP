#include "CDate.h"
#include <iomanip>
#include <cmath>

bool CDate::KiemTraNamNhuan(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int CDate::SoNgayTrongThang(int m, int y) const {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && KiemTraNamNhuan(y)) {
        return 29;
    }
    return daysInMonth[m];
}

int CDate::KhoangCachTuMoc() const {
    int totalDays = 0;
    // Cộng số ngày của các năm trước đó
    for (int i = 1; i < nam; i++) {
        totalDays += KiemTraNamNhuan(i) ? 366 : 365;
    }
    // Cộng số ngày của các tháng trước đó trong năm hiện tại
    for (int i = 1; i < thang; i++) {
        totalDays += SoNgayTrongThang(i, nam);
    }
    // Cộng số ngày hiện tại
    totalDays += ngay;
    return totalDays;
}

CDate::CDate(int ngay, int thang, int nam) {
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

CDate CDate::operator+(int soNgay) const {
    CDate res = *this;
    res.ngay += soNgay;
    while (res.ngay > SoNgayTrongThang(res.thang, res.nam)) {
        res.ngay -= SoNgayTrongThang(res.thang, res.nam);
        res.thang++;
        if (res.thang > 12) {
            res.thang = 1;
            res.nam++;
        }
    }
    return res;
}

CDate CDate::operator-(int soNgay) const {
    CDate res = *this;
    res.ngay -= soNgay;
    while (res.ngay <= 0) {
        res.thang--;
        if (res.thang <= 0) {
            res.thang = 12;
            res.nam--;
        }
        res.ngay += SoNgayTrongThang(res.thang, res.nam);
    }
    return res;
}

int CDate::operator-(const CDate& other) const {
    return abs(this->KhoangCachTuMoc() - other.KhoangCachTuMoc());
}

CDate& CDate::operator++() {
    *this = *this + 1;
    return *this;
}

CDate CDate::operator++(int) {
    CDate temp = *this;
    *this = *this + 1;
    return temp;
}

CDate& CDate::operator--() {
    *this = *this - 1;
    return *this;
}

CDate CDate::operator--(int) {
    CDate temp = *this;
    *this = *this - 1;
    return temp;
}

ostream& operator<<(ostream& os, const CDate& d) {
    os << setfill('0') << setw(2) << d.ngay << "/"
       << setw(2) << d.thang << "/"
       << setw(4) << d.nam;
    return os;
}

istream& operator>>(istream& is, CDate& d) {
    cout << "Nhap ngay: "; is >> d.ngay;
    cout << "Nhap thang: "; is >> d.thang;
    cout << "Nhap nam: "; is >> d.nam;
    return is;
}

double CDate::TinhLaiSuat(CDate ngayRut, double tienGoi, double laiSuatNam) const {
    int soNgayGui = ngayRut - *this;
    // Công thức lãi đơn: Tiền lãi = Tiền gốc * (Lãi suất năm / 100) * (Số ngày gửi / 365)
    return tienGoi * (laiSuatNam / 100.0) * (soNgayGui / 365.0);
}
