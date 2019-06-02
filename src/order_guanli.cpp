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
    int k=1;            //�ж��Ƿ��ҵ����
    cout<<"�����붩����ţ�";
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
        cout<<"δ�ҵ��ö�������˶Զ������"<<endl;
    }
    cout<<"�Ƿ�������ң�������Y��n��"<<endl;

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
            cout<<"�Ƿ����룬������ѡ��"<<endl;
        }
    }
}

void order_guanli::ogdisplay()
{
    cout<<"======================"<<endl;
    cout<<"1���鿴���ն���       "<<endl;
    cout<<"2���鿴���¶���       "<<endl;
    cout<<"3���鿴���궩��       "<<endl;
    cout<<"4�����²鿴����       "<<endl;
    cout<<"5�����ض�������˵�   "<<endl;
    cout<<"======================"<<endl;
    cout<<"�����������ţ�";
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
                    cout<<"=====����û�ж���====="<<endl;
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
                    cout<<"=====����û�ж���====="<<endl;
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
                    cout<<"=====����û�ж���====="<<endl;
                }
                break;
            }
            case 4:
            {

                while(1)
                {
                    cout<<"�������ѯ�·ݣ���201905����"<<endl;
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
                        cout<<"=====����û�ж���====="<<endl;
                    }
                    cout<<"�Ƿ�������²鿴��������Y��n��"<<endl;
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
                            cout<<"�Ƿ����룬������ѡ��"<<endl;
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
		cout << "�������󣡣�����������" << endl;
		cout << "======================================" << endl;
    }
}

void order_guanli::ogdelete()
{
    string s,ss;
    int k=1;            //�ж��Ƿ��ҵ����
    cout<<"��������Ҫɾ���Ķ�����ţ�";
    cin>>s;
    for(int i=0;i<og.size();++i)
    {
        if(og[i].getorderID()==s)
        {
            og[i].display();
            cout<<"�Ƿ�ȷ��ɾ���ö�����������Y��n��"<<endl;
            while(cin>>ss)
            {
                if(ss=="Y"||ss=="y")
                {
                    og.erase(og.begin()+i);
                    cout<<"ɾ���ɹ�"<<endl;
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
            //og.erase(og.begin()+i);
            k=0;
            break;
        }
    }
    if(k==1)
    {
        cout<<"δ�ҵ��ö�������˶Զ������"<<endl;
    }
    cout<<"�Ƿ����ɾ����������Y��n��"<<endl;
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
            cout<<"�Ƿ����룬������ѡ��"<<endl;
        }
    }
}

void order_guanli::ogupdata()
{
    string s,ss;
    int k=1,sl,n;
    long long bh;
    cout<<"��������Ҫ�޸ĵĶ�����ţ�";
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
                cout<<"1������µ���Ʒ         "<<endl;
                cout<<"2���޸Ĵ�����Ʒ����     "<<endl;
                cout<<"3���˳�                 "<<endl;
                cout<<"========================"<<endl;
                cout<<"��������Ҫִ�й��ܶ�Ӧ�����֣�"<<endl;
                cin>>xy;
                if(xy==1||xy==2||xy==3)
                {
                    switch(xy)
                    {
                        case 1:
                        {
                            cout<<"��������Ҫ�����Ʒ�ı�� "<<endl;
                            cin>>bh;
                            int k1=1,k2=1,sl;
                            for(int j=0;j<og[i].c.size();++j)
                            {
                                if(og[i].c[j].getnum()==bh)
                                {
                                    cout<<"��Ʒ�Ѵ��ڣ���Ҫ�޸���ѡ��2"<<endl;
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
                                        cout<<"��������Ʒ������";
                                        cin>>sl;
                                        if(sl<0)
                                        {
                                            cout<<"���벻�Ϸ���������ѡ��"<<endl;
                                        }
                                        else if(sl==0)
                                        {
                                            cout<<"��Ʒ����Ϊ0���޷�������"<<endl;
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
                                    cout<<"δ�ҵ�����Ʒ����˶���Ʒ���"<<endl;
                                }
                            }
                            break;
                        }
                        case 2:
                        {
                            cout<<"��������Ҫ�޸ĵ���Ʒ��� "<<endl;
                            cin>>bh;
                            int kk=1,uu=1;
                            for(int j=0;j<og[i].c.size();++j)
                            {
                                if(og[i].c[j].getnum()==bh)
                                {
                                    kk=0;
                                    cout<<"������������Ʒ������"<<endl;
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
                                        cout<<"���벻�Ϸ���������ѡ��"<<endl;
                                    }
                                }
                            }
                            if(kk==1)
                            {
                                cout<<"δ�ҵ�����Ʒ����˶���Ʒ���"<<endl;
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
                    cout << "�������󣡣����������룺" << endl;
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
        cout<<"δ�ҵ��ö�������˶Զ������"<<endl;
    }
    /*cout<<"�Ƿ�����޸ģ�������Y��n��"<<endl;
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
            cout<<"�Ƿ����룬������ѡ��"<<endl;
        }
    }*/
}

void order_guanli::ogsave()
{
    ofstream out("ORDER.txt",ios::out);
    for(int i=0;i<og.size();++i)
    {
        out<<"������ţ�"<<" "<<og[i].getorderID()<<endl;
        out<<"����ʱ�䣺"<<" "<<og[i].getorderdate()<<endl;
        out<<"��Ʒ������"<<" "<<og[i].c.size()<<endl;
        //out<<"��Ʒ���"<<" "<<"��Ʒ����"<<" "<<"��Ʒԭ��"<<" "<<"��Ʒ�ּ�"<<" "<<"��Ʒ����"<<"\t"<<"�ۿ�"<<endl;
        out<<setiosflags(ios::left)<<setw(14)<<"��Ʒ���"<<setw(14)<<"��Ʒ����"<<setw(14)<<"��Ʒԭ��"<<setw(14)<<"��Ʒ�ּ�"<<setw(14)<<"��Ʒ����"<<setw(14)<<"�ۿ�"<<endl;
        for(int j=0;j<og[i].c.size();++j)
        {
            out<<setiosflags(ios::left)<<setw(14)<<og[i].c[j].getnum()<<setw(14)<<og[i].c[j].getname()<<setw(14)<<og[i].c[j].getprice()<<setw(14)<<og[i].c[j].getnewprice()<<setw(14)<<og[i].c[j].getsum()<<setw(14)<<og[i].c[j].getdiscount()<<endl;
        }
        out<<setw(60)<<"�ܼۣ�"<<" "<<og[i].getordersum()<<endl;
    }
    out.close();
}

void order_guanli::menu()
{
    int lyb0,lyb1,lyb12=1;
    while(1)
    {
        cout<<"======================="<<endl;
        cout<<"| 1��������ѯ         |"<<endl;
        cout<<"| 2������ɾ��         |"<<endl;
        cout<<"| 3��������ʾ         |"<<endl;
        cout<<"| 4�������޸�         |"<<endl;
        cout<<"| 5���˳�             |"<<endl;
        cout<<"======================="<<endl;
        cout<<"��������Ҫִ�й��ܶ�Ӧ�����֣�"<<endl;
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
            cout << "�������󣡣����������룺" << endl;
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
        cout<<"�������ѯ���ڣ���20190508����"<<endl;
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
            cout<<"���ն���������"<<ans<<"��"<<endl;
            cout<<"���������ܶ"<<sum<<"Ԫ"<<endl;
            cout<<setiosflags(ios::left)<<setw(20)<<"��Ʒ����"<<setw(20)<<"������������"<<endl;
            for(int i=0;i<bb.ri.size();++i)
            {
                cout<<setiosflags(ios::left)<<setw(20)<<bb.ri[i].getname()<<setw(20)<<bb.ri[i].getsum()<<endl;
            }
        }
        if(k==1)
        {
            cout<<"=====����û�ж���====="<<endl;
        }
        cout<<"�Ƿ�����鿴��������Y��n��"<<endl;
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
                cout<<"�Ƿ����룬������ѡ��"<<endl;
            }
        }
        if(u==0)
        break;
    }
}

