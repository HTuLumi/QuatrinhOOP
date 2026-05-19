#include "CDaThuc.h"
#include <cmath>

CDaThuc::CDaThuc() {
    n = 0;
    a = new double[1];
    a[0] = 0;
}

CDaThuc::CDaThuc(int bac) {
    n = bac;
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = 0;
    }
}

// Hàm khởi tạo sao chép (Deep copy)
CDaThuc::CDaThuc(const CDaThuc& other) {
    n = other.n;
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = other.a[i];
    }
}

// Hàm hủy giải phóng bộ nhớ
CDaThuc::~CDaThuc() {
    delete[] a;
}

// Toán tử gán (Deep copy)
CDaThuc& CDaThuc::operator=(const CDaThuc& other) {
    if (this != &other) {
        delete[] a; // Xóa mảng cũ
        n = other.n;
        a = new double[n + 1]; // Cấp phát mảng mới
        for (int i = 0; i <= n; i++) {
            a[i] = other.a[i];
        }
    }
    return *this;
}

CDaThuc CDaThuc::operator+(const CDaThuc& other) const {
    int bacMax = max(n, other.n);
    CDaThuc res(bacMax);

    for (int i = 0; i <= bacMax; i++) {
        double heSo1 = (i <= n) ? a[i] : 0;
        double heSo2 = (i <= other.n) ? other.a[i] : 0;
        res.a[i] = heSo1 + heSo2;
    }

    // Chuẩn hóa bậc nếu hệ số bậc cao nhất bị triệt tiêu (vd: x^2 + (-x^2) = 0)
    while (res.n > 0 && res.a[res.n] == 0) {
        res.n--;
    }
    return res;
}

CDaThuc CDaThuc::operator-(const CDaThuc& other) const {
    int bacMax = max(n, other.n);
    CDaThuc res(bacMax);

    for (int i = 0; i <= bacMax; i++) {
        double heSo1 = (i <= n) ? a[i] : 0;
        double heSo2 = (i <= other.n) ? other.a[i] : 0;
        res.a[i] = heSo1 - heSo2;
    }

    while (res.n > 0 && res.a[res.n] == 0) {
        res.n--;
    }
    return res;
}

double CDaThuc::operator()(double x) const {
    double ketQua = 0;
    for (int i = n; i >= 0; i--) {
        ketQua += a[i] * pow(x, i);
    }
    return ketQua;
}

istream& operator>>(istream& is, CDaThuc& dt) {
    cout << "Nhap bac cua da thuc: ";
    int bac;
    is >> bac;
    if (bac < 0) bac = 0;

    // Khởi tạo lại mảng nếu số bậc thay đổi
    delete[] dt.a;
    dt.n = bac;
    dt.a = new double[dt.n + 1];

    for (int i = dt.n; i >= 0; i--) {
        cout << "Nhap he so cua x^" << i << ": ";
        is >> dt.a[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const CDaThuc& dt) {
    bool isZero = true; // Cờ kiểm tra đa thức có bằng 0 hoàn toàn không
    bool isFirst = true;

    for (int i = dt.n; i >= 0; i--) {
        if (dt.a[i] != 0) {
            isZero = false;

            // Xử lý dấu
            if (dt.a[i] > 0 && !isFirst) {
                os << " + ";
            } else if (dt.a[i] < 0) {
                os << (isFirst ? "-" : " - ");
            }

            double val = abs(dt.a[i]);

            // In hệ số (không in số 1 nếu có x đi kèm)
            if (val != 1 || i == 0) {
                os << val;
            }

            // In phần biến x
            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
            isFirst = false;
        }
    }

    if (isZero) {
        os << "0";
    }
    return os;
}
