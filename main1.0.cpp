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
	string input;//��Ϊ���в������������
	

	Start_Screen();
	cin >> input;
	while (input != "0")
	{
		if (input == "1");
		//����Աģʽ
		else if (input == "3")
		{
			if (the_admin.Pass_Check())//��¼�ɹ�
			{
				getchar(); getchar();
				system("CLS");
				the_admin.Init_The_Store_List();//��Ϊһ��ʼ������Ϣ�ĳ�ʼ��
				Admin_Menu();
				cout << "�����������";
				cin >> input;
				while (input != "0")
				{
					if (input == "1")//��ѯ��Ʒ
					{
						the_admin.Print_List();
					}
					else
					{
						cout << "��" << input << "��" << "Ϊ���Ϸ��Ĳ�������" << endl;
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
//��������
void Start_Screen()
{
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;
	cout << "1.�û���¼\t2.�û�ע��\t3.����Ա��¼" << endl;
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;
	cout << "�����������";
	return;
}
//����Աѡ���ܵĽ���
void Admin_Menu()
{
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;
	cout << "1.��ѯ��Ʒ\t";
	//δ��ɲ���
	cout << endl;
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;	
	return;
}
//ÿ�ι���֮����½���ʾ
void Low_Screen()
{
	for (int i = 0; i < THE_SCREEN_LEN; i++)
		cout << "=";
	cout << endl;
	cout << "�����������";
	return;
}