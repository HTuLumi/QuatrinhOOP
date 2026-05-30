#ifndef CCUU_H_INCLUDED
#define CCUU_H_INCLUDED
#include "cGiaSuc.h"

class cCuu : public cGiaSuc {
public:
    cCuu();
    void Keu() override;
    int SinhCon() override;
    int ChoSua() override;
};

#endif // CCUU_H_INCLUDED
