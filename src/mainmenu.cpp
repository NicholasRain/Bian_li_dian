#include "mainmenu.h"
#include "Guan_li_yuan.h"

mainmenu::mainmenu(){}

mainmenu::~mainmenu(){}

void mainmenu::menu()
{
    while(1)
    {
        int uuu=1;
        string ss;
        cout<<"--------------"<<endl;
        cout<<"|请选择身份：|"<<endl;
        cout<<"|1、顾客     |"<<endl;
        cout<<"|2、管理员   |"<<endl;
        cout<<"--------------"<<endl;
        int n,k=0;
        cin>>n;
        if(n==1||n==2)
        {
            if(n==1)
            {
                Gou_wu_che gwc;            //防止应商品信息更新不及时导致的交易失败
                gwc.menu();
            }
            if(n==2)
            {
                string s,ss;
                cout<<"请输入管理员账号：";
                cin>>s;
                if(s==gly.glygetname())
                {
                    cout<<"请输入密码：";
                    cin>>ss;
                    if(ss==gly.glygetmima())
                    {
                        menu1();
                    }
                    else
                    {
                        cout<<"密码错误！"<<endl;
                    }
                }
                else
                {
                    cout<<"不存在该账号！"<<endl;
                }
            }
        }
        else
        {
            cout<<"非法输入，请重新选择"<<endl;
        }
        cout<<"是否退出程序，请输入Y或n："<<endl;
        while(cin>>ss)
        {
            if(ss=="Y"||ss=="y")
            {
                uuu=0;
                break;
            }
            else if(ss=="n"||ss=="N")
            {
                break;
            }
            else
            {
                cout<<"非法输入，请重新选择："<<endl;
            }
        }
        if(uuu==0)
        {
            break;
        }
    }
}

void mainmenu::menu1()
{
    while(1)
    {
        int kt=1;
        gly.glymenu();
        cout<<"请输入你要执行功能对应的数字："<<endl;
        int lyb2;
        cin>>lyb2;
        if(lyb2>=1&&lyb2<=5)
        {
            switch(lyb2)
            {
            case 1:
                {
                    ogg.ogreadin();
                    ogg.menu();
                    break;
                }
            case 2:
                {
                    CG.cgmenu();
                    break;
                }
            case 3:
                {
                    ogg.ogreadin();
                    ogg.xiaoshou();
                    break;
                }
            case 4:
                {
                    gly.glysetmima();
                    break;
                }
            case 5:
                {
                    kt=0;
                    break;
                }
            }
        }
        else
        {
            cout << "======================================" << endl;
            cout << "输入有误！！请重新输入" << endl;
            cout << "======================================" << endl;
        }
        if(kt==0)
        {
            break;
        }
    }
}
