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
	int num = 0;//一般是大于0，-1为错误标记，表示该商品已经下架
	std::string owner = "NULL";//一般指向用户，在商品的读取的时候不进行使用
};

class Admin
{
private:
	std::string admin_name;
	std::string admin_password;
	std::string the_store_list_file;//作为所有的商品的储存目录
	std::string the_store_sold_file;//作为所有的已售商品的目录
	std::string pass_check_file;//作为登录信息的检测
	LIST store_list[THE_STORE_MAX];
public:
	Admin();
	~Admin();
	bool Pass_Check();
	void Init_The_Store_List();
	void Print_List();
};