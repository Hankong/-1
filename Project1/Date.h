#pragma once
#include<iostream>
#include<string>
using namespace std;

//日期类
class Date
{
public:
	int year;//年
	int month;//月
	int day;//日
	int Date_Differ(Date BigDay);//日期相差天数
	int Locate_Year();//返回该日期是本年第几天
	Date() { year = 0; month = 0; day = 0; }
	int Change_Date(int a, int b, int c);
	Date& operator++(int);//日期加一
	int Show();//输出1
	friend ostream &operator<< (ostream& os, Date & D);//输出2
};