#ifndef COMM_GUANLI_H_INCLUDED
#define COMM_GUANLI_H_INCLUDED
#include "Bian_li_dian.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Comm_guanli
{
private:
    Bian_li_dian BLD;
    int k=1;                //用于判断循环退出，无实际意义
public:
    Comm_guanli();
    ~Comm_guanli();
    void cgadd();           //添加商品
    void cgfind();          //查照商品
    void cgdelete();        //删除商品
    void cgupdata();        //修改商品
    void cgmenu();          //商品管理菜单
};
#endif // COMM_GUANLI_H_INCLUDED
