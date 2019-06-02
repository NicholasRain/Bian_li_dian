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
            cout<<"���Ѿ�����������"<<c[i].getsum()<<endl;
            cout<<"��ѡ��ɾ��������";
            cin>>cnt;
            while(cnt>c[i].getsum())
            {
                cout<<"����ʵ�ʹ������������������룺";
                cin>>cnt;
            }
            while(cnt<0)
            {
                cout<<"���벻�Ϸ������������룺";
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
        cout<<"�����ڸ���Ʒ����˶���Ʒ���"<<endl;
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
    cout<<"������ţ�"<<orderID<<endl;
    cout<<"����ʱ�䣺"<<orderdate<<endl;
    //cout<<"��Ʒ���ࣺ"<<ordernum<<endl;
    cout<<setiosflags(ios::left)<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(14)<<"��Ʒԭ��"<<setw(14)<<"��Ʒ�ּ�"<<setw(14)<<"��Ʒ����"<<setw(14)<<"�ۿ�"<<endl;
    for(int i=0;i<c.size();++i)
    {
        cout<<setiosflags(ios::left)<<setw(14)<<c[i].getnum()<<setw(14)<<c[i].getname()<<setw(14)<<c[i].getprice()<<setw(14)<<c[i].getnewprice()<<setw(14)<<c[i].getsum()<<setw(14)<<c[i].getdiscount()<<endl;
    }
    cout<<"\t\t\t\t"<<"�ܼۣ�"<<getordersum()<<endl;
}

void order::display2()
{
    //orderID=CDate().GetDateString();
    //cout<<"������ţ�"<<orderID<<endl;
    //cout<<"����ʱ�䣺"<<orderdate<<endl;
    //cout<<"����������"<<ordernum<<endl;
    cout<<setiosflags(ios::left)<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(14)<<"��Ʒԭ��"<<setw(14)<<"��Ʒ�ּ�"<<setw(14)<<"��Ʒ����"<<setw(14)<<"�ۿ�"<<endl;
    for(int i=0;i<c.size();++i)
    {
        cout<<setiosflags(ios::left)<<setw(14)<<c[i].getnum()<<setw(14)<<c[i].getname()<<setw(14)<<c[i].getprice()<<setw(14)<<c[i].getnewprice()<<setw(14)<<c[i].getsum()<<setw(14)<<c[i].getdiscount()<<endl;
    }
    cout<<"\t\t\t\t"<<"�ܼۣ�"<<getordersum()<<endl;
}
