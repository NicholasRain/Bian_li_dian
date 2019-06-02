#include "Guan_li_yuan.h"

Guan_li_yuan::Guan_li_yuan(){}

Guan_li_yuan::~Guan_li_yuan(){}

void Guan_li_yuan::glysetname(string Name)
{
    name=Name;
}

void Guan_li_yuan::glysetmima()
{
    cout<<"请输入原密码：";
    string s,ss;
    cin>>s;
    cout<<endl;
    if(s==mima)
    {
        while(1)
        {
            cout<<"请输入新密码：";
            cin>>s;
            cout<<endl;
            cout<<"请再次输入新密码：";
            cin>>ss;
            cout<<endl;
            if(s==ss)
            {
                mima=ss;
                break;
            }
            else
            {
                cout<<"两次输入不同，请重新输入"<<endl;;
            }
        }
    }
    else
    {
        cout<<"密码错误！"<<endl;
    }
}

string Guan_li_yuan::glygetname()
{
    return name;
}

string Guan_li_yuan::glygetmima()
{
    return mima;
}

void Guan_li_yuan::glymenu()
{
    cout<<"--------------"<<endl;
    cout<<"|1、订单管理 |"<<endl;
    cout<<"|2、商品管理 |"<<endl;
    cout<<"|3、销售情况 |"<<endl;
    cout<<"|4、修改密码 |"<<endl;
    cout<<"|5、退出     |"<<endl;
    cout<<"--------------"<<endl;
}
