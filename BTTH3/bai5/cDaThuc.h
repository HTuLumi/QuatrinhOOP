#ifndef CDATHUC_H_INCLUDED
#define CDATHUC_H_INCLUDED

class cDaThuc {
private:
    int n;
    double *a;

public:
    cDaThuc();
    cDaThuc(int bac);
    cDaThuc(const cDaThuc &other);
    ~cDaThuc();

    void Nhap();
    void Xuat();
    double TinhGiaTri(double x);
    cDaThuc Cong(cDaThuc d);
    cDaThuc Tru(cDaThuc d);
};

#endif // CDATHUC_H_INCLUDED
