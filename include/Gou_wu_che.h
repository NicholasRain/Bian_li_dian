#ifndef GOU_WU_CHE_H_INCLUDED
#define GOU_WU_CHE_H_INCLUDED
#include "order.h"
#include "Comm.h"
#include "Bian_li_dian.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Gou_wu_che
{
private:
    //int sumprice=0;
    bool is_buy=0;            //�ж��Ƿ���㹺�ﳵ
    order o;                  //�˵�����
    Bian_li_dian bld;         //�����������ʾ��Ʒ
public:

    Gou_wu_che();
    ~Gou_wu_che();
    void menu();              //�˵���������ʵ��
    //void setsumprice();`
    //int getsumprice();
};

#endif // GOU_WU_CHE_H_INCLUDED
