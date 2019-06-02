#include "Bian_li_dian.h"

Bian_li_dian::Bian_li_dian()
{
    //cout<<"<欢迎光顾本小店，请开始您的购物之旅>"<<endl;
    ri.clear();
    ifstream in("test.txt",ios::in);              //从文本读入商品信息
    string s,name,is_import;
    double price,discount;
    long long num;
    in>>s>>s>>s>>s>>s;                             //读入中文辅助信息，无用
    while(!in.eof())
    {
        in>>num>>name>>price>>is_import>>discount;
        Comm ls(num,name,price,is_import,discount);
        ri.push_back(ls);
        //cout<<ls.getname()<<endl;
    }
    ri.erase(ri.begin()+(ri.size()-1));             //最后一行读入两从，删一行
    in.close();
}

Bian_li_dian::~Bian_li_dian()
{
    //cout<<"<谢谢惠顾，欢迎下次光临>"<<endl;
}

