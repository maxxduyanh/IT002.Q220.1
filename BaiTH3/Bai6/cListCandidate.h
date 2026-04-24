#ifndef CLISTCANDIDATE_H
#define CLISTCANDIDATE_H

#include <vector>
#include "cCandidate.h"
using namespace std;

class cListCandidate {
private:
    vector<cCandidate> ds;

public:
    void Nhap();
    void XuatLonHon15();

    cCandidate Max();

    void SapXepGiam();
};

#endif