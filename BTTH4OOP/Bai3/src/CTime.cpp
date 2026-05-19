#include <windows.h> // Thư viện dùng để di chuyển con trỏ trên Console (Windows)
#include "CTime.h"
#include <iomanip>

void CTime::ChuanHoa() {
    // Quy đổi tất cả ra giây để tính toán cho dễ
    long long totalSeconds = gio * 3600 + phut * 60 + giay;

    // Nếu bị âm (do trừ quá nhiều), cộng thêm các ngày cho đến khi dương
    if (totalSeconds < 0) {
        totalSeconds = (totalSeconds % 86400 + 86400) % 86400; // 86400s = 24h
    }

    // Tính ngược lại ra giờ, phút, giây
    gio = (totalSeconds / 3600) % 24; // Chỉ lấy trong phạm vi 24h
    phut = (totalSeconds / 60) % 60;
    giay = totalSeconds % 60;
}

CTime::CTime(int gio, int phut, int giay) {
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
    ChuanHoa();
}

CTime CTime::operator+(int s) const {
    return CTime(gio, phut, giay + s);
}

CTime CTime::operator-(int s) const {
    return CTime(gio, phut, giay - s);
}

CTime& CTime::operator++() {
    giay++;
    ChuanHoa();
    return *this;
}

CTime CTime::operator++(int) {
    CTime temp = *this;
    giay++;
    ChuanHoa();
    return temp;
}

CTime& CTime::operator--() {
    giay--;
    ChuanHoa();
    return *this;
}

CTime CTime::operator--(int) {
    CTime temp = *this;
    giay--;
    ChuanHoa();
    return temp;
}

ostream& operator<<(ostream& os, const CTime& t) {
    // In theo format HH:MM:SS (tự động thêm số 0 ở trước nếu < 10)
    os << setfill('0') << setw(2) << t.gio << ":"
       << setw(2) << t.phut << ":"
       << setw(2) << t.giay;
    return os;
}

istream& operator>>(istream& is, CTime& t) {
    cout << "Nhap gio: "; is >> t.gio;
    cout << "Nhap phut: "; is >> t.phut;
    cout << "Nhap giay: "; is >> t.giay;
    t.ChuanHoa();
    return is;
}

// Hàm hỗ trợ nhảy con trỏ chuột trên màn hình Console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CTime::InDongHo() const {
    // Tọa độ góc trên bên phải màn hình (x = 90, y = 0)
    gotoxy(90, 0);
    cout << " [Dong Ho: " << *this << "] ";

    // Trả con trỏ về lại vị trí bình thường để code chạy tiếp không bị đè chữ
    gotoxy(0, 15);
}
