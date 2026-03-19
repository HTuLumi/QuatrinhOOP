#ifndef PHANSO_H_INCLUDED
#define PHANSO_H_INCLUDED
using namespace std;
class PhanSo
{
    private:
        int iTu, iMau;

    public:
        void Nhap();
        void Xuat();
        void RutGon();

        PhanSo Tong(PhanSo b);
        PhanSo Hieu(PhanSo b);
        PhanSo Tich(PhanSo b);
        PhanSo Thuong(PhanSo b);

        int SoSanh(PhanSo b);
};


#endif // PHANSO_H_INCLUDED
