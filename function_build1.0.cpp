##include"head1.0.h"
#include<iostream>
#include<string>
#include<iomanip>


Admin::Admin()
{
	char the_store_list_filename[] = ".\\All_File\\Admin\\���.txt";
	char the_store_sold_filename[] = ".\\All_File\\Admin\\�����嵥.txt";
	char pass_check_filename[] = ".\\All_File\\Admin\\����Ա�˺�.txt";
	admin_name = "NULL";
	admin_password = "NULL";//��ʵ��������ĸ�ֵ�����վͻ�ı�
	the_store_list_file = the_store_list_filename;
	the_store_sold_file = the_store_sold_filename;
	pass_check_file = pass_check_filename;//�������Ƕ����ļ�·���İ���
}

Admin::~Admin()
{
	//std::cout << "clear" << std::endl;
}

bool Admin::Pass_Check()
{
	std::string name_input;
	std::string password_input;
	char name_in_file[THE_STR_LEN + 1];
	char password_in_file[THE_STR_LEN + 1];
	FILE *the_check_file;

	if (fopen_s(&the_check_file, pass_check_file.c_str(), "r"))
	{
		std::cout << "�޷���ָ���Ĺ���Ա�ļ������������ļ����á�" << std::endl;
		return false;
	}
	else
	{
		fscanf_s(the_check_file, "%s", name_in_file, THE_STR_LEN + 1);
		fscanf_s(the_check_file, "%s", password_in_file, THE_STR_LEN + 1);//���ļ���ͷ������������
		std::cout << "�������Ա�˺ţ�";
		std::cin >> name_input;//��δ����������Ƚϳ�֮����α���
		std::cout << "�������Ա���룺";
		std::cin >> password_input;

		while (!feof(the_check_file))
		{
			fscanf_s(the_check_file, "%s", name_in_file, THE_STR_LEN + 1);
			fscanf_s(the_check_file, "%s", password_in_file, THE_STR_LEN + 1);
			if (strcmp(name_in_file, name_input.c_str()) == 0)
			{
				if (strcmp(password_in_file, password_input.c_str()) == 0)
				{
					admin_name = name_input;//������Ա��¼��
					admin_password = password_input;
					fclose(the_check_file);
					std::cout << "��¼�ɹ���" << std::endl;
					return true;
				}
			}
		}
	}
	fclose(the_check_file);
	std::cout << "��½ʧ�ܣ��������Ĺ���ԱID�����롣" << std::endl;
	return false;
}

//�����޸ģ��Ѷ�ȡ��ѭ�����ͺ󣬷�ֹ���һ�����ݵĶ���ظ���ȡ��������
void Admin::Init_The_Store_List()
{
	FILE *the_list_file;//�ļ���
	char get1[THE_STR_LEN + 1], get2[THE_STR_LEN + 1], get3[THE_STR_LEN + 1];
	double get4;
	int get5;

	if (fopen_s(&the_list_file, the_store_list_file.c_str(), "r"))
	{
		std::cout << "�޷���ָ���Ĳֿ��ļ������������ļ����á�" << std::endl;
		exit(-1);
	}
	else
	{
		for (int i = 0; i < 5; i++)
			fscanf_s(the_list_file, "%s", get1, THE_STR_LEN + 1);
		int i = 0;
		fscanf_s(the_list_file, "%s%s%s%lf%d", get1, THE_STR_LEN + 1, get2, THE_STR_LEN + 1, get3, THE_STR_LEN + 1, &get4, &get5);
		while (!feof(the_list_file))
		{
			store_list[i].ID = get1;
			store_list[i].name = get2;
			store_list[i].brand = get3;
			store_list[i].price = get4;
			store_list[i].num = get5;
			i++;
			fscanf_s(the_list_file, "%s%s%s%lf%d", get1, THE_STR_LEN + 1, get2, THE_STR_LEN + 1, get3, THE_STR_LEN + 1, &get4, &get5);
		}
	}

	fclose(the_list_file);
	return;
}

void Admin::Print_List()
{
	std::cout.setf(std::ios::left);//�����
	std::cout << std::setw(THE_TAB) << "ID" << std::setw(THE_TAB) << "����"
		<< std::setw(THE_TAB) << "Ʒ��" << std::setw(THE_TAB) << "�۸�"
		<< std::setw(THE_TAB) << "����" << std::endl;
	for (int i = 0; store_list[i].name != "NULL"; i++)
		std::cout << std::setw(THE_TAB) << store_list[i].ID << std::setw(THE_TAB) << store_list[i].name
		<< std::setw(THE_TAB) << store_list[i].brand << std::setw(THE_TAB) << store_list[i].price
		<< std::setw(THE_TAB) << store_list[i].num << std::endl;
	return;
}

void Admin::Add_List()
{
	std::string name, brand;
	double price;
	int num;
	std::cout << "��������Ʒ�����ƣ�";
	std::cin >> name;
	std::cout << "��������Ʒ��Ʒ�ƣ�";
	std::cin >> brand;
	std::cout << "��������Ʒ�ļ۸�";
	std::cin >> price;
	std::cout << "��������Ʒ��������";
	std::cin >> num;

	int i = 0;
	for (; store_list[i].ID != "NULL"; i++)
	{
		if (store_list[i].name == name && store_list[i].brand == brand && store_list[i].price == price)
		{
			store_list[i].num += num;
			std::cout << "����Ʒ�Ѿ������ڿ�棬�������޸�Ϊ" << store_list[i].num << std::endl;
			this->Write_List_File();
			return;
		}
	}
	//������û�и���Ʒ��������
	int n = 0;
	char add[10];
	n = atoi(&(store_list[i - 1].ID[1]));
	n++;
	if (n > 999)
		sprintf_s(add, 10, "F%d", n);
	else if (n > 99)
		sprintf_s(add, 10, "F0%d", n);
	else if (n > 9)
		sprintf_s(add, 10, "F00%d", n);
	else
		sprintf_s(add, 10, "F000%d", n);

	store_list[i].ID = add;
	store_list[i].name = name;
	store_list[i].brand = brand;
	store_list[i].price = price;
	store_list[i].num = num;
	std::cout << "�������½�����Ʒ��" << std::endl;
	std::cout << "ID��" << store_list[i].ID << "  ���ƣ�" << store_list[i].name << "  Ʒ�ƣ�"
		<< store_list[i].brand << "  �۸�" << store_list[i].price << "  ������" << store_list[i].num << std::endl;
	this->Write_List_File();
	return;
}

void Admin::Write_List_File()
{
	FILE *list_file;
	if (fopen_s(&list_file, the_store_list_file.c_str(), "w"))
	{
		std::cout << "��������ļ����ã�" << std::endl;
		exit(-1);
	}
	else
	{
		fprintf_s(list_file, "%-16s%-16s%-16s%-16s%-16s", "ID", "����", "Ʒ��", "�۸�", "����");
		for (int i = 0; store_list[i].ID != "NULL"; i++)
		{
			fprintf_s(list_file, "\n%-16s%-16s%-16s%-16.1f%-16d", store_list[i].ID.c_str(), store_list[i].name.c_str(), store_list[i].brand.c_str(), store_list[i].price, store_list[i].num);
		}
	}
	fclose(list_file);
	std::cout << "����ļ�д���곡��" << std::endl;
	return;
}