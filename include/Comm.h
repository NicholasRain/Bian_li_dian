#ifndef COMM_H_INCLUDED
#define COMM_H_INCLUDED
#include <string>
#include <map>
#include <iostream>
using namespace std;
class Comm
{
protected:
    long long num;                                        //��Ʒ���
    string name;                                          //��Ʒ����
    int sum=0;                                            //��Ʒ����
    string is_import;                                     //�Ƿ����
    double price;                                         //��Ʒԭ��
    double newprice;                                      //��Ʒ�ּ�
    double discount;                                      //��Ʒ�ۿ�
    map<string,int> h={{"Y",1},{"y",1},{"N",0},{"n",0}};
public:

    Comm();
    Comm(long long num,string name,double price,string is_import,double discount);
    ~Comm();
    void setnum(long long Num);
    void setname(string Name);
    void setsum(int Sum);
    void setprice(double Price);
    //void setnewprice(double Newprice);
    void setdiscount(double Discount);
    void setis_import(string Is_import);
    long long getnum();
    string getname();
    int getsum();
    double getprice();
    double getnewprice();
    string getis_import();
    double getdiscount();
    void display();
};


#endif // Comm_H_INCLUDED
