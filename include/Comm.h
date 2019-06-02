#ifndef COMM_H_INCLUDED
#define COMM_H_INCLUDED
#include <string>
#include <map>
#include <iostream>
using namespace std;
class Comm
{
protected:
    long long num;                                        //商品编号
    string name;                                          //商品名称
    int sum=0;                                            //商品数量
    string is_import;                                     //是否进口
    double price;                                         //商品原价
    double newprice;                                      //商品现价
    double discount;                                      //商品折扣
    map<string,int> h={{"Y",1},{"y",1},{"N",0},{"n",0}};
public:

    Comm();
    Comm(long long num,string name,double price,string is_import,double discount);
    ~Comm();
    void setnum(long long Num);
    void setname(string Name);
    void setsum(int Sum);
    void setprice(double Price);
    //void setnewprice(double Newprice);
    void setdiscount(double Discount);
    void setis_import(string Is_import);
    long long getnum();
    string getname();
    int getsum();
    double getprice();
    double getnewprice();
    string getis_import();
    double getdiscount();
    void display();
};


#endif // Comm_H_INCLUDED
