#include "Import_comm.h"

void Import_comm::setName(string name)
{
    Name=name+"<I>";
}

void Import_comm::setPrice(double price)
{
    Price=price*1.2;
}

string Import_comm::getName()
{
    return Name;
}

double Import_comm::getPrice()
{
    return Price;
}

void Import_comm::Display()
{
    cout<<"---------------------------"<<endl;
    cout<<"商品编号："<<"\t"<<num<<endl;
    cout<<"商品名称："<<"\t"<<name<<endl;
    cout<<"商品原价："<<"\t"<<price<<endl;
    cout<<"商品现价："<<"\t"<<getnewprice()<<endl;
    cout<<"商品折扣："<<"\t"<<discount<<endl;
    cout<<"---------------------------"<<endl;
}
