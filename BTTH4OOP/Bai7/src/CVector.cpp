#include "CVector.h"

CVector::CVector() {
    n = 0;
    v = NULL;
}

CVector::CVector(int n) {
    this->n = n;
    if (n > 0) {
        v = new double[n];
        for (int i = 0; i < n; i++) {
            v[i] = 0;
        }
    } else {
        v = NULL;
    }
}

// Copy constructor (Deep copy)
CVector::CVector(const CVector& other) {
    n = other.n;
    if (n > 0) {
        v = new double[n];
        for (int i = 0; i < n; i++) {
            v[i] = other.v[i];
        }
    } else {
        v = NULL;
    }
}

// Destructor
CVector::~CVector() {
    if (v != NULL) {
        delete[] v;
    }
}

// Assignment operator (Deep copy)
CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        if (v != NULL) delete[] v;

        n = other.n;
        if (n > 0) {
            v = new double[n];
            for (int i = 0; i < n; i++) {
                v[i] = other.v[i];
            }
        } else {
            v = NULL;
        }
    }
    return *this;
}

CVector CVector::operator+(const CVector& other) const {
    if (this->n != other.n) {
        cout << "[Loi] Khong the cong hai vector khac so chieu!\n";
        return CVector(); // Trả về vector rỗng
    }
    CVector res(n);
    for (int i = 0; i < n; i++) {
        res.v[i] = this->v[i] + other.v[i];
    }
    return res;
}

CVector CVector::operator-(const CVector& other) const {
    if (this->n != other.n) {
        cout << "[Loi] Khong the tru hai vector khac so chieu!\n";
        return CVector();
    }
    CVector res(n);
    for (int i = 0; i < n; i++) {
        res.v[i] = this->v[i] - other.v[i];
    }
    return res;
}

double CVector::operator*(const CVector& other) const {
    if (this->n != other.n) {
        cout << "[Loi] Khong the tinh tich vo huong hai vector khac so chieu!\n";
        return 0;
    }
    double dotProduct = 0;
    for (int i = 0; i < n; i++) {
        dotProduct += this->v[i] * other.v[i];
    }
    return dotProduct;
}

CVector CVector::operator*(double k) const {
    CVector res(n);
    for (int i = 0; i < n; i++) {
        res.v[i] = this->v[i] * k;
    }
    return res;
}

istream& operator>>(istream& is, CVector& vec) {
    cout << "Nhap so chieu cua vector: ";
    is >> vec.n;

    if (vec.v != NULL) delete[] vec.v;

    if (vec.n > 0) {
        vec.v = new double[vec.n];
        for (int i = 0; i < vec.n; i++) {
            cout << "Nhap thanh phan thu " << i + 1 << ": ";
            is >> vec.v[i];
        }
    } else {
        vec.v = NULL;
    }
    return is;
}

ostream& operator<<(ostream& os, const CVector& vec) {
    if (vec.n == 0 || vec.v == NULL) {
        os << "()";
        return os;
    }
    os << "(";
    for (int i = 0; i < vec.n; i++) {
        os << vec.v[i];
        if (i < vec.n - 1) os << ", ";
    }
    os << ")";
    return os;
}

int CVector::getKichThuoc() const {
    return n;
}

double CVector::operator[](int i) const {
    if (i >= 0 && i < n) return v[i];
    return 0;
}

void CVector::setPhanTu(int i, double val) {
    if (i >= 0 && i < n) {
        v[i] = val;
    }
}
