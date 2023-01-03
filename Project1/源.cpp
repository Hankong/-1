#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<fstream>
#include<time.h>
#include<iomanip>
#include<malloc.h>
#include"Function.h"
using namespace std;

int main()
{
	int i, temp, choice , flag = 1, Package_Statistics[8];
	int flag_choice_package_information = 1;//查询包裹信息循环标志
	int flag_choice_package_statistics = 1;//查询包裹领取、寄回信息循环标志
	int flag_s[501], flag_m[101], flag_b[51];//判断对应编号包裹是否存在
	int package_s_n, package_m_n, package_b_n;//包裹数量
	int today_package[30];//当天新来包裹数量
	int receive_package[30][2];//昨天+今天人员领取包裹数量
	int N[3];//每天随机来的包裹数量
	Person people[30];//社区人员信息
	Package_s* package_s;
	Package_m* package_m;
	Package_b* package_b;
	package_s = new Package_s;
	package_m = new Package_m;
	package_b = new Package_b;
	Date date;//当天日期
	srand(time(0));
	Read_files(people, package_s, package_m, package_b, date, flag_s, flag_m, flag_b, package_s_n, package_m_n, package_b_n, Package_Statistics, today_package, receive_package);
	while (flag == 1)
	{
		choice = Screen();
		switch (choice)
		{
		case 1://1.查询菜鸟包裹信息
			flag_choice_package_information = 1;
			while (flag_choice_package_information == 1)
			{
				switch (Screen_Search_Package())
				{
				case 1:
					flag_choice_package_information = 0;
					Package_s_Rerverse(package_s);
					break;
				case 2:
					flag_choice_package_information = 0;
					Package_m_Rerverse(package_m);
					break;
				case 3:
					flag_choice_package_information = 0;
					Package_b_Rerverse(package_b);
					break;
				case 4:
					flag_choice_package_information = 0;
					break;
				default:
					cout << "请输入正确的数！！\n";
					system("pause");
				}
			}
			system("pause");
			break;
		case 2://2.查询社区人员信息
			Person_Rerverse(people);
			system("pause");
			break;
		case 3://3.查询以往包裹信息
			flag_choice_package_statistics = 1;
			while (flag_choice_package_statistics == 1)
			{
				choice = Screen_Package_Statistics();
				switch ((choice > 9) + (choice > 8) + (choice > 7) + (choice > 0))
				{
				case 0:
					flag_choice_package_statistics = 0;
					cout << "\n\n\n-------------------------------------------\n\n";
					cout << "\t昨天共领取包裹" << Package_Statistics[0] << "件\n";
					cout << people[Max_Receive_Package(receive_package)].GetName() << "领取的包裹最多，领取了" << receive_package[Max_Receive_Package(receive_package)][1] << "件\n";
					cout << "\n-------------------------------------------\n\n\n";
					break;
				case 1:
					flag_choice_package_statistics = 0;
					Print_Package_Statistics_within_Days(Package_Statistics, choice);
					break;
				case 2:
					flag_choice_package_statistics = 0;
					cout << "\n\n\n-------------------------------------------\n\n";
					cout << "\t今日新来包裹" << Sum_Today_Package(today_package) << "件\n";
					cout << people[Max_Today_Package(today_package)].GetName() << "的包裹最多，新来了" << today_package[Max_Today_Package(today_package)] << "件\n";
					cout << "\n-------------------------------------------\n\n\n";
					break;
				case 3:
					flag_choice_package_statistics = 0;
					break;
				default:
					cout << "请输入正确的数！！\n";
					system("pause");
				}
			}
			system("pause");
			break;
		case 4://4.快速单独领取包裹（未开发）
			cout << "暂未开发。\n";
			break;
		case 5://5.迎来美好的明天并更新包裹
			//随机来领取包裹
			Renew_receive_package(receive_package);
			Package_Statistics[0] = 0;
			for (i = 0; i < 30; ++i)
			{
				if (rand() % 2 == 0)
				{
					Receive_Ones_Packages(people, package_s, package_m, package_b, flag_s, flag_m, flag_b, package_s_n, package_m_n, package_b_n, Package_Statistics, today_package, receive_package, i);
				}	
			}
			//更新日期
			Renew_Date(date);
			//寄回超期的包裹
			Delete_Package(people, package_s, package_m, package_b, flag_s, flag_m, flag_b, package_s_n, package_m_n, package_b_n, Package_Statistics, date);
			//随机增加包裹
			Set_0_today_package(today_package);
			N[0] = rand() % ((500 - package_s_n) / 2);
			for (i = 0; i < N[0]; ++i)
			{
				temp = rand() % 30;
				Insert_Package_s(people, package_s, package_s_n, flag_s, date, temp);
				today_package[temp]++;
			}
			N[1] = rand() % ((100 - package_m_n) / 2);
			for (i = 0; i < N[1]; ++i)
			{
				temp = rand() % 30;
				Insert_Package_m(people, package_m, package_m_n, flag_m, date, temp);
				today_package[temp]++;
			}
			N[2] = rand() % ((50 - package_b_n) / 2);
			for (i = 0; i < N[2]; ++i)
			{
				temp = rand() % 30;
				Insert_Package_b(people, package_b, package_b_n, flag_b, date, temp);
				today_package[temp]++;
			}
			Change_today_yesterday_package_file(people, today_package, receive_package);
			break;
		case 6://6.退出程序
			flag = 0;
			break;
		default:
			cout << "请输入正确的数！！\n";
			system("pause");
		}
	}
	return 1;
}