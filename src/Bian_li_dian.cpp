#include "Bian_li_dian.h"

Bian_li_dian::Bian_li_dian()
{
    //cout<<"<��ӭ��˱�С�꣬�뿪ʼ���Ĺ���֮��>"<<endl;
    ri.clear();
    ifstream in("test.txt",ios::in);              //���ı�������Ʒ��Ϣ
    string s,name,is_import;
    double price,discount;
    long long num;
    in>>s>>s>>s>>s>>s;                             //�������ĸ�����Ϣ������
    while(!in.eof())
    {
        in>>num>>name>>price>>is_import>>discount;
        Comm ls(num,name,price,is_import,discount);
        ri.push_back(ls);
        //cout<<ls.getname()<<endl;
    }
    ri.erase(ri.begin()+(ri.size()-1));             //���һ�ж������ӣ�ɾһ��
    in.close();
}

Bian_li_dian::~Bian_li_dian()
{
    //cout<<"<лл�ݹˣ���ӭ�´ι���>"<<endl;
}

