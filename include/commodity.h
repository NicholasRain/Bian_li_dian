#ifndef COMMODITY_H_INCLUDED
#define COMMODITY_H_INCLUDED
#include <string>
#include <map>
#include <iostream>
using namespace std;
class commodity
{
protected:
    long long num;
    string name;
    int sum=0;
    string is_import;
    double price;
    double newprice;
    double discount;
    map<string,int> h={{"Y",1},{"y",1},{"N",0},{"n",0}};
public:

    commodity();
    commodity(long long num,string name,double price,string is_import,double discount,int sum);
    ~commodity();
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


#endif // COMMODITY_H_INCLUDED
