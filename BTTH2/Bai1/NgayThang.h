#ifndef NGAYTHANG_H_INCLUDED
#define NGAYTHANG_H_INCLUDED

using namespace std;
class NgayThang
{
    private:
        int iNgay, iThang, iNam;

    public:
        void Nhap();
        void Xuat();
        NgayThang NgayThangNamTiepTheo();
};

#endif // NGAYTHANG_H_INCLUDED
