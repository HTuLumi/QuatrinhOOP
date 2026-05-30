#ifndef CGIASUC_H_INCLUDED
#define CGIASUC_H_INCLUDED
#include <iostream>
#include <string>
#include <cstdlib> // Thư viện dùng hàm rand()

using namespace std;

class cGiaSuc {
protected:
    string loai;

public:
    cGiaSuc();
    virtual ~cGiaSuc();

    virtual void Keu() = 0;
    virtual int SinhCon() = 0;
    virtual int ChoSua() = 0;

    string getLoai() const;
};

#endif // CGIASUC_H_INCLUDED
