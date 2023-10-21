#include<iostream>
using namespace std;

//建立链表
typedef struct Lnode
{
	size_t data;
	Lnode* next;
}Lnode,*LinkList;

LinkList LA;
LinkList LB;
LinkList LC;

//双向链表的初始化
void InitList(LinkList& L)
{
	L = new Lnode;
	L->next = NULL;
}


//尾插法创建单链表
void CreatListTail(LinkList& L, const size_t n)
{
	Lnode* r = L;
	for (int i = 0; i < n; ++i)
	{
		cout << "请输入" << i+1 << "节点的数据域" << endl;
		Lnode* p = new Lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

//输出链表
void printLink(LinkList& L)
{
	LinkList p = L->next;
	while (p)
	{
		cout << p->data << "   ";
		p = p->next;
	}
	cout << endl;
}

//链表的合并--无序
void merge_unorder(LinkList &La,LinkList &Lb)
{
	LinkList p = La;
	LinkList q = Lb;
	LinkList r;
	int selete1 = 0;
	while (q->next)
	{
		q = q->next;
		int selete = 0;
		p = La;
		while (p->next)//遍历La，查找是否有相同元素
		{
			p = p->next;
			if (p->data == q->data)
			{
				selete = 1;
				break;
			}
		}
		if (selete == 0)//如果没有就将这个节点链接在La后面
		{
			r = q;
			r->next = NULL;
			p->next = r;
		}
	}
}

//有序链表的合并
void merge_order(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	LinkList p = La->next;
	LinkList q = Lb->next;
	Lc = La;
	LinkList r=Lc;
	while (p && q)
	{
		if (p->data < q->data)
		{
			r->next = p;
			r = r->next;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = r->next;
			q = q->next;
		}
	}
	if (p)
	{
		r->next = p;
	}
	else
	{
		r->next = q;
	}
}


//菜单
void menu()
{
	cout << "-----------------------------" << endl;
	cout << "-------1、链表的合并---------" << endl;
	cout << "-------2、有序链表的合并-----" << endl;
	cout << "-------0、退出系统--------" << endl;
	cout << "-----------------------------" << endl;
}

//链表的合并
void system1()
{
	cout << "请分别为两个链表赋值" << endl;
	cout << "请输入第一个链表的长度" << endl;
	int selete1;
	cin >> selete1;
	CreatListTail(LA, selete1);
	cout << "---------------------------" << endl;
	cout << "请输入第二个链表的长度" << endl;
	int selete2;
	cin >> selete2;
	CreatListTail(LB, selete2);
	cout << "---------------------------" << endl;
	merge_unorder(LA, LB);
	cout << "合并后链表为：" << endl;
	printLink(LA);
	system("pause");
	system("cls");
}

//链表的有序合并
void system2()
{
	cout << "请分别为两个链表赋值" << endl;
	cout << "请输入第一个链表的长度" << endl;
	int selete1;
	cin >> selete1;
	CreatListTail(LA, selete1);
	cout << "---------------------------" << endl;
	cout << "请输入第二个链表的长度" << endl;
	int selete2;
	cin >> selete2;
	CreatListTail(LB, selete2);
	cout << "---------------------------" << endl;
	merge_order(LA, LB, LC);
	cout << "合并后链表为：" << endl;
	printLink(LC);
	system("pause");
	system("cls");
}

int main()
{
	InitList(LA);
	InitList(LB);
	InitList(LC);
	int selete = 0;
	while (1)
	{
		menu();
		cout << "请输入您的选择：" << endl;
		cin >> selete;
		switch (selete)
		{
		case 1:
			system1();
			break;
		case 2:
			system2();
			break;
		case 0:
			exit(0);
			break;
		}
	}
	system("pause");
	system("cls");
	return 0;
}