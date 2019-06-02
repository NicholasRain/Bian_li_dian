#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include <iostream>
#include "date.h"
#include <string>
#include "Comm.h"
#include <vector>
#include <iomanip>

using namespace std;
//using namespace Comm;
class order
{
private:
    int ordernum=0;         //销售数量
    double ordersum=0;      //总钱数
    string orderID="1";     //订单编号
    string orderdate="1";   //订单时间

public:
    vector<Comm> c;
    order();
    ~order();
    void add(Comm e,int cnt);
    void Clear();
    void cancel(long long Num);
    void setorderID();
    void setordernum(int n);
    void setordernum();
    void setorderID(string m);
    void setorderdate();
    void setorderdate(string m);
    void setordersum();
    string getorderID();
    string getorderdate();
    int getordernum();
    double getordersum();
    void display();
    void display2();
};



#endif // Comm_H_INCLUDED

