#ifndef COMM_GUANLI_H_INCLUDED
#define COMM_GUANLI_H_INCLUDED
#include "Bian_li_dian.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Comm_guanli
{
private:
    Bian_li_dian BLD;
    int k=1;                //�����ж�ѭ���˳�����ʵ������
public:
    Comm_guanli();
    ~Comm_guanli();
    void cgadd();           //�����Ʒ
    void cgfind();          //������Ʒ
    void cgdelete();        //ɾ����Ʒ
    void cgupdata();        //�޸���Ʒ
    void cgmenu();          //��Ʒ����˵�
};
#endif // COMM_GUANLI_H_INCLUDED
