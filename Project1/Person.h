#pragma once
#include<iostream>
#include<string>
using namespace std;

//������Ա��
class Person
{
private:
	string name;//����
	string phoneNumber;//�ֻ���
	int Package_Num;//�������
public:
	string GetName() { return name; }
	string GetPhone() { return phoneNumber; }
	int GetPackage_Num() { return Package_Num; }
	int ChangeName(string a);
	int ChangePhone(string a);
	int ChangePackage_Num(int a);
};
