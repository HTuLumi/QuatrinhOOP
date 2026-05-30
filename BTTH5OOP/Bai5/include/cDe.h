#ifndef CDE_H_INCLUDED
#define CDE_H_INCLUDED
#include "cGiaSuc.h"

class cDe : public cGiaSuc {
public:
    cDe();
    void Keu() override;
    int SinhCon() override;
    int ChoSua() override;
};

#endif // CDE_H_INCLUDED
