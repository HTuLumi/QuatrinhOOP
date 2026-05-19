#ifndef CTIME_H_INCLUDED
#define CTIME_H_INCLUDED
#include <iostream>

using namespace std;

class CTime {
private:
    int gio, phut, giay;
    void ChuanHoa(); // Hàm hỗ trợ chuẩn hóa thời gian (chống tràn 60s, 60m, 24h)

public:
    CTime(int gio = 0, int phut = 0, int giay = 0);

    // Toán tử cộng/trừ với số nguyên giây
    CTime operator+(int s) const;
    CTime operator-(int s) const;

    // Toán tử ++, -- (cả tiền tố và hậu tố)
    CTime& operator++();    // Tiền tố (++t)
    CTime operator++(int);  // Hậu tố (t++)
    CTime& operator--();    // Tiền tố (--t)
    CTime operator--(int);  // Hậu tố (t--)

    // Toán tử nhập xuất
    friend ostream& operator<<(ostream& os, const CTime& t);
    friend istream& operator>>(istream& is, CTime& t);

    // In đồng hồ góc trên bên phải
    void InDongHo() const;
};

#endif // CTIME_H_INCLUDED
