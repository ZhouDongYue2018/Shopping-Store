##include"head1.0.h"
#include<iostream>
#include<string>
#include<iomanip>


Admin::Admin()
{
	char the_store_list_filename[] = ".\\All_File\\Admin\\库存.txt";
	char the_store_sold_filename[] = ".\\All_File\\Admin\\已售清单.txt";
	char pass_check_filename[] = ".\\All_File\\Admin\\管理员账号.txt";
	admin_name = "NULL";
	admin_password = "NULL";//其实是无意义的赋值，最终就会改变
	the_store_list_file = the_store_list_filename;
	the_store_sold_file = the_store_sold_filename;
	pass_check_file = pass_check_filename;//这三个是对于文件路径的把握
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
		std::cout << "无法打开指定的管理员文件，请检查您的文件配置。" << std::endl;
		return false;
	}
	else
	{
		fscanf_s(the_check_file, "%s", name_in_file, THE_STR_LEN + 1);
		fscanf_s(the_check_file, "%s", password_in_file, THE_STR_LEN + 1);//将文件的头读出，不在列
		std::cout << "输入管理员账号：";
		std::cin >> name_input;//暂未考虑输出长度较长之后如何报错
		std::cout << "输入管理员密码：";
		std::cin >> password_input;

		while (!feof(the_check_file))
		{
			fscanf_s(the_check_file, "%s", name_in_file, THE_STR_LEN + 1);
			fscanf_s(the_check_file, "%s", password_in_file, THE_STR_LEN + 1);
			if (strcmp(name_in_file, name_input.c_str()) == 0)
			{
				if (strcmp(password_in_file, password_input.c_str()) == 0)
				{
					admin_name = name_input;//将管理员名录入
					admin_password = password_input;
					fclose(the_check_file);
					std::cout << "登录成功！" << std::endl;
					return true;
				}
			}
		}
	}
	fclose(the_check_file);
	std::cout << "登陆失败，请检查您的管理员ID和密码。" << std::endl;
	return false;
}

//经过修改，把读取在循环中滞后，防止最后一组数据的多次重复读取引起的误差
void Admin::Init_The_Store_List()
{
	FILE *the_list_file;//文件名
	char get1[THE_STR_LEN + 1], get2[THE_STR_LEN + 1], get3[THE_STR_LEN + 1];
	double get4;
	int get5;

	if (fopen_s(&the_list_file, the_store_list_file.c_str(), "r"))
	{
		std::cout << "无法打开指定的仓库文件，请检查您的文件配置。" << std::endl;
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
	std::cout.setf(std::ios::left);//左对齐
	std::cout << std::setw(THE_TAB) << "ID" << std::setw(THE_TAB) << "名称"
		<< std::setw(THE_TAB) << "品牌" << std::setw(THE_TAB) << "价格"
		<< std::setw(THE_TAB) << "数量" << std::endl;
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
	std::cout << "请输入商品的名称：";
	std::cin >> name;
	std::cout << "请输入商品的品牌：";
	std::cin >> brand;
	std::cout << "请输入商品的价格：";
	std::cin >> price;
	std::cout << "请输入商品的数量：";
	std::cin >> num;

	int i = 0;
	for (; store_list[i].ID != "NULL"; i++)
	{
		if (store_list[i].name == name && store_list[i].brand == brand && store_list[i].price == price)
		{
			store_list[i].num += num;
			std::cout << "该商品已经存在于库存，将数量修改为" << store_list[i].num << std::endl;
			this->Write_List_File();
			return;
		}
	}
	//以下是没有该商品的添加情况
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
	std::cout << "增加了新进的商品：" << std::endl;
	std::cout << "ID：" << store_list[i].ID << "  名称：" << store_list[i].name << "  品牌："
		<< store_list[i].brand << "  价格：" << store_list[i].price << "  数量：" << store_list[i].num << std::endl;
	this->Write_List_File();
	return;
}

void Admin::Write_List_File()
{
	FILE *list_file;
	if (fopen_s(&list_file, the_store_list_file.c_str(), "w"))
	{
		std::cout << "请检查你的文件配置！" << std::endl;
		exit(-1);
	}
	else
	{
		fprintf_s(list_file, "%-16s%-16s%-16s%-16s%-16s", "ID", "名称", "品牌", "价格", "数量");
		for (int i = 0; store_list[i].ID != "NULL"; i++)
		{
			fprintf_s(list_file, "\n%-16s%-16s%-16s%-16.1f%-16d", store_list[i].ID.c_str(), store_list[i].name.c_str(), store_list[i].brand.c_str(), store_list[i].price, store_list[i].num);
		}
	}
	fclose(list_file);
	std::cout << "库存文件写入完场！" << std::endl;
	return;
}