#include"Date.h"
#include "Person.h"

//С����--500
typedef struct Package_s
{
	int size;
	int number;
	Date date;
	Person person;
	Package_s* next;
	Package_s* pre;
};

//�а���--100
typedef struct Package_m
{
	int size;
	int number;
	Date date;
	Person person;
	Package_m* next;
	Package_m* pre;
};

//�����--50
typedef struct Package_b
{
	int size;
	int number;
	Date date;
	Person person;
	Package_b* next;
	Package_b* pre;
};

//stringת��Ϊint
int Getint(string a)
{
	char s;
	int i = 0, sum = 0;
	while (a[i] != '\0')
	{
		sum = sum * 10 + a[i++] - '0';
	}
	return sum;
}

//��Ļ��ҳ
int Screen()
{
	int i;
	cout << "\n\n\n-------------------------------------------\n\n";
	cout << "\t1.��ѯ���������Ϣ\n";
	cout << "\t2.��ѯ������Ա��Ϣ\n";
	cout << "\t3.��ѯ����������Ϣ\n";
	cout << "\t4.���ٵ�����ȡ������δ������\n";
	cout << "\t5.ӭ�����õ����첢���°���\n";
	cout << "\t6.�˳�����\n";
	cout << "\n-------------------------------------------\n\n\n";
	cout << "������ѡ�";
	cin >> i;
	return i;
}

//��Ļ��ѯ����С���ְ���
int Screen_Search_Package()
{
	int i;
	cout << "\n\n\n-------------------------------------------\n\n";
	cout << "\t1.��С������Ϣ\n";
	cout << "\t2.���а�����Ϣ\n";
	cout << "\t3.��������Ϣ\n";
	cout << "\t4.������һ��\n";
	cout << "\n-------------------------------------------\n\n\n";
	cout << "������ѡ�";
	cin >> i;
	return i;
}

//��Ļ���ա�һ�ܼĻذ���ͳ��
int Screen_Package_Statistics()
{
	int i;
	cout << "\n\n\n-------------------------------------------\n\n";
	cout << "\t0.��ѯ������ȡ��������\n";
	cout << "\t1~7.��ѯn���ڼĻصİ�������\n";
	cout << "\t8.��ѯ����������������\n";
	cout << "\t9.������һ��\n";
	cout << "\n-------------------------------------------\n\n\n";
	cout << "������ѡ�";
	cin >> i;
	return i;
}

//��ʾn���ڱ��Ļصİ���
int Print_Package_Statistics_within_Days(int Package_Statistics[8], int n)
{
	int i, sum = 0;
	for (i = 1; i <= n; ++i)
	{
		sum += Package_Statistics[i];
	}
	cout << "\n\n\n-------------------------------------------\n\n";
	cout << "\t" << n <<"���ڱ��Ļصİ�����" << sum << "��\n";
	cout << "\n-------------------------------------------\n\n\n";
	return 1;
}

//�ַ����ָ�
void Stringsplit(const string& str, const char split, vector<string>& res)
{
	if (str == "")        return;
	//���ַ���ĩβҲ����ָ����������ȡ���һ��
	string strs = str + split;
	size_t pos = strs.find(split);

	// ���Ҳ����������ַ��������������� npos
	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//ȥ���ѷָ���ַ���,��ʣ�µ��ַ����н��зָ�
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(split);
	}
}

//flag�жϼ����Ƿ�Ϊ��_����
int Set_0(int flag_s[501], int flag_m[101], int  flag_b[51])
{
	int i;
	for (i = 0; i < 501; ++i)
	{
		flag_s[i] = 0;
	}
	for (i = 0; i < 101; ++i)
	{
		flag_m[i] = 0;
	}
	for (i = 0; i < 51; ++i)
	{
		flag_b[i] = 0;
	}
	return 1;
}

//ÿ��������������
int Set_0_today_package(int today_package[30])
{
	int i;
	for (i = 0; i < 30; ++i)
	{
		today_package[i] = 0;
	}
	return 1;
}

//ÿ�ո�����ȡ������Ϣ
int Renew_receive_package(int receive_package[30][2])
{
	int i;
	for (i = 0; i < 30; ++i)
	{
		receive_package[i][1] = receive_package[i][0];
		receive_package[i][0] = 0;
	}
	return 1;
}

//��ȡ�ļ�
int Read_files(Person people[30], Package_s*& package_s, Package_m*& package_m, Package_b*& package_b, Date& date, int flag_s[501], int flag_m[101], int flag_b[51], int& package_s_n, int& package_m_n, int& package_b_n, int Package_Statistics[8], int today_package[30], int receive_package[30][2])
{
	//��ȡ������Ա
	fstream file1;
	string temp;
	vector<string> res, res1;
	int i = 0;
	file1.open("person.txt", ios::in);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	while (getline(file1, temp))
	{
		Stringsplit(temp, ',', res);
		people[i].ChangeName(res[0]);
		people[i].ChangePhone(res[1]);
		people[i++].ChangePackage_Num(Getint(res[2]));
		res.clear();
	}
	file1.close();
	//��ȡ����
	file1.open("date.txt", ios::in);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	getline(file1, temp);
	date.year = Getint(temp);
	getline(file1, temp);
	date.month = Getint(temp);
	getline(file1, temp);
	date.day = Getint(temp);
	file1.close();
	//��ȡ���ְ���
	Package_s* p1,* q1;
	Package_m* p2,* q2;
	Package_b* p3,* q3;
	int n1 = 0, n2 = 0, n3 = 0;
	q1 = package_s;
	q2 = package_m;
	q3 = package_b;
	package_s->pre = NULL;
	package_s->next = NULL;
	package_m->pre = NULL;
	package_m->next = NULL;
	package_b->pre = NULL;
	package_b->next = NULL;
	Set_0(flag_s, flag_m, flag_b); //flag�жϼ����Ƿ�Ϊ��_����
	//С����
	file1.open("package_s.txt", ios::in);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	while (getline(file1, temp))
	{
		p1 = new Package_s;
		p1->size = 1;
		p1->next = NULL;
		Stringsplit(temp, ':', res);
		p1->size = Getint(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, '-', res);
		p1->number = Getint(res[1]);
		flag_s[Getint(res[1])] = 1;
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		p1->person.ChangeName(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		p1->person.ChangePhone(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		Stringsplit(res[1], '-', res1);
		p1->date.Change_Date(Getint(res1[0]), Getint(res1[1]), Getint(res1[2]));
		q1->next = p1;
		p1->pre = q1;
		q1 = p1;
		res.clear();
		res1.clear();
		n1++;
	}
	package_s_n = n1;
	file1.close();
	//�а���
	file1.open("package_m.txt", ios::in);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	while (getline(file1, temp))
	{
		p2 = new Package_m;
		p2->size = 2;
		p2->next = NULL;
		Stringsplit(temp, ':', res);
		p2->size = Getint(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, '-', res);
		p2->number = Getint(res[1]);
		flag_m[Getint(res[1])] = 1;
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		p2->person.ChangeName(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		p2->person.ChangePhone(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		Stringsplit(res[1], '-', res1);
		p2->date.Change_Date(Getint(res1[0]), Getint(res1[1]), Getint(res1[2]));
		q2->next = p2;
		p2->pre = q2;
		q2 = p2;
		res.clear();
		res1.clear();
		n2++;
	}
	package_m_n = n2;
	file1.close();
	//�����
	file1.open("package_b.txt", ios::in);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	while (getline(file1, temp))
	{
		p3 = new Package_b;
		p3->size = 3;
		p3->next = NULL;
		Stringsplit(temp, ':', res);
		p3->size = Getint(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, '-', res);
		p3->number = Getint(res[1]);
		flag_b[Getint(res[1])] = 1;
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		p3->person.ChangeName(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		p3->person.ChangePhone(res[1]);
		res.clear();
		getline(file1, temp);
		Stringsplit(temp, ':', res);
		Stringsplit(res[1], '-', res1);
		p3->date.Change_Date(Getint(res1[0]), Getint(res1[1]), Getint(res1[2]));
		q3->next = p3;
		p3->pre = q3;
		q3 = p3;
		res.clear();
		res1.clear();
		n3++;
	}
	package_b_n = n3;
	file1.close();
	//������ȡ��Ļذ�����Ϣ
	file1.open("package_statistics.txt", ios::in);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	i = 0;
	while (getline(file1, temp))
	{
		Stringsplit(temp, ':', res);
		Package_Statistics[i++] = Getint(res[1]);
		res.clear();
	}
	file1.close();
	//today_yesterday_package��Ϣ
	file1.open("today_yesterday_package.txt", ios::in);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	i = 0;
	while (getline(file1, temp))
	{
		Stringsplit(temp, ',', res);
		today_package[i] = Getint(res[2]);
		receive_package[i][0] = Getint(res[4]);
		receive_package[i++][1] = Getint(res[6]);
		res.clear();
	}
	file1.close();
	return 1;
}

//����������λ�±�
int Locate_person_n(Person people[30], string a)
{
	int i, n = -1;
	for (i = 0; i < 30; ++i)
	{
		if (a == people[i].GetName())
		{
			n = i;
			break;
		}
	}
	return n;
}

//��ʾ����person
int Person_Rerverse(Person people[30])
{
	int i, outputcounter = 0;
	for (i = 0; i < 30; ++i)
	{
		cout << "������" << people[i].GetName() << "\n";
		cout << "�ֻ��ţ�" << people[i].GetPhone() << "\n";
		cout << "���������" << people[i].GetPackage_Num() << "\n\n";
		if (++outputcounter % 5 == 0)									//20�鰴�س����� 
		{
			system("pause");
		}
	}
	return 1;
}

//��ʾpackage_s
int Package_s_Rerverse(Package_s* package_s)
{
	int outputcounter = 0;
	Package_s* p;
	p = package_s->next;
	while (p)
	{
		cout << "\n\n\n-------------------------------------------\n\n";
		cout << "\t������С ��" << p->size << endl;
		cout << "\t������� : 1 - " << setw(3) << setfill('0') << p->number << endl;
		cout << "\tȡ�������� : " << p->person.GetName() << endl;
		cout << "\tȡ�����ֻ��� : " << p->person.GetPhone() << endl;
		cout << "\t�������� : ";
		p->date.Show();
		cout << "\n\n-------------------------------------------\n\n\n";
		p = p->next;
		if (++outputcounter % 20 == 0)									//20�鰴�س����� 
		{
			system("pause");
		}
	}
	return 1;
}

//��ʾpackage_m
int Package_m_Rerverse(Package_m* package_m)
{
	int outputcounter = 0;
	Package_m* p;
	p = package_m->next;
	while (p)
	{
		cout << "\n\n\n-------------------------------------------\n\n";
		cout << "\t������С ��" << p->size << endl;
		cout << "\t������� : 2 - " << setw(3) << setfill('0') << p->number << endl;
		cout << "\tȡ�������� : " << p->person.GetName() << endl;
		cout << "\tȡ�����ֻ��� : " << p->person.GetPhone() << endl;
		cout << "\t�������� : ";
		p->date.Show();
		cout << "\n\n-------------------------------------------\n\n\n";
		p = p->next;
		if (++outputcounter % 20 == 0)									//20�鰴�س����� 
		{
			system("pause");
		}
	}
	return 1;
}

//��ʾpackage_b
int Package_b_Rerverse(Package_b* package_b)
{
	int outputcounter = 0;
	Package_b* p;
	p = package_b->next;
	while (p)
	{
		cout << "\n\n\n-------------------------------------------\n\n";
		cout << "\t������С ��" << p->size << endl;
		cout << "\t������� : 3 - " << setw(3) << setfill('0') << p->number << endl;
		cout << "\tȡ�������� : " << p->person.GetName() << endl;
		cout << "\tȡ�����ֻ��� : " << p->person.GetPhone() << endl;
		cout << "\t�������� : ";
		p->date.Show();
		cout << "\n\n-------------------------------------------\n\n\n";
		p = p->next;
		if (++outputcounter % 20 == 0)									//20�鰴�س����� 
		{
			system("pause");
		}
	}
	return 1;
}

//����date�����޸�date.txt�ļ�
int Renew_Date(Date& date)
{
	date++;
	fstream file1;
	file1.open("date.txt", ios::out);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	file1 << date.year << endl;
	file1 << date.month << endl;
	file1 << date.day;
	file1.close();
	return 1;
}

//�޸�package_s.txt
int Change_package_s_file(Package_s*& package_s)
{
	fstream file1;
	Package_s* q;
	file1.open("package_s.txt", ios::out);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	q = package_s->next;
	while (q->next)
	{
		file1 << "������С:1\n";
		file1 << "�������:1-" << setw(3) << setfill('0') << q->number << endl;
		file1 << "ȡ��������:" << q->person.GetName() << endl;
		file1 << "ȡ�����ֻ���:" << q->person.GetPhone() << endl;
		file1 << "��������:" << q->date.year << "-" << q->date.month << "-" << q->date.day << endl;
		q = q->next;
	}
	file1 << "������С:1\n";
	file1 << "�������:1-" << setw(3) << setfill('0') << q->number << endl;
	file1 << "ȡ��������:" << q->person.GetName() << endl;
	file1 << "ȡ�����ֻ���:" << q->person.GetPhone() << endl;
	file1 << "��������:" << q->date.year << "-" << q->date.month << "-" << q->date.day;
	file1.close();
	return 1;
}

//�޸�package_m.txt
int Change_package_m_file(Package_m*& package_m)
{
	fstream file1;
	Package_m* q;
	file1.open("package_m.txt", ios::out);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	q = package_m->next;
	while (q->next)
	{
		file1 << "������С:2\n";
		file1 << "�������:2-" << setw(3) << setfill('0') << q->number << endl;
		file1 << "ȡ��������:" << q->person.GetName() << endl;
		file1 << "ȡ�����ֻ���:" << q->person.GetPhone() << endl;
		file1 << "��������:" << q->date.year << "-" << q->date.month << "-" << q->date.day << endl;
		q = q->next;
	}
	file1 << "������С:2\n";
	file1 << "�������:2-" << setw(3) << setfill('0') << q->number << endl;
	file1 << "ȡ��������:" << q->person.GetName() << endl;
	file1 << "ȡ�����ֻ���:" << q->person.GetPhone() << endl;
	file1 << "��������:" << q->date.year << "-" << q->date.month << "-" << q->date.day;
	file1.close();
	return 1;
}

//�޸�package_b.txt
int Change_package_b_file(Package_b*& package_b)
{
	fstream file1;
	Package_b* q;
	file1.open("package_b.txt", ios::out);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	q = package_b->next;
	while (q->next)
	{
		file1 << "������С:3\n";
		file1 << "�������:3-" << setw(3) << setfill('0') << q->number << endl;
		file1 << "ȡ��������:" << q->person.GetName() << endl;
		file1 << "ȡ�����ֻ���:" << q->person.GetPhone() << endl;
		file1 << "��������:" << q->date.year << "-" << q->date.month << "-" << q->date.day << endl;
		q = q->next;
	}
	file1 << "������С:3\n";
	file1 << "�������:3-" << setw(3) << setfill('0') << q->number << endl;
	file1 << "ȡ��������:" << q->person.GetName() << endl;
	file1 << "ȡ�����ֻ���:" << q->person.GetPhone() << endl;
	file1 << "��������:" << q->date.year << "-" << q->date.month << "-" << q->date.day;
	file1.close();
	return 1;
}

//�޸�person.txt
int Change_person_file(Person people[30])
{
	int i;
	fstream file1;
	file1.open("person.txt", ios::out);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	for (i = 0; i < 29; ++i)
	{
		file1 << people[i].GetName() << "," << people[i].GetPhone() << "," << people[i].GetPackage_Num() << endl;
	}
	file1 << people[i].GetName() << "," << people[i].GetPhone() << "," << people[i].GetPackage_Num();
	file1.close();
	return 1;
}

//�޸�package_statistics.txt
int Change_package_statistics_file(int Package_Statistics[8])
{
	int i;
	fstream file1;
	file1.open("package_statistics.txt", ios::out);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	file1 << "������ȡ��������:" << Package_Statistics[0] << endl;
	for (i = 1; i < 7; ++i)
	{
		file1 << i << "��ǰ�����İ�����:" << Package_Statistics[i] << endl;
	}
	file1 << i << "��ǰ�����İ�����:" << Package_Statistics[i];
	file1.close();
	return 1;
}

//�޸�today_yesterday_package.txt�ļ�
int Change_today_yesterday_package_file(Person people[30], int today_package[30], int receive_package[30][2])
{
	int i;
	fstream file1;
	file1.open("today_yesterday_package.txt", ios::out);
	if (!file1)
	{
		cout << "�ļ���ʧ��";
		return 1;
	}
	for (i = 0; i < 29; ++i)
	{
		file1 << people[i].GetName();
		file1 << ",����������������," << today_package[i];
		file1 << ",������ȡ��������," << receive_package[i][0];
		file1 << ",������ȡ��������," << receive_package[i][1] << endl;
	}
	file1 << people[i].GetName();
	file1 << ",����������������," << today_package[i];
	file1 << ",������ȡ��������," << receive_package[i][0];
	file1 << ",������ȡ��������," << receive_package[i][1];
	file1.close();
}

//����һ��package_s�����޸�package_s.txt��person.txt�ļ�
int Insert_Package_s(Person people[30], Package_s*& package_s, int& package_s_n, int flag_s[501], Date date, int random_person_n)
{
	package_s_n++;
	int package_n;//���
	Package_s* p,* q,*s;//s < p < q
	q = package_s->next;
	p = new Package_s;
	p->size = 1;
	p->pre = NULL;
	p->next = NULL;
	int i;
	for (i = 1; flag_s[i] == 1; ++i);
	package_n = i;
	p->number = i;
	flag_s[i] = 1;
	p->date.Change_Date(date.year, date.month, date.day);
	people[random_person_n].ChangePackage_Num(people[random_person_n].GetPackage_Num() + 1);
	p->person.ChangeName(people[random_person_n].GetName());
	p->person.ChangePhone(people[random_person_n].GetPhone());
	p->person.ChangePackage_Num(people[random_person_n].GetPackage_Num());
	//q������
	if (!q)
	{
		package_s->next = p;
		p->pre = package_s;
		return 1;
	}
	s = package_s;
	while (q)
	{
		if (q->number > p->number)
		{
			s->next = p;
			q->pre = p;
			p->next = q;
			p->pre = s;
			break;
		}
		q = q->next;
		s = s->next;
	}
	if (!q)
	{
		s->next = p;
		p->pre = s;
	}
	//дperson.txt�ļ�
	Change_person_file(people);
	//дpackage_s.txt�ļ�
	Change_package_s_file(package_s);
	return 1;
}

//����һ��package_m�����޸�package_m.txt��person.txt�ļ�
int Insert_Package_m(Person people[30], Package_m*& package_m, int& package_m_n, int flag_m[101], Date date, int random_person_n)
{
	package_m_n++;
	int package_n;//���
	Package_m* p, * q, * s;//s < p < q
	q = package_m->next;
	p = new Package_m;
	p->size = 2;
	p->pre = NULL;
	p->next = NULL;
	int i;
	for (i = 1; flag_m[i] == 1; ++i);
	package_n = i;
	p->number = i;
	flag_m[i] = 1;
	p->date.Change_Date(date.year, date.month, date.day);
	people[random_person_n].ChangePackage_Num(people[random_person_n].GetPackage_Num() + 1);
	p->person.ChangeName(people[random_person_n].GetName());
	p->person.ChangePhone(people[random_person_n].GetPhone());
	p->person.ChangePackage_Num(people[random_person_n].GetPackage_Num());
	//q������
	if (!q)
	{
		package_m->next = p;
		p->pre = package_m;
		return 1;
	}
	s = package_m;
	while (q)
	{
		if (q->number > p->number)
		{
			s->next = p;
			q->pre = p;
			p->next = q;
			p->pre = s;
			break;
		}
		q = q->next;
		s = s->next;
	}
	if (!q)
	{
		s->next = p;
		p->pre = s;
	}
	//дperson.txt�ļ�
	Change_person_file(people);
	//дpackage_m.txt�ļ�
	Change_package_m_file(package_m);
	return 1;
}

//����һ��package_b�����޸�package_b.txt��person.txt�ļ�
int Insert_Package_b(Person people[30], Package_b*& package_b, int& package_b_n, int flag_b[51], Date date, int random_person_n)
{
	package_b_n++;
	int package_n;//���
	Package_b* p, * q, * s;//s < p < q
	q = package_b->next;
	p = new Package_b;
	p->size = 3;
	p->pre = NULL;
	p->next = NULL;
	int i;
	for (i = 1; flag_b[i] == 1; ++i);
	package_n = i;
	p->number = i;
	flag_b[i] = 1;
	p->date.Change_Date(date.year, date.month, date.day);
	people[random_person_n].ChangePackage_Num(people[random_person_n].GetPackage_Num() + 1);
	p->person.ChangeName(people[random_person_n].GetName());
	p->person.ChangePhone(people[random_person_n].GetPhone());
	p->person.ChangePackage_Num(people[random_person_n].GetPackage_Num());
	//q������
	if (!q)
	{
		package_b->next = p;
		p->pre = package_b;
		return 1;
	}
	s = package_b;
	while (q)
	{
		if (q->number > p->number)
		{
			s->next = p;
			q->pre = p;
			p->next = q;
			p->pre = s;
			break;
		}
		q = q->next;
		s = s->next;
	}
	if (!q)
	{
		s->next = p;
		p->pre = s;
	}
	//дperson.txt�ļ�
	Change_person_file(people);
	//дpackage_s.txt�ļ�
	Change_package_b_file(package_b);
	return 1;
}

//��ȡĳ������Ա�����а��������޸����������ļ���person.txt�ļ���package_statistics.txt�ļ���today_yesterday_package.txt�ļ�
int Receive_Ones_Packages(Person people[30], Package_s*& package_s, Package_m*& package_m, Package_b*& package_b, int flag_s[501], int flag_m[101], int flag_b[51], int& package_s_n, int& package_m_n, int& package_b_n, int Package_Statistics[8], int today_package[30], int receive_package[30][2], int random_n)
{
	//��С�������޸�С�����ļ�
	Package_s* p1, * q1, * s1;//q1 > p1 > s1
	p1 = package_s->next;
	if (!p1) return 1;
	q1 = package_s;
	s1 = p1->next;
	while (p1)
	{
		if (p1->person.GetName() == people[random_n].GetName())
		{
			people[random_n].ChangePackage_Num(people[random_n].GetPackage_Num() - 1);//���˰���--
			flag_s[p1->number] = 0;//������0
			package_s_n--;//��������--
			Package_Statistics[0]++;//��ȡ������++
			receive_package[random_n][1]++;//������ȡ����++
			q1->next = s1;
			if (s1)
			{
				s1->pre = p1;
				delete p1;
				p1 = q1->next;
				if (p1) { s1 = p1->next; }
			}
			else
			{
				delete p1;
				p1 = q1->next;
			}
		}
		else
		{
			p1 = p1->next;
			q1 = q1->next;
			if (!s1) { s1 = NULL; }
			else { s1 = s1->next; }
		}
	}
	Change_package_s_file(package_s);
	//���а������޸��а����ļ�
	Package_m* p2, * q2, * s2;//q2 > p2 > s2
	p2 = package_m->next;
	if (!p2) return 1;
	q2 = package_m;
	s2 = p2->next;
	while (p2)
	{
		if (p2->person.GetName() == people[random_n].GetName())
		{
			people[random_n].ChangePackage_Num(people[random_n].GetPackage_Num() - 1);//���˰���--
			flag_m[p2->number] = 0;//������0
			package_m_n--;//��������--
			Package_Statistics[0]++;//��ȡ������++
			receive_package[random_n][1]++;//������ȡ����++
			q2->next = s2;
			if (s2)
			{
				s2->pre = p2;
				delete p2;
				p2 = q2->next;
				if (p2) { s2 = p2->next; }
			}
			else
			{
				delete p2;
				p2 = q2->next;
			}
		}
		else
		{
			p2 = p2->next;
			q2 = q2->next;
			if (!s2) { s2 = NULL; }
			else { s2 = s2->next; }
		}
	}
	Change_package_m_file(package_m);
	//���������޸Ĵ�����ļ�
	Package_b* p3, * q3, * s3;//q3 > p3 > s3
	p3 = package_b->next;
	if (!p3) return 1;
	q3 = package_b;
	s3 = p3->next;
	while (p3)
	{
		if (p3->person.GetName() == people[random_n].GetName())
		{
			people[random_n].ChangePackage_Num(people[random_n].GetPackage_Num() - 1);//���˰���--
			flag_b[p3->number] = 0;//������0
			package_b_n--;//��������--
			Package_Statistics[0]++;//��ȡ������++
			receive_package[random_n][1]++;//������ȡ����++
			q3->next = s3;
			if (s3)
			{
				s3->pre = p3;
				delete p3;
				p3 = q3->next;
				if (p3) { s3 = p3->next; }
			}
			else
			{
				delete p3;
				p3 = q3->next;
			}
		}
		else
		{
			p3 = p3->next;
			q3 = q3->next;
			if (!s3) { s3 = NULL; }
			else { s3 = s3->next; }
		}
	}
	Change_package_b_file(package_b);
	//�ļ��޸�
	Change_person_file(people);
	Change_package_statistics_file(Package_Statistics);
	Change_today_yesterday_package_file(people, today_package, receive_package);
	return 1;
}

//�Ļس�ʱ�Ŀ�ݣ����޸����������ļ���person.txt�ļ���package_statistics.txt�ļ�
int Delete_Package(Person people[30], Package_s*& package_s, Package_m*& package_m, Package_b*& package_b, int flag_s[501], int flag_m[101], int flag_b[51], int& package_s_n, int& package_m_n, int& package_b_n, int Package_Statistics[8], Date date)
{
	int i, person_n;
	for (i = 7; i > 1; --i)
	{
		Package_Statistics[i] = Package_Statistics[i - 1];
	}
	Package_Statistics[1] = 0;
	//�Ļ�С�������޸�С�����ļ�
	Package_s* p1, * q1, * s1;//q1 > p1 > s1
	p1 = package_s->next;
	if (!p1) return 1;
	q1 = package_s;
	s1 = p1->next;
	while (p1)
	{
		if (p1->date.Date_Differ(date) > 2)
		{
			person_n = Locate_person_n(people, p1->person.GetName());
			people[person_n].ChangePackage_Num(people[person_n].GetPackage_Num() - 1);//���˰���--
			flag_s[p1->number] = 0;//������0
			package_s_n--;//��������--
			Package_Statistics[1]++;
			q1->next = s1;
			if (s1)
			{
				s1->pre = p1;
				delete p1;
				p1 = q1->next;
				if (p1) { s1 = p1->next; }
			}
			else
			{
				delete p1;
				p1 = q1->next;
			}
		}
		else
		{
			p1 = p1->next;
			q1 = q1->next;
			if (!s1) { s1 = NULL; }
			else { s1 = s1->next; }
		}
	}
	Change_package_s_file(package_s);
	//���а������޸��а����ļ�
	Package_m* p2, * q2, * s2;//q2 > p2 > s2
	p2 = package_m->next;
	if (!p2) return 1;
	q2 = package_m;
	s2 = p2->next;
	while (p2)
	{
		if (p2->date.Date_Differ(date) > 2)
		{
			person_n = Locate_person_n(people, p2->person.GetName());
			people[person_n].ChangePackage_Num(people[person_n].GetPackage_Num() - 1);//���˰���--
			flag_m[p2->number] = 0;//������0
			package_m_n--;//��������--
			Package_Statistics[1]++;
			q2->next = s2;
			if (s2)
			{
				s2->pre = p2;
				delete p2;
				p2 = q2->next;
				if (p2) { s2 = p2->next; }
			}
			else
			{
				delete p2;
				p2 = q2->next;
			}
		}
		else
		{
			p2 = p2->next;
			q2 = q2->next;
			if (!s2) { s2 = NULL; }
			else { s2 = s2->next; }
		}
	}
	Change_package_m_file(package_m);
	//���������޸Ĵ�����ļ�
	Package_b* p3, * q3, * s3;//q3 > p3 > s3
	p3 = package_b->next;
	if (!p3) return 1;
	q3 = package_b;
	s3 = p3->next;
	while (p3)
	{
		if (p3->date.Date_Differ(date) > 2)
		{
			person_n = Locate_person_n(people, p3->person.GetName());
			people[person_n].ChangePackage_Num(people[person_n].GetPackage_Num() - 1);//���˰���--
			flag_b[p3->number] = 0;//������0
			package_b_n--;//��������--
			Package_Statistics[1]++;
			q3->next = s3;
			if (s3)
			{
				s3->pre = p3;
				delete p3;
				p3 = q3->next;
				if (p3) { s3 = p3->next; }
			}
			else
			{
				delete p3;
				p3 = q3->next;
			}
		}
		else
		{
			p3 = p3->next;
			q3 = q3->next;
			if (!s3) { s3 = NULL; }
			else { s3 = s3->next; }
		}
	}
	Change_package_b_file(package_b);
	//�ļ��޸�
	Change_person_file(people);
	Change_package_statistics_file(Package_Statistics);
	return 1;
}

//ͳ�ƽ���������������
int Sum_Today_Package(int today_package[30])
{
	int i, sum = 0;
	for (i = 0; i < 30; ++i)
	{
		sum += today_package[i];
	}
	return sum;
}

//�����������������ˣ������±�
int Max_Today_Package(int today_package[30])
{
	int i, temp = 0, max = 0;
	for (i = 0; i < 30; ++i)
	{
		if (today_package[i] > max)
		{
			max = today_package[i];
			temp = i;
		}
	}
	return temp;
}

//������ȡ���������ˣ������±�
int Max_Receive_Package(int receive_package[30][2])
{
	int i, temp = 0, max = 0;
	for (i = 0; i < 30; ++i)
	{
		if (receive_package[i][1] > max)
		{
			max = receive_package[i][1];
			temp = i;
		}
	}
	return temp;
}