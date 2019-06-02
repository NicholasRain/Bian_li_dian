#include "Comm.h"

Comm::Comm(){}

Comm::Comm(long long num,string name,double price,string is_import,double discount)
{
    this->num=num;
    this->name=name;
    //this->price=price;
    //this->sum=sum;
    this->is_import=is_import;
    this->discount=discount;
    if(is_import=="Y"||is_import=="y")
    {
        this->name=name+"<I>";
        this->price=1.2*price;
    }
    else if(is_import=="N"||is_import=="n")
    {
        this->name=name;
        this->price=price;
    }
}

Comm::~Comm(){}

void Comm::setnum(long long Num)
{
    num=Num;
}

void Comm::setname(string Name)
{
    name=(h[is_import]==1)?(Name+"<I>"):Name;
}

void Comm::setsum(int Sum)
{
    sum=sum+Sum;
}

void Comm::setprice(double Price)
{
    price=0;
    price=Price+h[is_import]*0.2*Price;
}

void Comm::setis_import(string Is_import)
{
    is_import=Is_import;
}

void Comm::setdiscount(double Discount)
{
    discount=Discount;
}

long long Comm::getnum()
{
    return num;
}

string Comm::getname()
{
    return name;
}

int Comm::getsum()
{
    return sum;
}

double Comm::getprice()
{
    return price;
}

double Comm::getdiscount()
{
    return discount;
}

string Comm::getis_import()
{
    return is_import;
}

double Comm::getnewprice()
{
    return discount*price;
}

void Comm::display()
{
    cout<<"---------------------------"<<endl;
    cout<<"商品编号："<<"\t"<<num<<endl;
    cout<<"商品名称："<<"\t"<<name<<endl;
    cout<<"商品原价："<<"\t"<<price<<endl;
    cout<<"商品现价："<<"\t"<<getnewprice()<<endl;
    cout<<"是否进口："<<"\t"<<is_import<<endl;
    cout<<"商品折扣："<<"\t"<<discount<<endl;
    //cout<<"商品数量："<<"\t"<<sum<<endl;
    //int ss=0;
    cout<<"---------------------------"<<endl;
}
