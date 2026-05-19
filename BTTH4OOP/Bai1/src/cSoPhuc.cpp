#include "cSoPhuc.h"

cSoPhuc::cSoPhuc(double thuc, double ao) {
    this->thuc = thuc;
    this->ao = ao;
}

cSoPhuc cSoPhuc::operator+(const cSoPhuc& other) const {
    return cSoPhuc(thuc + other.thuc, ao + other.ao);
}

cSoPhuc cSoPhuc::operator-(const cSoPhuc& other) const {
    return cSoPhuc(thuc - other.thuc, ao - other.ao);
}

cSoPhuc cSoPhuc::operator*(const cSoPhuc& other) const {
    return cSoPhuc(thuc * other.thuc - ao * other.ao, thuc * other.ao + ao * other.thuc);
}

cSoPhuc cSoPhuc::operator/(const cSoPhuc& other) const {
    double mauSo = other.thuc * other.thuc + other.ao * other.ao;
    if (mauSo == 0) {
        cout << "Loi chia cho 0!" << endl;
        return cSoPhuc(0, 0);
    }
    double thucMoi = (thuc * other.thuc + ao * other.ao) / mauSo;
    double aoMoi = (ao * other.thuc - thuc * other.ao) / mauSo;
    return cSoPhuc(thucMoi, aoMoi);
}

cSoPhuc& cSoPhuc::operator=(const cSoPhuc& other) {
    if (this != &other) {
        thuc = other.thuc;
        ao = other.ao;
    }
    return *this;
}

bool cSoPhuc::operator!=(const cSoPhuc& other) const {
    return (thuc != other.thuc) || (ao != other.ao);
}

ostream& operator<<(ostream& os, const cSoPhuc& sp) {
    if (sp.thuc == 0 && sp.ao == 0) {
        os << "0";
    } else if (sp.thuc == 0) {
        os << sp.ao << "i";
    } else if (sp.ao == 0) {
        os << sp.thuc;
    } else {
        os << sp.thuc << (sp.ao > 0 ? " + " : " - ") << abs(sp.ao) << "i";
    }
    return os;
}

istream& operator>>(istream& is, cSoPhuc& sp) {
    cout << "Nhap phan thuc: ";
    is >> sp.thuc;
    cout << "Nhap phan ao: ";
    is >> sp.ao;
    return is;
}
