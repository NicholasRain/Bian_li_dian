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
    cout<<"��Ʒ��ţ�"<<"\t"<<num<<endl;
    cout<<"��Ʒ���ƣ�"<<"\t"<<name<<endl;
    cout<<"��Ʒԭ�ۣ�"<<"\t"<<price<<endl;
    cout<<"��Ʒ�ּۣ�"<<"\t"<<getnewprice()<<endl;
    cout<<"��Ʒ�ۿۣ�"<<"\t"<<discount<<endl;
    cout<<"---------------------------"<<endl;
}
