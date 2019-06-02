#include "order.h"
order::order(){}

order::~order(){}

void order::add(Comm e,int cnt)
{
    e.setsum(cnt);
    int k=1;
    for(int i=0;i<c.size();++i)
    {
        if(c[i].getnum()==e.getnum())
        {
            c[i].setsum(cnt);
            k=0;
            break;
        }
    }
    if(k==1)
    c.push_back(e);
    ordernum+=cnt;
}

void order::cancel(long long Num)
{
    int k=1;
    for(int i=0;i<c.size();++i)
    {
        int cnt;
        if(c[i].getnum()==Num)
        {
            cout<<"先已经购买数量："<<c[i].getsum()<<endl;
            cout<<"请选择删除数量：";
            cin>>cnt;
            while(cnt>c[i].getsum())
            {
                cout<<"超出实际购买数量，请重新输入：";
                cin>>cnt;
            }
            while(cnt<0)
            {
                cout<<"输入不合法，请重新输入：";
                cin>>cnt;
            }
            if(cnt==c[i].getsum())
            c.erase(c.begin()+i);
            else
                c[i].setsum(-cnt);
            k=0;
            ordernum-=cnt;
            break;
        }
    }
    if(k==1)
    {
        cout<<"不存在该商品，请核对商品编号"<<endl;
    }
}

void order::Clear()
{
    c.clear();
}

void order::setorderID()
{
    orderID=CDate().GetDateString();
}

void order::setorderID(string m)
{
    orderID=m;
}

void order::setordernum(int n)
{
    ordernum+=n;
}

void order::setordernum()
{
    ordernum=0;
    for(int i=0;i<c.size();++i)
    {
        ordernum+=c[i].getsum();
    }
}

void order::setordersum()
{
    ordersum=0;
    for(int i=0;i<c.size();++i)
    {
        ordersum+=(c[i].getnewprice()*c[i].getsum());
    }
}

void order::setorderdate()
{
    orderdate=CDate().GetDateOfCN(orderID);
}

void order::setorderdate(string m)
{
    orderdate=m;
}

string order::getorderID()
{
    return orderID;
}

string order::getorderdate()
{
    return orderdate;
}

int order::getordernum()
{
    return ordernum;
}

double order::getordersum()
{
    this->setordersum();
    return this->ordersum;
}

void order::display()
{
    //orderID=CDate().GetDateString();
    cout<<"订单编号："<<orderID<<endl;
    cout<<"订单时间："<<orderdate<<endl;
    //cout<<"商品种类："<<ordernum<<endl;
    cout<<setiosflags(ios::left)<<setw(14)<<"商品编号"<<setw(14)<<"商品名称"<<setw(14)<<"商品原价"<<setw(14)<<"商品现价"<<setw(14)<<"商品数量"<<setw(14)<<"折扣"<<endl;
    for(int i=0;i<c.size();++i)
    {
        cout<<setiosflags(ios::left)<<setw(14)<<c[i].getnum()<<setw(14)<<c[i].getname()<<setw(14)<<c[i].getprice()<<setw(14)<<c[i].getnewprice()<<setw(14)<<c[i].getsum()<<setw(14)<<c[i].getdiscount()<<endl;
    }
    cout<<"\t\t\t\t"<<"总价："<<getordersum()<<endl;
}

void order::display2()
{
    //orderID=CDate().GetDateString();
    //cout<<"订单编号："<<orderID<<endl;
    //cout<<"订单时间："<<orderdate<<endl;
    //cout<<"购买总数："<<ordernum<<endl;
    cout<<setiosflags(ios::left)<<setw(14)<<"商品编号"<<setw(14)<<"商品名称"<<setw(14)<<"商品原价"<<setw(14)<<"商品现价"<<setw(14)<<"商品数量"<<setw(14)<<"折扣"<<endl;
    for(int i=0;i<c.size();++i)
    {
        cout<<setiosflags(ios::left)<<setw(14)<<c[i].getnum()<<setw(14)<<c[i].getname()<<setw(14)<<c[i].getprice()<<setw(14)<<c[i].getnewprice()<<setw(14)<<c[i].getsum()<<setw(14)<<c[i].getdiscount()<<endl;
    }
    cout<<"\t\t\t\t"<<"总价："<<getordersum()<<endl;
}
