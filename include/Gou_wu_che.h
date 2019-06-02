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
    bool is_buy=0;            //判断是否结算购物车
    order o;                  //菜单对象
    Bian_li_dian bld;         //便利店对象，显示商品
public:

    Gou_wu_che();
    ~Gou_wu_che();
    void menu();              //菜单包含功能实现
    //void setsumprice();`
    //int getsumprice();
};

#endif // GOU_WU_CHE_H_INCLUDED
