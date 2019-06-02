#include "commodity.h"

commodity::commodity(){}

commodity::commodity(long long num,string name,double price,string is_import,double discount,int sum)
{
    //this->num=num;
    this->name=name;
    //this->price=price;
    this->sum=sum;
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

commodity::~commodity(){}

void commodity::setnum(long long Num)
{
    num=Num;
}

void commodity::setname(string Name)
{
    name=(h[is_import]==1)?Name:Name+"<I>";
}

void commodity::setsum(int Sum)
{
    sum=Sum;
}

void commodity::setprice(double Price)
{
    price=Price+h[is_import]*0.2*Price;
}

void commodity::setis_import(string Is_import)
{
    is_import=Is_import;
}

void commodity::setdiscount(double Discount)
{
    discount=Discount;
}

long long commodity::getnum()
{
    return num;
}

string commodity::getname()
{
    return name;
}

int commodity::getsum()
{
    return sum;
}

double commodity::getprice()
{
    return price;
}

double commodity::getdiscount()
{
    return discount;
}

string commodity::getis_import()
{
    return is_import;
}

double commodity::getnewprice()
{
    return discount*price;
}

void commodity::display()
{
    cout<<"---------------------------"<<endl;
    cout<<"��Ʒ��ţ�"<<"\t"<<num<<endl;
    cout<<"��Ʒ���ƣ�"<<"\t"<<name<<endl;
    cout<<"��Ʒԭ�ۣ�"<<"\t"<<price<<endl;
    cout<<"��Ʒ�ּۣ�"<<"\t"<<getnewprice()<<endl;
    cout<<"�Ƿ���ڣ�"<<"\t"<<is_import<<endl;
    cout<<"��Ʒ�ۿۣ�"<<"\t"<<discount<<endl;
    //cout<<"��Ʒ������"<<"\t"<<sum<<endl;
    cout<<"---------------------------"<<endl;
}
