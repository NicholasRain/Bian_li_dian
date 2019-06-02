#include "Comm_guanli.h"

Comm_guanli::Comm_guanli(){}

Comm_guanli::~Comm_guanli(){}

void Comm_guanli::cgadd()
{
    cout<<"������������Ʒ���ƣ�";
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
            cout<<"����Ʒ�Ѵ��ڣ�������ѡ��"<<endl;
            lyb=0;
            break;
        }
    }
    if(lyb==1)
    {
        long long bh=BLD.ri[ls-1].getnum()+1;
        cout<<"������ԭ�ۣ�";
        double pa,pb;
        cin>>pa;
        cout<<"��������Ʒ�Ƿ���ڣ�Y/n����";
        cin>>nnn;
        cout<<"��������Ʒ�ۿۣ�";
        cin>>pb;
        Comm l1(bh,nn,pa,nnn,pb);
        BLD.ri.push_back(l1);
        cout<<"��ӳɹ�"<<endl;
    }
}

void Comm_guanli::cgfind()
{
    long long bh;
    //int sl;
    cout<<"��������Ʒ��ţ�";
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
        cout<<"δ�ҵ�����Ʒ����˶Ժ�����"<<endl;
    }
}

void Comm_guanli::cgdelete()
{
    long long bh;
    //int sl;
    string ss;
    cout<<"��������Ʒ��ţ�";
    cin>>bh;
    int k=1;
    for(int i=0;i<BLD.ri.size();++i)
    {
        if(bh==BLD.ri[i].getnum())
        {
            BLD.ri[i].display();
            cout<<"�Ƿ�ȷ��ɾ������Ʒ��������Y��n��"<<endl;
            while(cin>>ss)
            {
                if(ss=="Y"||ss=="y")
                {
                    BLD.ri.erase(BLD.ri.begin()+i);
                    cout<<"ɾ���ɹ�"<<endl;
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
                    cout<<"�Ƿ����룬������ѡ��"<<endl;
                }
            }
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"δ�ҵ�����Ʒ����˶Ժ�����"<<endl;
    }
}

void Comm_guanli::cgupdata()
{
    long long bh;
    //int sl;
    string ss,s,sss;
    double p;
    cout<<"��������Ʒ��ţ�";
    cin>>bh;
    int k=1;
    for(int i=0;i<BLD.ri.size();++i)
    {
        if(bh==BLD.ri[i].getnum())
        {
            BLD.ri[i].display();
            cout<<"�Ƿ��޸ĸ���Ʒ��������Y��n��"<<endl;
            while(cin>>ss)
            {
                if(ss=="Y"||ss=="y")
                {
                    cout<<"��������Ʒ���ƣ�";
                    cin>>s;
                    //
                    cout<<"��������Ʒ�۸�";
                    cin>>p;
                    cout<<"��������Ʒ�Ƿ���ڣ�";
                    cin>>sss;
                    BLD.ri[i].setis_import(sss);
                    BLD.ri[i].setname(s);
                    BLD.ri[i].setprice(p);
                    cout<<"��������Ʒ�ۿۣ�";
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
                    cout<<"�Ƿ����룬������ѡ��"<<endl;
                }
            }
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"δ�ҵ�����Ʒ����˶Ժ�����"<<endl;
    }
}

void Comm_guanli::cgmenu()
{
    int lyb=1;
    while(1)
    {
        cout<<"---------------------"<<endl;
        cout<<"|1����Ʒ���        |"<<endl;
        cout<<"|2����Ʒ����        |"<<endl;
        cout<<"|3����Ʒɾ��        |"<<endl;
        cout<<"|4����Ʒ�޸�        |"<<endl;
        cout<<"|5����ʾ������Ʒ    |"<<endl;
        cout<<"|6�����ع���Ա�˵�  |"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"��������Ҫִ�еĹ��ܱ�ţ�";
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
                    cout<<setiosflags(ios::left)<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(14)<<"��Ʒ�۸�"<<setw(14)<<"��Ʒ�ּ�"<<setw(14)<<"�Ƿ����"<<setw(14)<<"��Ʒ�ۿ�"<<endl;
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
                    //out<<"��Ʒ���"<<"		  "<<"��Ʒ����"<<"		  "<<"��Ʒ�۸�"<<"		  "<<"�Ƿ����"<<"		  "<<"��Ʒ�ۿ�"<<endl;
                    out<<setiosflags(ios::left)<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(14)<<"��Ʒ�۸�"<<setw(14)<<"�Ƿ����"<<setw(14)<<"��Ʒ�ۿ�"<<endl;
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
            cout << "�������󣡣�����������" << endl;
            cout << "======================================" << endl;
        }
    }

}
