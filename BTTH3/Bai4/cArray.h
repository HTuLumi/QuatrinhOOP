#ifndef CARRAY_H_INCLUDED
#define CARRAY_H_INCLUDED

class cArray {
private:
    int n;
    int *a;
    bool KiemTraNguyenTo(int x);

public:
    cArray();
    ~cArray();

    void TaoMangNgauNhien();
    void Xuat();
    int DemSoLanXuatHien(int x);
    bool KiemTraTangDan();
    bool TimPhanTuLeNhoNhat(int &res);
    bool TimSoNguyenToLonNhat(int &res);
    void SapXepTangDan();
    void SapXepGiamDan();
};

#endif // CARRAY_H_INCLUDED
