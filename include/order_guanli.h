#ifndef ORDER_GUANLI_H_INCLUDED
#define ORDER_GUANLI_H_INCLUDED
#include "order.h"
#include "Comm.h"
#include "date.h"
#include "Bian_li_dian.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
class order_guanli
{
private:
     int lyb3=1;
public:
    vector<order> og; //用vector存放所有的订单
    order_guanli();
    ~order_guanli();
    void ogreadin();  //历史订单的读入储存
    void ogfind();    //订单的查找
    void ogdelete();  //订单的删除
    void ogdisplay(); //订单的显示
    void ogupdata();   //订单的修改
    void ogsave();    //订单的保存
    void menu();      //订单管理菜单
    void xiaoshou();  //销售情况
};


#endif // ORDER_GUANLI_H_INCLUDED
