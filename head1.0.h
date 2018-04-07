#pragma once
#include<iostream>
#include<string>

#define THE_STORE_MAX 200
#define THE_STR_LEN 20
#define THE_TAB 16

struct LIST
{
	std::string ID = "NULL";
	std::string name = "NULL";
	std::string brand = "NULL";
	double price = 0.0;
	int num = 0;//һ���Ǵ���0��-1Ϊ�����ǣ���ʾ����Ʒ�Ѿ��¼�
	std::string owner = "NULL";//һ��ָ���û�������Ʒ�Ķ�ȡ��ʱ�򲻽���ʹ��
};

class Admin
{
private:
	std::string admin_name;
	std::string admin_password;
	std::string the_store_list_file;//��Ϊ���е���Ʒ�Ĵ���Ŀ¼
	std::string the_store_sold_file;//��Ϊ���е�������Ʒ��Ŀ¼
	std::string pass_check_file;//��Ϊ��¼��Ϣ�ļ��
	LIST store_list[THE_STORE_MAX];
public:
	Admin();
	~Admin();
	bool Pass_Check();
	void Init_The_Store_List();
	void Print_List();
};