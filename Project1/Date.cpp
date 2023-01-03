#include<iostream>
#include"Date.h"
using namespace std;

//���������ʽ1
int Date::Show()
{
	cout << year << " - " << month << " - " << day;
	return 1;
}

int Date::Change_Date(int a, int b, int c)
{
	year = a;
	month = b;
	day = c;
	return 1;
}

//���������ʽ2
ostream& operator<< (ostream& os, Date& D)
{
	cout << "\n\n\n-------------------------------------------\n\n\t";
	os << D.year << " - " << D.month << " - " << D.day << endl;
	cout << "\n-------------------------------------------\n\n\n";
	return os;
}

//�ж��Ƿ�������
int Judge_Leap_Year(int year)
{
	if ((year % 4 == 0 && (year % 100 != 0)) || year % 400 == 0)
	{
		return 1;
	}
	return 0;
}


//���ظ������Ǳ���ڼ���
int Date::Locate_Year()
{
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, sum = 0;
	for (i = 1; i < month; ++i)
	{
		sum += days[i];
	}
	sum += day;
	if (month > 2 && Judge_Leap_Year(year))sum += 1;
	return sum;
}

//����++
Date& Date:: operator++(int)
{
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 12 && day == 31)
	{
		year++;
		month = 1;
		day = 1;
	}
	else
	{
		if (Judge_Leap_Year(year) && month == 2 && day >= 28)
		{
			if (day == 28)day++;
			else { month = 3; day = 1; }
		}
		else
		{
			if (days[month] == day) { month++; day = 1; }
			else { day++; }
		}
	}
	return *this;
}

//�����������
int Date::Date_Differ(Date BigDay)
{
	int i, sum = 0;
	for (i = year; i < BigDay.year; ++i)
	{
		if (Judge_Leap_Year(i))sum += 366;
		else sum += 365;
	}
	sum += BigDay.Locate_Year();
	sum -= this->Locate_Year();
	return sum;
}