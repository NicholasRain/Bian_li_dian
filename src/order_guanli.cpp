#include "order_guanli.h"

order_guanli::order_guanli()
{
    og.clear();
}

order_guanli::~order_guanli(){}

void order_guanli::ogreadin()
{
    ifstream in("ORDER.txt",ios::in);
    string ss,sss,s;
    og.clear();
    int n,SUM;
    double a,b,c;
    long long ff;
    while(!in.eof())
    {
        order o1;
        in>>ss>>sss;
        o1.setorderID(sss);
        in>>ss>>sss;
        o1.setorderdate(sss);
        in>>ss>>n;
        //o1.setordernum(n);
        in>>ss>>ss>>ss>>ss>>ss>>ss;
        for(int i=0;i<n;++i)
        {
            in>>ff>>s>>a>>b>>SUM>>c;
            int nn=s.size();
            if(s[nn-1]=='>')
                {
                    ss="Y";
                    s.resize(nn-3);
                    a=a/1.2;
                }
            else
                ss="N";
            Comm c1(ff,s,a,ss,c);
            c1.setsum(SUM);
            o1.c.push_back(c1);
        }
        in>>s>>a;
        o1.setordersum();
        og.push_back(o1);
    }
    og.erase(og.begin()+(og.size()-1));
    in.close();
}

void order_guanli::ogfind()
{
    string s,ss;
    int k=1;            //判断是否找到编号
    cout<<"请输入订单编号：";
    cin>>s;
    for(int i=0;i<og.size();++i)
    {
        if(og[i].getorderID()==s)
        {
            og[i].display();
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"未找到该订单，请核对订单编号"<<endl;
    }
    cout<<"是否继续查找，请输入Y或n："<<endl;

    //cout<<endl;
    while(cin>>ss)
    {
        if(ss=="Y"||ss=="y")
        {
            this->ogfind();
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
}

void order_guanli::ogdisplay()
{
    cout<<"======================"<<endl;
    cout<<"1、查看今日订单       "<<endl;
    cout<<"2、查看本月订单       "<<endl;
    cout<<"3、查看今年订单       "<<endl;
    cout<<"4、按月查看订单       "<<endl;
    cout<<"5、返回订单管理菜单   "<<endl;
    cout<<"======================"<<endl;
    cout<<"请输入操作编号：";
    int n;
    string s,ss,sss;
    cin>>n;
    if(n>=1&&n<=5)
    {
        switch(n)
        {
            case 1:
            {
                ss=CDate().GetDateString();
                ss.resize(8);
                int k=1;
                for(int i=0;i<og.size();++i)
                {
                    s=og[i].getorderID();
                    s.resize(8);
                    if(s==ss)
                    {
                        og[i].display();
                        k=0;
                    }
                }
                if(k==1)
                {
                    cout<<"=====今日没有订单====="<<endl;
                }
                break;
            }
            case 2:
            {
                ss=CDate().GetDateString();
                ss.resize(6);
                int k=1;
                for(int i=0;i<og.size();++i)
                {
                    s=og[i].getorderID();
                    s.resize(6);
                    if(s==ss)
                    {
                        og[i].display();
                        k=0;
                    }
                }
                if(k==1)
                {
                    cout<<"=====本月没有订单====="<<endl;
                }
                break;
            }
            case 3:
            {
                ss=CDate().GetDateString();
                ss.resize(4);
                int k=1;
                for(int i=0;i<og.size();++i)
                {
                    s=og[i].getorderID();
                    s.resize(4);
                    if(s==ss)
                    {
                        og[i].display();
                        k=0;
                    }
                }
                if(k==1)
                {
                    cout<<"=====今年没有订单====="<<endl;
                }
                break;
            }
            case 4:
            {

                while(1)
                {
                    cout<<"请输入查询月份（如201905）："<<endl;
                    cin>>ss;
                    int k=1,u=1;
                    for(int i=0;i<og.size();++i)
                    {
                        s=og[i].getorderID();
                        s.resize(6);
                        if(s==ss)
                        {
                            og[i].display();
                            k=0;
                        }
                    }
                    if(k==1)
                    {
                        cout<<"=====当月没有订单====="<<endl;
                    }
                    cout<<"是否继续按月查看，请输入Y或n："<<endl;
                    //cin>>ss;
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
            case 5:
            {
                lyb3=0;
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
}

void order_guanli::ogdelete()
{
    string s,ss;
    int k=1;            //判断是否找到编号
    cout<<"请输入需要删除的订单编号：";
    cin>>s;
    for(int i=0;i<og.size();++i)
    {
        if(og[i].getorderID()==s)
        {
            og[i].display();
            cout<<"是否确定删除该订单，请输入Y或n："<<endl;
            while(cin>>ss)
            {
                if(ss=="Y"||ss=="y")
                {
                    og.erase(og.begin()+i);
                    cout<<"删除成功"<<endl;
                    break;
                }
                else if(ss=="n"||ss=="N")
                {
                    break;
                }
                else
                {
                    cout<<"非法输入，请重新选择"<<endl;
                }
            }
            //og.erase(og.begin()+i);
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"未找到该订单，请核对订单编号"<<endl;
    }
    cout<<"是否继续删除，请输入Y或n："<<endl;
    while(cin>>ss)
    {
        if(ss=="Y"||ss=="y")
        {
            this->ogdelete();
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
}

void order_guanli::ogupdata()
{
    string s,ss;
    int k=1,sl,n;
    long long bh;
    cout<<"请输入需要修改的订单编号：";
    cin>>s;
    for(int i=0;i<og.size();++i)
    {
        if(og[i].getorderID()==s)
        {
            k=0;
            og[i].display();
            while(1)
            {
                int bj=1,xy;
                cout<<"========================"<<endl;
                cout<<"1、添加新的商品         "<<endl;
                cout<<"2、修改存在商品数量     "<<endl;
                cout<<"3、退出                 "<<endl;
                cout<<"========================"<<endl;
                cout<<"请输入你要执行功能对应的数字："<<endl;
                cin>>xy;
                if(xy==1||xy==2||xy==3)
                {
                    switch(xy)
                    {
                        case 1:
                        {
                            cout<<"请输入需要添加商品的编号 "<<endl;
                            cin>>bh;
                            int k1=1,k2=1,sl;
                            for(int j=0;j<og[i].c.size();++j)
                            {
                                if(og[i].c[j].getnum()==bh)
                                {
                                    cout<<"商品已存在，若要修改请选择2"<<endl;
                                    k1=0;
                                    break;
                                }
                            }
                            if(k1==1)
                            {
                                Bian_li_dian omg;
                                for(int j=0;j<omg.ri.size();++j)
                                {
                                    if(omg.ri[j].getnum()==bh)
                                    {
                                        k2=0;
                                        cout<<"请输入商品数量：";
                                        cin>>sl;
                                        if(sl<0)
                                        {
                                            cout<<"输入不合法，请重新选择"<<endl;
                                        }
                                        else if(sl==0)
                                        {
                                            cout<<"商品数量为0，无法完成添加"<<endl;
                                        }
                                        else
                                        {
                                            Comm cc=omg.ri[j];
                                            cc.setsum(sl);
                                            og[i].c.push_back(cc);
                                            og[i].setordernum();
                                        }
                                    }
                                }
                                if(k2==1)
                                {
                                    cout<<"未找到该商品，请核对商品编号"<<endl;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            cout<<"请输入需要修改的商品编号 "<<endl;
                            cin>>bh;
                            int kk=1,uu=1;
                            for(int j=0;j<og[i].c.size();++j)
                            {
                                if(og[i].c[j].getnum()==bh)
                                {
                                    kk=0;
                                    cout<<"请重新输入商品数量："<<endl;
                                    cin>>sl;
                                    if(sl==0)
                                    {
                                        og[i].c.erase(og[i].c.begin()+j);
                                    }
                                    else if(sl>0)
                                    {
                                       int lyb=og[i].c[j].getsum();
                                       og[i].c[j].setsum(-lyb+sl);
                                       //og[i].c[j].setsum(sl);
                                    }
                                    else
                                    {
                                        cout<<"输入不合法，请重新选择"<<endl;
                                    }
                                }
                            }
                            if(kk==1)
                            {
                                cout<<"未找到该商品，请核对商品编号"<<endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            bj=0;
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
                if(bj==0)
                {
                    break;
                }
            }
        }
    }
    if(k==1)
    {
        cout<<"未找到该订单，请核对订单编号"<<endl;
    }
    /*cout<<"是否继续修改，请输入Y或n："<<endl;
    while(cin>>ss)
    {
        if(ss=="Y"||ss=="y")
        {
            this->ogdelete();
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
    }*/
}

void order_guanli::ogsave()
{
    ofstream out("ORDER.txt",ios::out);
    for(int i=0;i<og.size();++i)
    {
        out<<"订单编号："<<" "<<og[i].getorderID()<<endl;
        out<<"订单时间："<<" "<<og[i].getorderdate()<<endl;
        out<<"商品总数："<<" "<<og[i].c.size()<<endl;
        //out<<"商品编号"<<" "<<"商品名称"<<" "<<"商品原价"<<" "<<"商品现价"<<" "<<"商品数量"<<"\t"<<"折扣"<<endl;
        out<<setiosflags(ios::left)<<setw(14)<<"商品编号"<<setw(14)<<"商品名称"<<setw(14)<<"商品原价"<<setw(14)<<"商品现价"<<setw(14)<<"商品数量"<<setw(14)<<"折扣"<<endl;
        for(int j=0;j<og[i].c.size();++j)
        {
            out<<setiosflags(ios::left)<<setw(14)<<og[i].c[j].getnum()<<setw(14)<<og[i].c[j].getname()<<setw(14)<<og[i].c[j].getprice()<<setw(14)<<og[i].c[j].getnewprice()<<setw(14)<<og[i].c[j].getsum()<<setw(14)<<og[i].c[j].getdiscount()<<endl;
        }
        out<<setw(60)<<"总价："<<" "<<og[i].getordersum()<<endl;
    }
    out.close();
}

void order_guanli::menu()
{
    int lyb0,lyb1,lyb12=1;
    while(1)
    {
        cout<<"======================="<<endl;
        cout<<"| 1、订单查询         |"<<endl;
        cout<<"| 2、订单删除         |"<<endl;
        cout<<"| 3、订单显示         |"<<endl;
        cout<<"| 4、订单修改         |"<<endl;
        cout<<"| 5、退出             |"<<endl;
        cout<<"======================="<<endl;
        cout<<"请输入你要执行功能对应的数字："<<endl;
        cin>>lyb0;
        if(lyb0>=1&&lyb0<=5)
        {
            switch(lyb0)
            {
            case 1:
                {
                    this->ogfind();
                    break;
                }
            case 2:
                {
                    this->ogdelete();
                    break;
                }
            case 3:
                {
                    while(1)
                    {
                        this->ogdisplay();
                        if(lyb3==0)
                            break;
                    }
                    break;
                }
            case 4:
                {
                    this->ogupdata();
                    break;
                }
            case 5:
                {
                    this->ogsave();
                    //exit(0);
                    lyb12=0;
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
        if(lyb12==0)
            break;
    }
}

void order_guanli::xiaoshou()
{
    string ss,s,sss;
    int cut=0;
    while(1)
    {
        double sum=0;
        int ans=0;
        cout<<"请输入查询日期（如20190508）："<<endl;
        cin>>ss;
        int k=1,u=1;
        Bian_li_dian bb;
        for(int i=0;i<og.size();++i)
        {
            s=og[i].getorderID();
            s.resize(8);
            if(s==ss)
            {
                ans++;
                sum+=og[i].getordersum();
                for(int j=0;j<og[i].c.size();++j)
                {
                    sss=og[i].c[j].getname();
                    for(int l=0;l<bb.ri.size();++l)
                    {
                        if(bb.ri[l].getname()==sss)
                        {
                            bb.ri[l].setsum(og[i].c[j].getsum());
                            break;
                        }
                    }
                }
                k=0;
            }
        }
        if(k==0)
        {
            cout<<"当日订单总数："<<ans<<"单"<<endl;
            cout<<"当日销售总额："<<sum<<"元"<<endl;
            cout<<setiosflags(ios::left)<<setw(20)<<"商品名称"<<setw(20)<<"当日销售数量"<<endl;
            for(int i=0;i<bb.ri.size();++i)
            {
                cout<<setiosflags(ios::left)<<setw(20)<<bb.ri[i].getname()<<setw(20)<<bb.ri[i].getsum()<<endl;
            }
        }
        if(k==1)
        {
            cout<<"=====当天没有订单====="<<endl;
        }
        cout<<"是否继续查看，请输入Y或n："<<endl;
        //cin>>ss;
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
}

