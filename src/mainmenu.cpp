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
        cout<<"|��ѡ����ݣ�|"<<endl;
        cout<<"|1���˿�     |"<<endl;
        cout<<"|2������Ա   |"<<endl;
        cout<<"--------------"<<endl;
        int n,k=0;
        cin>>n;
        if(n==1||n==2)
        {
            if(n==1)
            {
                Gou_wu_che gwc;            //��ֹӦ��Ʒ��Ϣ���²���ʱ���µĽ���ʧ��
                gwc.menu();
            }
            if(n==2)
            {
                string s,ss;
                cout<<"���������Ա�˺ţ�";
                cin>>s;
                if(s==gly.glygetname())
                {
                    cout<<"���������룺";
                    cin>>ss;
                    if(ss==gly.glygetmima())
                    {
                        menu1();
                    }
                    else
                    {
                        cout<<"�������"<<endl;
                    }
                }
                else
                {
                    cout<<"�����ڸ��˺ţ�"<<endl;
                }
            }
        }
        else
        {
            cout<<"�Ƿ����룬������ѡ��"<<endl;
        }
        cout<<"�Ƿ��˳�����������Y��n��"<<endl;
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
                cout<<"�Ƿ����룬������ѡ��"<<endl;
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
        cout<<"��������Ҫִ�й��ܶ�Ӧ�����֣�"<<endl;
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
            cout << "�������󣡣�����������" << endl;
            cout << "======================================" << endl;
        }
        if(kt==0)
        {
            break;
        }
    }
}
