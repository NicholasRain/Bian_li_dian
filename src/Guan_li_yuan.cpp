#include "Guan_li_yuan.h"

Guan_li_yuan::Guan_li_yuan(){}

Guan_li_yuan::~Guan_li_yuan(){}

void Guan_li_yuan::glysetname(string Name)
{
    name=Name;
}

void Guan_li_yuan::glysetmima()
{
    cout<<"������ԭ���룺";
    string s,ss;
    cin>>s;
    cout<<endl;
    if(s==mima)
    {
        while(1)
        {
            cout<<"�����������룺";
            cin>>s;
            cout<<endl;
            cout<<"���ٴ����������룺";
            cin>>ss;
            cout<<endl;
            if(s==ss)
            {
                mima=ss;
                break;
            }
            else
            {
                cout<<"�������벻ͬ������������"<<endl;;
            }
        }
    }
    else
    {
        cout<<"�������"<<endl;
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
    cout<<"|1���������� |"<<endl;
    cout<<"|2����Ʒ���� |"<<endl;
    cout<<"|3��������� |"<<endl;
    cout<<"|4���޸����� |"<<endl;
    cout<<"|5���˳�     |"<<endl;
    cout<<"--------------"<<endl;
}
