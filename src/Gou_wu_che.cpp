#include "Gou_wu_che.h"

Gou_wu_che::Gou_wu_che()
{
    cout<<"<欢迎光顾本小店，请开始您的购物之旅>"<<endl;
    o.Clear();
}

Gou_wu_che::~Gou_wu_che()
{
    cout<<"<谢谢惠顾，欢迎下次光临>"<<endl;
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
        cout<<"| 1、显示所有商品信息 |"<<endl;
        cout<<"| 2、添加商品到购物车 |"<<endl;
        cout<<"| 3、移除商品从购物车 |"<<endl;
        cout<<"| 4、查看购物车       |"<<endl;
        cout<<"| 5、结算购物车       |"<<endl;
        cout<<"| 6、退出             |"<<endl;
        cout<<"======================="<<endl;
        cout<<"请输入你要执行功能对应的数字："<<endl;
        cin>>n;
        if(n>=1&&n<=6)
        {
            switch(n)
            {
            case 1:
                {
                    //cout<<"商品编号 商品名称 商品价格 商品现价 是否进口 商品折扣"<<endl;
                    cout<<setiosflags(ios::left)<<setw(14)<<"商品编号"<<setw(14)<<"商品名称"<<setw(14)<<"商品价格"<<setw(14)<<"商品现价"<<setw(14)<<"是否进口"<<setw(14)<<"商品折扣"<<endl;
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
                    cout<<"请输入商品编号：";
                    cin>>bh;
                    cout<<"请输入购买数量：";
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
                        cout<<"未找到改商品，请核对后输入"<<endl;
                    }
                    cout<<"是否继续添加商品到购物车，请输入Y或n："<<endl;
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
                            cout<<"非法输入，请重新选择："<<endl;
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
                    cout<<"请输入商品编号：";
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
                    cout<<"请核对账单："<<endl;
                    o.display2();
                    cout<<"是否进行结账（请输入Y/n）"<<endl;
                    char a;
                    cin>>a;
                    while(1)
                    {
                         double zq;
                        if(a=='Y'||a=='y')
                        {
                            cout<<"请回答“1&2+3”的结果，答对就可成为会员，只有一次机会"<<endl;
                            string da;
                            cin>>da;
                            is_buy=1;
                            if(da=="1")
                            {
                                cout<<"回答正确，享有9折优惠！"<<endl;
                                zq=0.9*o.getordersum();
                            }
                            else
                                {
                                    cout<<"很遗憾，回答错误！"<<endl;
                                    zq=o.getordersum();
                                }
                            is_buy=1;
                            o.setorderID();
                            o.setorderdate();
                            o.display();
                            da=="1"?(cout<<"\t\t\t\t"<<"实付："<<zq<<endl):(cout<<"\t\t\t\t"<<"实付："<<zq<<endl);
                            string s=o.getorderID();
                    s.resize(8);
                    s=s+".txt";
                    ofstream out(s,ios::out|ios::app);
                    out<<"订单编号："<<o.getorderID()<<endl;
                    out<<"订单时间："<<o.getorderdate()<<endl;
                    //out<<setiosflags(ios::left);
                    //out<<"商品编号"<<setw(10)<<"商品名称"<<setw(10)<<"商品原价"<<setw(10)<<"商品现价"<<setw(10)<<"商品数量"<<setw(10)<<"折扣"<<endl;
                    //out<<"商品编号"<<" "<<"商品名称"<<" "<<"商品原价"<<" "<<"商品现价"<<" "<<"商品数量"<<"\t"<<"折扣"<<endl;
                    out<<setiosflags(ios::left)<<setw(14)<<"商品编号"<<setw(14)<<"商品名称"<<setw(14)<<"商品原价"<<setw(14)<<"商品现价"<<setw(14)<<"商品数量"<<setw(14)<<"折扣"<<endl;
                    for(int i=0;i<o.c.size();++i)
                    {
                        out<<setiosflags(ios::left)<<setw(14)<<o.c[i].getnum()<<setw(14)<<o.c[i].getname()<<setw(14)<<o.c[i].getprice()<<setw(14)<<o.c[i].getnewprice()<<setw(14)<<o.c[i].getsum()<<setw(14)<<o.c[i].getdiscount()<<endl;
                    }
                    //out<<resetiosflags(ios::left);
                    out<<setw(60)<<"总价："<<zq<<endl;
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
                            cout<<"输入不合法，请重新输入：";
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
                    out<<"订单编号："<<" "<<o.getorderID()<<endl;
                    out<<"订单时间："<<" "<<o.getorderdate()<<endl;
                    out<<"商品总数："<<" "<<o.c.size()<<endl;
                    //out<<setiosflags(ios::left);
                    //out<<"商品编号"<<setw(10)<<"商品名称"<<setw(10)<<"商品原价"<<setw(10)<<"商品现价"<<setw(10)<<"商品数量"<<setw(10)<<"折扣"<<endl;
                    //out<<"商品编号"<<" "<<"商品名称"<<" "<<"商品原价"<<" "<<"商品现价"<<" "<<"商品数量"<<"\t"<<"折扣"<<endl;
                    out<<setiosflags(ios::left)<<setw(14)<<"商品编号"<<setw(14)<<"商品名称"<<setw(14)<<"商品原价"<<setw(14)<<"商品现价"<<setw(14)<<"商品数量"<<setw(14)<<"折扣"<<endl;
                    for(int i=0;i<o.c.size();++i)
                    {
                        out<<setiosflags(ios::left)<<setw(14)<<o.c[i].getnum()<<setw(14)<<o.c[i].getname()<<setw(14)<<o.c[i].getprice()<<setw(14)<<o.c[i].getnewprice()<<setw(14)<<o.c[i].getsum()<<setw(14)<<o.c[i].getdiscount()<<endl;
                    }
                    //out<<resetiosflags(ios::left);
                    out<<setw(60)<<"总价："<<" "<<o.getordersum()<<endl;
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
            cout << "输入有误！！请重新输入：" << endl;
            cout << "======================================" << endl;
        }
        if(op==0)
            break;
    }

}
