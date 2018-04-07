#include"head1.0.h"


#define THE_SCREEN_LEN 60
#define THE_SCREEN_HIGHT 20

using namespace std;

void Start_Screen();
void Admin_Menu();
void Low_Screen();

Admin the_admin;


int main()
{
	string input;//作为所有操作的输入输出
	

	Start_Screen();
	cin >> input;
	while (input != "0")
	{
		if (input == "1");
		//管理员模式
		else if (input == "3")
		{
			if (the_admin.Pass_Check())//登录成功
			{
				getchar(); getchar();
				system("CLS");
				the_admin.Init_The_Store_List();//作为一开始储存信息的初始化
				Admin_Menu();
				cout << "请输入操作：";
				cin >> input;
				while (input != "0")
				{
					if (input == "1")//查询商品
					{
						the_admin.Print_List();
					}
					else
					{
						cout << "“" << input << "”" << "为不合法的操作输入" << endl;
					}
					Low_Screen();
					cin >> input;
					system("CLS");
					Admin_Menu();
				}
			}
		}
	}
	


	return 0;
}
//开机界面
void Start_Screen()
{
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;
	cout << "1.用户登录\t2.用户注册\t3.管理员登录" << endl;
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;
	cout << "请输入操作：";
	return;
}
//管理员选择功能的界面
void Admin_Menu()
{
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;
	cout << "1.查询商品\t";
	//未完成部分
	cout << endl;
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;	
	return;
}
//每次功能之后的下界显示
void Low_Screen()
{
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;
	cout << "请输入操作：";
	return;
}