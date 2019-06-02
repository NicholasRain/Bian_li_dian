#include "Comm_guanli.h"

Comm_guanli::Comm_guanli(){}

Comm_guanli::~Comm_guanli(){}

void Comm_guanli::cgadd()
{
    cout<<"请输入新增商品名称：";
    string nn,nnn,lb;
    cin>>nn;
    int lyb=1;
    int ls=BLD.ri.size();
    for(int i=0;i<ls;++i)
    {
        lb=BLD.ri[i].getname();
        if(BLD.ri[i].getis_import()=="Y"||BLD.ri[i].getis_import()=="y")
        {
            lb.resize(lb.size()-3);
            //cout<<lb<<endl;
        }
        if(nn==lb)
        {
            cout<<"该商品已存在，请重新选择"<<endl;
            lyb=0;
            break;
        }
    }
    if(lyb==1)
    {
        long long bh=BLD.ri[ls-1].getnum()+1;
        cout<<"请输入原价：";
        double pa,pb;
        cin>>pa;
        cout<<"请输入商品是否进口（Y/n）：";
        cin>>nnn;
        cout<<"请输入商品折扣：";
        cin>>pb;
        Comm l1(bh,nn,pa,nnn,pb);
        BLD.ri.push_back(l1);
        cout<<"添加成功"<<endl;
    }
}

void Comm_guanli::cgfind()
{
    long long bh;
    //int sl;
    cout<<"请输入商品编号：";
    cin>>bh;
    int k=1;
    for(int i=0;i<BLD.ri.size();++i)
    {
        if(bh==BLD.ri[i].getnum())
        {
            BLD.ri[i].display();
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"未找到改商品，请核对后输入"<<endl;
    }
}

void Comm_guanli::cgdelete()
{
    long long bh;
    //int sl;
    string ss;
    cout<<"请输入商品编号：";
    cin>>bh;
    int k=1;
    for(int i=0;i<BLD.ri.size();++i)
    {
        if(bh==BLD.ri[i].getnum())
        {
            BLD.ri[i].display();
            cout<<"是否确定删除该商品，请输入Y或n："<<endl;
            while(cin>>ss)
            {
                if(ss=="Y"||ss=="y")
                {
                    BLD.ri.erase(BLD.ri.begin()+i);
                    cout<<"删除成功"<<endl;
                    for(long long i=0;i<BLD.ri.size();++i)
                        BLD.ri[i].setnum(i+1);
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
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"未找到改商品，请核对后输入"<<endl;
    }
}

void Comm_guanli::cgupdata()
{
    long long bh;
    //int sl;
    string ss,s,sss;
    double p;
    cout<<"请输入商品编号：";
    cin>>bh;
    int k=1;
    for(int i=0;i<BLD.ri.size();++i)
    {
        if(bh==BLD.ri[i].getnum())
        {
            BLD.ri[i].display();
            cout<<"是否修改该商品，请输入Y或n："<<endl;
            while(cin>>ss)
            {
                if(ss=="Y"||ss=="y")
                {
                    cout<<"请输入商品名称：";
                    cin>>s;
                    //
                    cout<<"请输入商品价格：";
                    cin>>p;
                    cout<<"请输入商品是否进口：";
                    cin>>sss;
                    BLD.ri[i].setis_import(sss);
                    BLD.ri[i].setname(s);
                    BLD.ri[i].setprice(p);
                    cout<<"请输入商品折扣：";
                    cin>>p;
                    BLD.ri[i].setdiscount(p);
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
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"未找到改商品，请核对后输入"<<endl;
    }
}

void Comm_guanli::cgmenu()
{
    int lyb=1;
    while(1)
    {
        cout<<"---------------------"<<endl;
        cout<<"|1、商品添加        |"<<endl;
        cout<<"|2、商品查找        |"<<endl;
        cout<<"|3、商品删除        |"<<endl;
        cout<<"|4、商品修改        |"<<endl;
        cout<<"|5、显示所有商品    |"<<endl;
        cout<<"|6、返回管理员菜单  |"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"请输入想要执行的功能编号：";
        int n;
        cin>>n;
        if(n>=1&&n<=6)
        {
            switch(n)
            {
            case 1:
                {
                    cgadd();
                    break;
                }
            case 2:
                {
                    cgfind();
                    break;
                }
            case 3:
                {
                    cgdelete();
                    break;
                }
            case 4:
                {
                    cgupdata();
                    break;
                }
            case 5:
                {
                    cout<<setiosflags(ios::left)<<setw(14)<<"商品编号"<<setw(14)<<"商品名称"<<setw(14)<<"商品价格"<<setw(14)<<"商品现价"<<setw(14)<<"是否进口"<<setw(14)<<"商品折扣"<<endl;
                    for(int i=0;i<BLD.ri.size();++i)
                    {
                        Comm ll=BLD.ri[i];
                        cout<<setiosflags(ios::left)<<setw(14)<<ll.getnum()<<setw(14)<<ll.getname()<<setw(14)<<ll.getprice()<<setw(14)<<ll.getnewprice()<<setw(14)<<ll.getis_import()<<setw(14)<<ll.getdiscount()<<endl;

                        //cout<<bld.ri[i].getnum()<<"\t"<<bld.ri[i].getname()<<"\t"<<bld.ri[i].getprice()<<"\t"<<bld.ri[i].getnewprice()<<bld.ri[i].getis_import()<<bld.ri[i].gediscount()<<endl;
                    }
                    break;
                }
            case 6:
                {
                    string os;
                    int nnn;
                    double oos;
                    ofstream out("test.txt",ios::out);
                    //out<<"商品编号"<<"		  "<<"商品名称"<<"		  "<<"商品价格"<<"		  "<<"是否进口"<<"		  "<<"商品折扣"<<endl;
                    out<<setiosflags(ios::left)<<setw(14)<<"商品编号"<<setw(14)<<"商品名称"<<setw(14)<<"商品价格"<<setw(14)<<"是否进口"<<setw(14)<<"商品折扣"<<endl;
                    for(int i=0;i<BLD.ri.size();++i)
                    {
                        if(BLD.ri[i].getis_import()=="Y"||BLD.ri[i].getis_import()=="y")
                        {
                            os=BLD.ri[i].getname();
                            //nnn=
                            os.resize(os.size()-3);
                            oos=BLD.ri[i].getprice();
                            oos=oos/1.2;
                            out<<setiosflags(ios::left)<<setw(14)<<BLD.ri[i].getnum()<<setw(14)<<os<<setw(14)<<oos<<setw(14)<<BLD.ri[i].getis_import()<<setw(14)<<BLD.ri[i].getdiscount()<<endl;
                        }
                        else
                        {
                            out<<setiosflags(ios::left)<<setw(14)<<BLD.ri[i].getnum()<<setw(14)<<BLD.ri[i].getname()<<setw(14)<<BLD.ri[i].getprice()<<setw(14)<<BLD.ri[i].getis_import()<<setw(14)<<BLD.ri[i].getdiscount()<<endl;
                        }

                    }
                    out.close();
                    lyb=0;
                    break;
                }
            }
            if(lyb==0)
                break;
        }
        else
        {
            cout << "======================================" << endl;
            cout << "输入有误！！请重新输入" << endl;
            cout << "======================================" << endl;
        }
    }

}
