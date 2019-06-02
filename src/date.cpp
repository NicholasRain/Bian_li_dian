#include"date.h"
CDate::CDate():df_s("ddd"),df_l("DDD"),df_h("HHMMSS")    //初始化
{
	time_t now;

	time(&now);

	struct tm *t_now;

	t_now = localtime(&now);

	y = t_now -> tm_year + 1900;

	m = t_now -> tm_mon + 1;

	d = t_now -> tm_mday;

	hh = t_now -> tm_hour;

	mm = t_now -> tm_min;

	ss = t_now -> tm_sec;
}
CDate::~CDate()
{
    //dtor
}
string CDate::format(string df)
{
		char c_df[20];
		if(df == df_s)
		{
			sprintf(c_df, "%d-%d-%d", y, m, d);
			return string(c_df);
		}
		if(df == df_l)
		{
			sprintf(c_df, "%d年%d月%d日", y, m, d);
			return string(c_df);
		}
		if(df == df_h)
		{
			sprintf(c_df, "%d年%d月%d日%d时%d分%d秒", y, m, d,hh,mm,ss);
			return string(c_df);
		}
		return string("");
}
string CDate::GetDateString(){
    return twobitstr(y)+twobitstr(m)+twobitstr(d)+twobitstr(hh)+twobitstr(mm)+twobitstr(ss);
}
string CDate::GetDateOfCN(string DateString){
    char c_df[20];
    int year,month,day,hour,minute,second;
    sscanf(DateString.substr(0,4).c_str(),"%d",&year);
    sscanf(DateString.substr(4,2).c_str(),"%d",&month);
    sscanf(DateString.substr(6,2).c_str(),"%d",&day);
    sscanf(DateString.substr(8,2).c_str(),"%d",&hour);
    sscanf(DateString.substr(10,2).c_str(),"%d",&minute);
    sscanf(DateString.substr(12,2).c_str(),"%d",&second);
    sprintf(c_df, "%d年%d月%d日%d时%d分%d秒", year, month, day,hour,minute,second);
    return string(c_df);
}

string CDate::twobitstr(int x){
    string res="";
    int xx=x;
    while(x){
        res=char('0'+(x%10))+res;
        x/=10;
    }
    if(xx<10)
        res='0'+res;
    return res;
}

