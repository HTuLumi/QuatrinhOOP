#include "cPhanSo.h"
#include <cmath>

// Hàm tìm UCLN để rút gọn
int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    return UCLN(b, a % b);
}

void cPhanSo::RutGon() {
    if (mau == 0) return; // Tránh lỗi chia cho 0 trong lúc chuẩn hóa
    if (mau < 0) { // Chuyển dấu trừ lên tử số
        tu = -tu;
        mau = -mau;
    }
    int uc = UCLN(tu, mau);
    if (uc > 0) {
        tu /= uc;
        mau /= uc;
    }
}

cPhanSo::cPhanSo(int tu, int mau) {
    this->tu = tu;
    if (mau == 0) {
        cout << "[Canh bao] Mau so khong the bang 0. He thong tu dong gan mau = 1.\n";
        this->mau = 1;
    } else {
        this->mau = mau;
    }
    RutGon();
}

cPhanSo cPhanSo::operator+(const cPhanSo& other) const {
    return cPhanSo(tu * other.mau + other.tu * mau, mau * other.mau);
}

cPhanSo cPhanSo::operator-(const cPhanSo& other) const {
    return cPhanSo(tu * other.mau - other.tu * mau, mau * other.mau);
}

cPhanSo cPhanSo::operator*(const cPhanSo& other) const {
    return cPhanSo(tu * other.tu, mau * other.mau);
}

cPhanSo cPhanSo::operator/(const cPhanSo& other) const {
    if (other.tu == 0) {
        cout << "[Loi] Khong the chia cho 0! Tra ve phan so 0/1.\n";
        return cPhanSo(0, 1);
    }
    return cPhanSo(tu * other.mau, mau * other.tu);
}

cPhanSo& cPhanSo::operator=(const cPhanSo& other) {
    if (this != &other) {
        tu = other.tu;
        mau = other.mau;
    }
    return *this;
}

bool cPhanSo::operator>(const cPhanSo& other) const {
    // Vì RutGon() đảm bảo mẫu luôn dương, nên có thể quy đồng để so sánh
    return (tu * other.mau) > (other.tu * mau);
}

bool cPhanSo::operator<(const cPhanSo& other) const {
    return (tu * other.mau) < (other.tu * mau);
}

ostream& operator<<(ostream& os, const cPhanSo& ps) {
    if (ps.mau == 1 || ps.tu == 0) {
        os << ps.tu; // In ra số nguyên nếu mẫu là 1 hoặc tử là 0
    } else {
        os << ps.tu << "/" << ps.mau;
    }
    return os;
}

istream& operator>>(istream& is, cPhanSo& ps) {
    cout << "Nhap tu so: ";
    is >> ps.tu;
    do {
        cout << "Nhap mau so (khac 0): ";
        is >> ps.mau;
        if (ps.mau == 0) {
            cout << "Loi! Mau so phai khac 0. Vui long nhap lai.\n";
        }
    } while (ps.mau == 0);
    ps.RutGon();
    return is;
}
