#ifndef IMPORT_COMM_H_INCLUDED
#define IMPORT_COMM_H_INCLUDED
#include "Comm.h"

class Import_comm:public Comm
{
private:
    string Name;                    //商品名称
    double Price;                   //商品价格
public:
    void setName(string name);
    void setPrice(double price);
    string getName();
    double getPrice();
    void Display();                 //显示商品信息
};


#endif // IMPORT_COMM_H_INCLUDED
