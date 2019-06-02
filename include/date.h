#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
class CDate{
	int d,m,y,hh,mm,ss;
	const string df_s;//xxxx-xx-xx
	const string df_l;//xxxx��xx��xx��
	const string df_h;//xxxx��xx��xx��xxʱxx��xx��
public:
    /** Default constructor */
	CDate();
	/** Default constructor */
	~CDate();
	/** Return Date String
     *  \param ��ȡ�̶���ʽ�����ַ���
     */
	string format(string df);
	/** Return Only Number Date String
     *  \param ��ȡ�����������ַ���
     */
	string GetDateString();
	/** Return Date Form Only Number Date String
     *  \param ��ȡ���������ַ���������
     */
    string GetDateOfCN(string DateString);
private:
    /** Return At Least Two Bit Digit Form A Number
     *  \param ��ȡ�̶���ʽ�����ַ���
     */
    string twobitstr(int x);
};
#endif

