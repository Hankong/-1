#pragma once
#include<iostream>
#include<string>
using namespace std;

//������
class Date
{
public:
	int year;//��
	int month;//��
	int day;//��
	int Date_Differ(Date BigDay);//�����������
	int Locate_Year();//���ظ������Ǳ���ڼ���
	Date() { year = 0; month = 0; day = 0; }
	int Change_Date(int a, int b, int c);
	Date& operator++(int);//���ڼ�һ
	int Show();//���1
	friend ostream &operator<< (ostream& os, Date & D);//���2
};