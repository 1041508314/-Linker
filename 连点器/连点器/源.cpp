#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
int wait1 = 10, wait2 = 90;
float speed = 10;
string B = "���", mode = "��ס";
void menu()//��Ҫ��Ϣҳ�� 
{
	system("cls");//���� 
	cout << "�鿴����˵���밴[F1],���������밴[F2]" << endl << endl;
	cout << "��ǰ����ģʽ��" << mode << endl << "��ǰ���ư�����" << B << endl << "��ǰ�����ٶȣ�" << speed << "��/s" << endl;
}
void FAQ()//�������� 
{
	system("cls");
	cout << "Ϊʲô��ʾ�ĵ���ٶȺ�����ĵ���ٶȲ�һ����" << endl;
	cout << "�����ó�����Ƶ���ٶȵ�ʱ�䵥λΪms�����������ʾ�ٶ�Ϊ�ο�" << endl << endl;
	cout << "Ϊʲôʵ�ʵ���ٶȺ���ʾ�ĵ���ٶȲ�һ����" << endl;
	cout << "���������ڵ���Ӳ���Ĵ����ٶ�Ӱ�죬������ʾ�ٶ���ʵ���ٶ���ƫ��Ϊ��������" << endl << endl;
	cout << "Ϊʲôʹ�������Ῠ��" << endl;
	cout << "���������ٶȹ�����������CPU��Դ�����д������齵�͵���ٶ�" << endl << endl;
	cout << endl << "������������bilibili˽��Alan7am" << endl << endl;
	Sleep(1000);
	system("PAUSE");//��ͣ���� ����������� 
	menu();
}
void help()//����˵�� 
{
	system("cls");
	cout << "[����м�]����ʼ/��ͣ ����" << endl << "[�������]������������" << endl << "[�������]����������Ҽ�" << endl;
	cout << "[��Ctrl]���л�����ģʽ" << endl << "[��Shift]������ÿ���������" << endl << "[��Alt]����ͣ����" << endl << "[End]����ֹ����" << endl << endl;
	Sleep(1000);
	system("PAUSE");
	menu();
}
bool set()//����ÿ���������(�˴�ʹ��bool����Ϊ�з���ֵ) 
{
	cin.clear();//����cin�Ĵ���״̬ 
	cin.sync();//���cin�Ļ������ݣ���cin.clear()������������������ѭ�� 
	system("cls");
	cout << "������ÿ����������";
	cin >> speed;
	system("cls");
	if (speed<0) speed = speed*-1;
	if (speed<0.0001)//�ж��Ƿ�ֵ��С��������� 
	{
		cout << "�������";
		Sleep(1500);
		return 1;//����ֵΪ1����ѭ�� 
	}
	if (speed>1000)//��ʹ��Sleep������ʱ��speed���ܴ���1000��������ʱΪ0 
	{
		cout << "���棡����1000��/��������ٶȲ��ɿأ����ܻᵼ�µ��Կ��٣�" << endl;
		cout << "�Ƿ������ǰ�趨��" << endl << "1:��,�����趨         2:��,�����趨";
		getch();//�ȴ����¼��� 
		if (GetKeyState(49)<0 || GetKeyState(97)<0) speed = 9999;//�ø�ֵ�����壬ֻ�Ǹ���ʹ�����ٶȴﵽ���� 
		else return 1;//����ֵΪ1����ѭ�� 
	}
	wait1 = 500 / speed;
	if (wait1>10) wait1 = 10;
	wait2 = 1000 / speed - wait1;
	if (speed != 9999) speed = (float)1000 / (wait1 + wait2);//���������ٶȣ���ʹ���߲ο� 
	menu();
	return 0;//����ֵΪ0��ֹwhileѭ�� 
}

void click()//������� 
{
	if (B == "���")
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(wait1);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(wait2);
	}
	else
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		Sleep(wait1);
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		Sleep(wait2);
	}
}
int main()
{
	for (int i = 0; i <= 1200; i++)//�ſ����������  #���� 
	{
		if (i == 0)system("color 4F");
		if (i == 200)system("color 2F");
		if (i == 400)system("color 1F");
		if (i == 600)system("color 4F");
		if (i == 800)system("color 6F");
		if (i == 1000)system("color 1F");
		if (i % 4 == 0)cout << endl;
		if (i <= 200)cout << "|     ��ӭ     |";
		if (i <= 400 && i>200)cout << "|     ʹ��     |";
		if (i <= 600 && i>400)cout << "|      ��      |";
		if (i <= 800 && i>600)cout << "|   Alan_7am   |";
		if (i <= 1000 && i>800)cout << "|    ������    |";
		if (i>1000)cout << "|  ���������  |";
		Sleep(1);
	}
	system("color 0F");
	menu();
	while (GetKeyState(35) == 0)
	{
		if (GetKeyState(4) && mode == "�л�") { click(); continue; }
		if (GetKeyState(4)<0 && mode == "��ס") { click(); continue; }
		if (GetKeyState(37)<0 && B != "���") { B = "���"; menu(); }
		if (GetKeyState(39)<0 && B != "�Ҽ�") { B = "�Ҽ�"; menu(); }
		if (GetKeyState(112)<0) help();
		if (GetKeyState(113)<0) FAQ();
		if (GetKeyState(VK_RSHIFT)<0) while (set());//while�������������������� 
		if (GetKeyState(VK_RCONTROL)<0)//�л�����ģʽ 
		{
			if (mode == "��ס") mode = "�л�";
			else mode = "��ס";
			while (GetKeyState(VK_RCONTROL)<0) Sleep(10);
			menu();
		}
		if (GetKeyState(VK_RMENU))//��ͣ���� 
		{
			system("cls");
			cout << "��������ͣ����[��ALT]����...";
			while (GetKeyState(VK_RMENU)) Sleep(10);
			menu();
		}
		Sleep(1);
	}
}