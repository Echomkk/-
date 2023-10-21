#include"标头.h"
#include<iostream>
using namespace std;

//双向链表的封装
typedef struct DuLnode
{
	int data;
	DuLnode* pair, * next;
} DuLnode, * DuLinkList;

DuLinkList L;

//双向链表的初始化
void InitList(DuLinkList &L)
{
	L = new DuLnode;
	L->pair = NULL;
	L->next = NULL;
}

//头插法建立双向链表
void CreatListHand(DuLinkList &L,size_t n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个节点的数据域" << endl;
		DuLinkList p = new DuLnode;
		cin >> p->data;
		p->next = L->next;
		p->pair = L;
		L->next = p;
		if (i > 0)
		{
			p->next->pair = p;
		}
	}
}

//尾插法建立双向链表
void CreatListTair(DuLinkList& L,size_t n)
{
	DuLinkList q = L;
	while (q->next != NULL)
	{
		q = q->next;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第"<<i+1<<"个节点的数据域" << endl;
		DuLinkList p = new DuLnode;
		cin >> p->data;
		p->pair = q;
		q->next = p;
		p->next = NULL;
		q = p;
	}
}

//向链表中插入数据
bool ListInsert_DuL(DuLinkList& L, size_t i, int num)//链表，位置，数据域
{
	DuLinkList r = L;
	for (int j = 0; j < i; j++)
	{
		if (r->next == NULL)
		{
			return false;
		}
		r = r->next;
	}
	DuLinkList p=new DuLnode;
	p->data = num;
	p->pair = r->pair;
	r->pair->next = p;
	p->next = r;
	r->pair = p;
	return true;
}

//对链表中指定位置元素进行删除
bool ListDelete_DuL(DuLinkList& L, size_t i)//链表，位置
{
	DuLinkList r = L;
	for (int j = 0; j < i; j++)
	{
		if (r->next == NULL)
		{
			return false;
		}
		r = r->next;
	}
	if (r->next != NULL)
	{
		r->pair->next = r->next;
	}
	else
	{
		r->pair->next = NULL;
	}
	if (r->next != NULL)
	{
		r->next->pair = r->pair;
	}
	delete r;
	return true;
}

//查找指定位置节点数据
int Find_Pos_DuL(DuLinkList &L,size_t i)
{
	DuLinkList p = L;
	for (int j = 0; j < i; j++)
	{
		p = p->next;
	}
	if (p)
	{
		cout << "查找成功" << endl;
		return p->data;
	}
	else
	{
		cout << "查找失败" << endl;
		return false;
	}
}

//查找指定数据节点位置
size_t Find_Data_DuL(DuLinkList &L,int data)
{
	DuLinkList p = L->next;
	size_t cit = 1;
	while (p)
	{
		if (p->data == data)
		{
			cout << "查找成功" << endl;
			return cit;
		}
		cit++;
		p = p->next;
	}
	cout << "查找失败" << endl;
	return false;
}

void MenuLnode()
{
	cout << "---------------------------" << endl;
	cout << "------1、建立双向链表------" << endl;
	cout << "------2、插入链表元素------" << endl;
	cout << "------3、删除链表元素------" << endl;
	cout << "------4、查找链表数据------" << endl;
	cout << "------5、输出链表数据------" << endl;
	cout << "------6、退出系统----------" << endl;
	cout << "---------------------------" << endl;
}

//建立双向链表
void system1()
{
	while (1)
	{
		cout << "1、头插法建立链表" << endl;
		cout << "2、尾插法建立链表" << endl;
		cout << "请输入您的选择" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入要添加的节点个数" << endl;
			int select1;
			cin >> select1;
			CreatListHand(L, select1);
			cout << "链表建立成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 2)
		{
			cout << "请输入要添加的节点个数" << endl;
			int select1;
			cin >> select1;
			CreatListTair(L, select1);
			cout << "链表建立成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "您的输入有误，请重新输入！" << endl;
		}
	}

}

//插入链表数据
void system2()
{
	while (1)
	{
		cout << "请输入要插入的位置：" << endl;
		size_t i = 0;
		cin >> i;
		cout << "请输入插入节点的数据域：" << endl;
		int num;
		cin >> num;
		if (ListInsert_DuL(L, i, num))
		{
			cout << "插入成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "插入失败，请重新选择插入位置" << endl;
		}
	}
}

//删除链表数据
void system3()
{
	while (1)
	{
		cout << "请输入要删除的位置：" << endl;
		size_t i = 0;
		cin >> i;
		if (ListDelete_DuL(L, i))
		{
			cout << "删除成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "删除失败，请重新选择删除位置" << endl;
		}
	}
}

//查找链表数据
void system4()
{
	cout << "1、查找指定位置节点数据" << endl;
	cout << "2、查找指定数据节点位置" << endl;
	cout << "请输入您的选择" << endl;
	int selete;
	cin >> selete;
	while (1)
	{
		if (selete == 1)
		{
			size_t i;
			cout << "请输入要查找的节点的位置" << endl;
			cin >> i;
			int num = Find_Pos_DuL(L, i);
			cout << "查找位置值为：" << num << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (selete == 2)
		{
			int data;
			cout << "请输入您要查找的数据域" << endl;
			cin >> data;
			cout << "该值的位置为：" << Find_Data_DuL(L, data) << endl;
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "您的输入有误，请重新输入" << endl;
		}
	}
}

//输出链表
void printLnode(DuLinkList& L)
{
	DuLinkList p = L;
	p = p->next;
	while (p)
	{
		cout << p->data << "   ";
		p = p->next;
	}
	cout << endl;
	system("pause");
	system("cls");
}


int main()
{
	InitList(L);
	while (1)
	{
		MenuLnode();
		int n1;
		cout << "请输入您要选择的操作" << endl;
		cin >> n1;
		switch (n1)
		{
		case 1:
			system1();
			break;
		case 2:
			system2();
			break;
		case 3:
			system3();
			break;
		case 4:
			system4();
			break;
		case 5:
			printLnode(L);
			break;
		case 6:
			exit(0);
			break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}
