#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include "order_guanli.h"
#include "Gou_wu_che.h"
#include "Guan_li_yuan.h"
#include "Comm_guanli.h"
#include <string>
#include <iostream>
using namespace std;

class mainmenu
{
private:
    Comm_guanli CG;                  //��Ʒ����
    //Gou_wu_che gwc;
    order_guanli ogg;                //��������
    Guan_li_yuan gly;                //����Ա�˵��ӿ�
public:
    mainmenu();
    ~mainmenu();
    void menu();                     //���˵�
    void menu1();                    //����Աʵ��С�˵�
};


#endif // MAINMENU_H_INCLUDED
