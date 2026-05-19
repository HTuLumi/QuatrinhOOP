#include "CMatrix.h"

CMatrix::CMatrix() {
    rows = 0; cols = 0; data = NULL;
}

CMatrix::CMatrix(int r, int c) {
    rows = r; cols = c;
    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) data[i][j] = 0;
        }
    } else {
        data = NULL;
    }
}

// Deep copy
CMatrix::CMatrix(const CMatrix& other) {
    rows = other.rows;
    cols = other.cols;
    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    } else {
        data = NULL;
    }
}

CMatrix::~CMatrix() {
    if (data != NULL) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i]; // Xóa từng dòng
        }
        delete[] data; // Xóa mảng con trỏ
    }
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        // Giải phóng vùng nhớ cũ
        if (data != NULL) {
            for (int i = 0; i < rows; i++) delete[] data[i];
            delete[] data;
        }
        // Cấp phát và chép vùng nhớ mới
        rows = other.rows;
        cols = other.cols;
        if (rows > 0 && cols > 0) {
            data = new double*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new double[cols];
                for (int j = 0; j < cols; j++) data[i][j] = other.data[i][j];
            }
        } else {
            data = NULL;
        }
    }
    return *this;
}

CMatrix CMatrix::operator+(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "[Loi] Khong the cong hai ma tran khac kich thuoc!\n";
        return CMatrix();
    }
    CMatrix res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return res;
}

CMatrix CMatrix::operator-(const CMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        cout << "[Loi] Khong the tru hai ma tran khac kich thuoc!\n";
        return CMatrix();
    }
    CMatrix res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return res;
}

CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (cols != other.rows) {
        cout << "[Loi] So cot ma tran 1 phai bang so dong ma tran 2 de nhan!\n";
        return CMatrix();
    }
    CMatrix res(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < cols; k++) {
                res.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return res;
}

CVector CMatrix::operator*(const CVector& v) const {
    /* Mẹo: Để code này chạy được, lớp CVector phải có hàm
       int getKichThuoc() const { return n; }
       và double operator[](int i) const { return v[i]; } */
    if (cols != v.getKichThuoc()) {
        cout << "[Loi] So cot cua ma tran phai bang so chieu cua vector!\n";
        return CVector();
    }
    CVector res(rows);
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += data[i][j] * v[j];
        }
        res.setPhanTu(i, sum); // Cần thêm hàm setPhanTu(index, value) bên CVector
    }
    return res;
}

istream& operator>>(istream& is, CMatrix& m) {
    cout << "Nhap so dong: "; is >> m.rows;
    cout << "Nhap so cot: "; is >> m.cols;

    if (m.data != NULL) {
        for (int i = 0; i < m.rows; i++) delete[] m.data[i];
        delete[] m.data;
    }

    if (m.rows > 0 && m.cols > 0) {
        m.data = new double*[m.rows];
        for (int i = 0; i < m.rows; i++) {
            m.data[i] = new double[m.cols];
            for (int j = 0; j < m.cols; j++) {
                cout << "M[" << i << "][" << j << "] = ";
                is >> m.data[i][j];
            }
        }
    } else { m.data = NULL; }
    return is;
}

ostream& operator<<(ostream& os, const CMatrix& m) {
    if (m.rows == 0 || m.cols == 0 || m.data == NULL) {
        os << "(Ma tran rong)\n";
        return os;
    }
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m.data[i][j] << "\t";
        }
        os << "\n";
    }
    return os;
}
