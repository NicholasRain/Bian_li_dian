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
	const string df_l;//xxxx年xx月xx日
	const string df_h;//xxxx年xx月xx日xx时xx分xx秒
public:
    /** Default constructor */
	CDate();
	/** Default constructor */
	~CDate();
	/** Return Date String
     *  \param 获取固定格式日期字符串
     */
	string format(string df);
	/** Return Only Number Date String
     *  \param 获取纯数字日期字符串
     */
	string GetDateString();
	/** Return Date Form Only Number Date String
     *  \param 获取数字日期字符串的日期
     */
    string GetDateOfCN(string DateString);
private:
    /** Return At Least Two Bit Digit Form A Number
     *  \param 获取固定格式日期字符串
     */
    string twobitstr(int x);
};
#endif

