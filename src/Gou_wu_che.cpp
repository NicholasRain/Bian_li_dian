#include "Gou_wu_che.h"

Gou_wu_che::Gou_wu_che()
{
    cout<<"<��ӭ��˱�С�꣬�뿪ʼ���Ĺ���֮��>"<<endl;
    o.Clear();
}

Gou_wu_che::~Gou_wu_che()
{
    cout<<"<лл�ݹˣ���ӭ�´ι���>"<<endl;
}

/*void Gou_wu_che::setsumprice()
{
    for(int i=0;i<o.c.size();++i)
    {
        sumprice+=(o.c[i].getnewprice()*o.c[i].getsum());
    }
}

int Gou_wu_che::getsumprice()
{
    return sumprice;
}*/

void Gou_wu_che::menu()
{
    int n,op=1;
    while(1)
    {
        cout<<"======================="<<endl;
        cout<<"| 1����ʾ������Ʒ��Ϣ |"<<endl;
        cout<<"| 2�������Ʒ�����ﳵ |"<<endl;
        cout<<"| 3���Ƴ���Ʒ�ӹ��ﳵ |"<<endl;
        cout<<"| 4���鿴���ﳵ       |"<<endl;
        cout<<"| 5�����㹺�ﳵ       |"<<endl;
        cout<<"| 6���˳�             |"<<endl;
        cout<<"======================="<<endl;
        cout<<"��������Ҫִ�й��ܶ�Ӧ�����֣�"<<endl;
        cin>>n;
        if(n>=1&&n<=6)
        {
            switch(n)
            {
            case 1:
                {
                    //cout<<"��Ʒ��� ��Ʒ���� ��Ʒ�۸� ��Ʒ�ּ� �Ƿ���� ��Ʒ�ۿ�"<<endl;
                    cout<<setiosflags(ios::left)<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(14)<<"��Ʒ�۸�"<<setw(14)<<"��Ʒ�ּ�"<<setw(14)<<"�Ƿ����"<<setw(14)<<"��Ʒ�ۿ�"<<endl;
                    for(int i=0;i<bld.ri.size();++i)
                    {
                        Comm ll=bld.ri[i];
                        cout<<setiosflags(ios::left)<<setw(14)<<ll.getnum()<<setw(14)<<ll.getname()<<setw(14)<<ll.getprice()<<setw(14)<<ll.getnewprice()<<setw(14)<<ll.getis_import()<<setw(14)<<ll.getdiscount()<<endl;

                        //cout<<bld.ri[i].getnum()<<"\t"<<bld.ri[i].getname()<<"\t"<<bld.ri[i].getprice()<<"\t"<<bld.ri[i].getnewprice()<<bld.ri[i].getis_import()<<bld.ri[i].gediscount()<<endl;
                    }
                    //for(int i=0;i<u.size();++i)
                    break;
                }
            case 2:
                {
                    long long bh;
                    int sl,u=1;
                    while(1){
                    cout<<"��������Ʒ��ţ�";
                    cin>>bh;
                    cout<<"�����빺��������";
                    cin>>sl;
                    cout<<endl;
                    int k=1;
                    for(int i=0;i<bld.ri.size();++i)
                    {
                        if(bh==bld.ri[i].getnum())
                        {
                            o.add(bld.ri[i],sl);
                            k=0;
                            break;
                        }
                    }
                    if(k==1)
                    {
                        cout<<"δ�ҵ�����Ʒ����˶Ժ�����"<<endl;
                    }
                    cout<<"�Ƿ���������Ʒ�����ﳵ��������Y��n��"<<endl;
                    //cin>>ss;
                    string ss;
                    while(cin>>ss)
                    {
                        if(ss=="Y"||ss=="y")
                        {
                            //u=0;
                            break;
                        }
                        else if(ss=="n"||ss=="N")
                        {
                            u=0;
                            break;
                        }
                        else
                        {
                            cout<<"�Ƿ����룬������ѡ��"<<endl;
                        }
                    }
                    if(u==0)
                        break;
                    }
                    break;
                }
            case 3:
                {
                    long long bh;
                    cout<<"��������Ʒ��ţ�";
                    cin>>bh;
                    cout<<endl;
                    o.cancel(bh);
                    break;
                }
            case 4:
                {
                    o.display2();
                    break;
                }
            case 5:
                {
                    cout<<"��˶��˵���"<<endl;
                    o.display2();
                    cout<<"�Ƿ���н��ˣ�������Y/n��"<<endl;
                    char a;
                    cin>>a;
                    while(1)
                    {
                         double zq;
                        if(a=='Y'||a=='y')
                        {
                            cout<<"��ش�1&2+3���Ľ������ԾͿɳ�Ϊ��Ա��ֻ��һ�λ���"<<endl;
                            string da;
                            cin>>da;
                            is_buy=1;
                            if(da=="1")
                            {
                                cout<<"�ش���ȷ������9���Żݣ�"<<endl;
                                zq=0.9*o.getordersum();
                            }
                            else
                                {
                                    cout<<"���ź����ش����"<<endl;
                                    zq=o.getordersum();
                                }
                            is_buy=1;
                            o.setorderID();
                            o.setorderdate();
                            o.display();
                            da=="1"?(cout<<"\t\t\t\t"<<"ʵ����"<<zq<<endl):(cout<<"\t\t\t\t"<<"ʵ����"<<zq<<endl);
                            string s=o.getorderID();
                    s.resize(8);
                    s=s+".txt";
                    ofstream out(s,ios::out|ios::app);
                    out<<"������ţ�"<<o.getorderID()<<endl;
                    out<<"����ʱ�䣺"<<o.getorderdate()<<endl;
                    //out<<setiosflags(ios::left);
                    //out<<"��Ʒ���"<<setw(10)<<"��Ʒ����"<<setw(10)<<"��Ʒԭ��"<<setw(10)<<"��Ʒ�ּ�"<<setw(10)<<"��Ʒ����"<<setw(10)<<"�ۿ�"<<endl;
                    //out<<"��Ʒ���"<<" "<<"��Ʒ����"<<" "<<"��Ʒԭ��"<<" "<<"��Ʒ�ּ�"<<" "<<"��Ʒ����"<<"\t"<<"�ۿ�"<<endl;
                    out<<setiosflags(ios::left)<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(14)<<"��Ʒԭ��"<<setw(14)<<"��Ʒ�ּ�"<<setw(14)<<"��Ʒ����"<<setw(14)<<"�ۿ�"<<endl;
                    for(int i=0;i<o.c.size();++i)
                    {
                        out<<setiosflags(ios::left)<<setw(14)<<o.c[i].getnum()<<setw(14)<<o.c[i].getname()<<setw(14)<<o.c[i].getprice()<<setw(14)<<o.c[i].getnewprice()<<setw(14)<<o.c[i].getsum()<<setw(14)<<o.c[i].getdiscount()<<endl;
                    }
                    //out<<resetiosflags(ios::left);
                    out<<setw(60)<<"�ܼۣ�"<<zq<<endl;
                    out.close();
                            //exit(0);
                            break;
                        }
                        else if(a=='n'||a=='N')
                        {
                            break;
                        }
                        else
                        {
                            cout<<"���벻�Ϸ������������룺";
                            cin>>a;
                        }
                    }
                    break;
                }
            case 6:
                {
                    //string s=o.getorderID();
                    //s.resize(8);
                    //s=s+".txt";
                    if(is_buy==1)
                    {ofstream out("ORDER.txt",ios::out|ios::app);
                    out<<"������ţ�"<<" "<<o.getorderID()<<endl;
                    out<<"����ʱ�䣺"<<" "<<o.getorderdate()<<endl;
                    out<<"��Ʒ������"<<" "<<o.c.size()<<endl;
                    //out<<setiosflags(ios::left);
                    //out<<"��Ʒ���"<<setw(10)<<"��Ʒ����"<<setw(10)<<"��Ʒԭ��"<<setw(10)<<"��Ʒ�ּ�"<<setw(10)<<"��Ʒ����"<<setw(10)<<"�ۿ�"<<endl;
                    //out<<"��Ʒ���"<<" "<<"��Ʒ����"<<" "<<"��Ʒԭ��"<<" "<<"��Ʒ�ּ�"<<" "<<"��Ʒ����"<<"\t"<<"�ۿ�"<<endl;
                    out<<setiosflags(ios::left)<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(14)<<"��Ʒԭ��"<<setw(14)<<"��Ʒ�ּ�"<<setw(14)<<"��Ʒ����"<<setw(14)<<"�ۿ�"<<endl;
                    for(int i=0;i<o.c.size();++i)
                    {
                        out<<setiosflags(ios::left)<<setw(14)<<o.c[i].getnum()<<setw(14)<<o.c[i].getname()<<setw(14)<<o.c[i].getprice()<<setw(14)<<o.c[i].getnewprice()<<setw(14)<<o.c[i].getsum()<<setw(14)<<o.c[i].getdiscount()<<endl;
                    }
                    //out<<resetiosflags(ios::left);
                    out<<setw(60)<<"�ܼۣ�"<<" "<<o.getordersum()<<endl;
                    out.close();
                    }
                    //exit(0);
                    op=0;
                    break;
                }
            }
        }
        else
        {
            cout << "======================================" << endl;
            cout << "�������󣡣����������룺" << endl;
            cout << "======================================" << endl;
        }
        if(op==0)
            break;
    }

}
