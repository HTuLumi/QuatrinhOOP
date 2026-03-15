#include <iostream>

using namespace std;

struct ps
{
    int tu, mau;
};


//Ham nhap tu so mau so
void input(ps &a)
{
    cout << "Nhap tu so : ";
    cin >> a.tu;
    cout << "Nhap mau so : ";
    cin >> a.mau;
}


//Ham xuat phan so
void output(ps a)
{
    cout << a.tu << "/" << a.mau;
}


//ham tra ve max phan so input la ps a,b
ps MaxPS(ps a, ps b)
{
    if (a.tu*b.mau > b.tu*a.mau)
        return a;
    else return b;
}

//Khai bao nhap ps a,b roi tim max
int main()
{
    ps a, b;
    input(a);
    input(b);
    ps PSmax = MaxPS(a,b);
    output(PSmax);
    return 0;
}
