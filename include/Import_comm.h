#ifndef IMPORT_COMM_H_INCLUDED
#define IMPORT_COMM_H_INCLUDED
#include "Comm.h"

class Import_comm:public Comm
{
private:
    string Name;                    //��Ʒ����
    double Price;                   //��Ʒ�۸�
public:
    void setName(string name);
    void setPrice(double price);
    string getName();
    double getPrice();
    void Display();                 //��ʾ��Ʒ��Ϣ
};


#endif // IMPORT_COMM_H_INCLUDED
