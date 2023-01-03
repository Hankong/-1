#pragma once
#include<iostream>
#include<string>
using namespace std;

//社区人员类
class Person
{
private:
	string name;//姓名
	string phoneNumber;//手机号
	int Package_Num;//快递数量
public:
	string GetName() { return name; }
	string GetPhone() { return phoneNumber; }
	int GetPackage_Num() { return Package_Num; }
	int ChangeName(string a);
	int ChangePhone(string a);
	int ChangePackage_Num(int a);
};
