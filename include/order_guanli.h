#ifndef ORDER_GUANLI_H_INCLUDED
#define ORDER_GUANLI_H_INCLUDED
#include "order.h"
#include "Comm.h"
#include "date.h"
#include "Bian_li_dian.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
class order_guanli
{
private:
     int lyb3=1;
public:
    vector<order> og; //��vector������еĶ���
    order_guanli();
    ~order_guanli();
    void ogreadin();  //��ʷ�����Ķ��봢��
    void ogfind();    //�����Ĳ���
    void ogdelete();  //������ɾ��
    void ogdisplay(); //��������ʾ
    void ogupdata();   //�������޸�
    void ogsave();    //�����ı���
    void menu();      //��������˵�
    void xiaoshou();  //�������
};


#endif // ORDER_GUANLI_H_INCLUDED
