#ifndef CBO_H_INCLUDED
#define CBO_H_INCLUDED
#include "cGiaSuc.h"

class cBo : public cGiaSuc {
public:
    cBo();
    void Keu() override;
    int SinhCon() override;
    int ChoSua() override;
};

#endif // CBO_H_INCLUDED
