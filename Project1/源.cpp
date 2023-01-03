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
	int flag_choice_package_information = 1;//��ѯ������Ϣѭ����־
	int flag_choice_package_statistics = 1;//��ѯ������ȡ���Ļ���Ϣѭ����־
	int flag_s[501], flag_m[101], flag_b[51];//�ж϶�Ӧ��Ű����Ƿ����
	int package_s_n, package_m_n, package_b_n;//��������
	int today_package[30];//����������������
	int receive_package[30][2];//����+������Ա��ȡ��������
	int N[3];//ÿ��������İ�������
	Person people[30];//������Ա��Ϣ
	Package_s* package_s;
	Package_m* package_m;
	Package_b* package_b;
	package_s = new Package_s;
	package_m = new Package_m;
	package_b = new Package_b;
	Date date;//��������
	srand(time(0));
	Read_files(people, package_s, package_m, package_b, date, flag_s, flag_m, flag_b, package_s_n, package_m_n, package_b_n, Package_Statistics, today_package, receive_package);
	while (flag == 1)
	{
		choice = Screen();
		switch (choice)
		{
		case 1://1.��ѯ���������Ϣ
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
					cout << "��������ȷ��������\n";
					system("pause");
				}
			}
			system("pause");
			break;
		case 2://2.��ѯ������Ա��Ϣ
			Person_Rerverse(people);
			system("pause");
			break;
		case 3://3.��ѯ����������Ϣ
			flag_choice_package_statistics = 1;
			while (flag_choice_package_statistics == 1)
			{
				choice = Screen_Package_Statistics();
				switch ((choice > 9) + (choice > 8) + (choice > 7) + (choice > 0))
				{
				case 0:
					flag_choice_package_statistics = 0;
					cout << "\n\n\n-------------------------------------------\n\n";
					cout << "\t���칲��ȡ����" << Package_Statistics[0] << "��\n";
					cout << people[Max_Receive_Package(receive_package)].GetName() << "��ȡ�İ�����࣬��ȡ��" << receive_package[Max_Receive_Package(receive_package)][1] << "��\n";
					cout << "\n-------------------------------------------\n\n\n";
					break;
				case 1:
					flag_choice_package_statistics = 0;
					Print_Package_Statistics_within_Days(Package_Statistics, choice);
					break;
				case 2:
					flag_choice_package_statistics = 0;
					cout << "\n\n\n-------------------------------------------\n\n";
					cout << "\t������������" << Sum_Today_Package(today_package) << "��\n";
					cout << people[Max_Today_Package(today_package)].GetName() << "�İ�����࣬������" << today_package[Max_Today_Package(today_package)] << "��\n";
					cout << "\n-------------------------------------------\n\n\n";
					break;
				case 3:
					flag_choice_package_statistics = 0;
					break;
				default:
					cout << "��������ȷ��������\n";
					system("pause");
				}
			}
			system("pause");
			break;
		case 4://4.���ٵ�����ȡ������δ������
			cout << "��δ������\n";
			break;
		case 5://5.ӭ�����õ����첢���°���
			//�������ȡ����
			Renew_receive_package(receive_package);
			Package_Statistics[0] = 0;
			for (i = 0; i < 30; ++i)
			{
				if (rand() % 2 == 0)
				{
					Receive_Ones_Packages(people, package_s, package_m, package_b, flag_s, flag_m, flag_b, package_s_n, package_m_n, package_b_n, Package_Statistics, today_package, receive_package, i);
				}	
			}
			//��������
			Renew_Date(date);
			//�Ļس��ڵİ���
			Delete_Package(people, package_s, package_m, package_b, flag_s, flag_m, flag_b, package_s_n, package_m_n, package_b_n, Package_Statistics, date);
			//������Ӱ���
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
		case 6://6.�˳�����
			flag = 0;
			break;
		default:
			cout << "��������ȷ��������\n";
			system("pause");
		}
	}
	return 1;
}