#ifndef GUAN_LI_YUAN_H_INCLUDED
#define GUAN_LI_YUAN_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Guan_li_yuan
{
private:
    string name="123";                //账号
    string mima="123";                //密码
public:
    Guan_li_yuan();
    ~Guan_li_yuan();
    void glysetname(string Name);
    void glysetmima();
    void glymenu();                   //管理员菜单
    string glygetname();
    string glygetmima();
};


#endif // GUAN_LI_YUAN_H_INCLUDED
