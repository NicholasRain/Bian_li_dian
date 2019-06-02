#ifndef BIAN_LI_DIAN_H_INCLUDED
#define BIAN_LI_DIAN_H_INCLUDED
#include "Comm.h"
//#include "Gou_wu_che.h"
#include <fstream>
#include <vector>
using namespace std;

class Bian_li_dian
{
    public:
        vector<Comm> ri;
        Bian_li_dian();
        virtual ~Bian_li_dian();
    private:
};

#endif // BIAN_LI_DIAN_H
