#ifndef SOPHUC_H_INCLUDED
#define SOPHUC_H_INCLUDED
class SoPhuc{
private:
    double iThuc, iAo;
public:
    void Nhap();
    void Xuat();

    SoPhuc Tong(SoPhuc b);
    SoPhuc Hieu(SoPhuc b);
    SoPhuc Tich(SoPhuc b);
    SoPhuc Thuong(SoPhuc b);
};


#endif // SOPHUC_H_INCLUDED
