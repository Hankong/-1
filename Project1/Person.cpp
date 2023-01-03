#include "Person.h"

int Person::ChangeName(string a)
{
	name = a;
	return 1;
}

int Person::ChangePhone(string a)
{
	phoneNumber = a;
	return 1;
}

int Person::ChangePackage_Num(int a)
{
	Package_Num = a;
	return 1;
}