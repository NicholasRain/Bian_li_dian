#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include "order_guanli.h"
#include "Gou_wu_che.h"
#include "Guan_li_yuan.h"
#include "Comm_guanli.h"
#include <string>
#include <iostream>
using namespace std;

class mainmenu
{
private:
    Comm_guanli CG;                  //商品管理
    //Gou_wu_che gwc;
    order_guanli ogg;                //订单管理
    Guan_li_yuan gly;                //管理员菜单接口
public:
    mainmenu();
    ~mainmenu();
    void menu();                     //主菜单
    void menu1();                    //管理员实现小菜单
};


#endif // MAINMENU_H_INCLUDED
