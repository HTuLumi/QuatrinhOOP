#include <iostream>
#include "GioPhutGiay.h"
#include "GioPhutGiay.cpp"

using namespace std;

int main()
{
    Time t1;
    t1.Nhap();
    cout <<"Thoi gian da nhap la : "; t1.Xuat();
    Time t2 = t1.TinhCongThemMotGiay();;
    cout<<"Thoi gian sau khi cong them 1 giay la: "; t2.Xuat();
    return 0;
}
