#include<iostream>
using namespace std;

//��������
typedef struct Lnode
{
	size_t data;
	Lnode* next;
}Lnode,*LinkList;

LinkList LA;
LinkList LB;
LinkList LC;

//˫������ĳ�ʼ��
void InitList(LinkList& L)
{
	L = new Lnode;
	L->next = NULL;
}


//β�巨����������
void CreatListTail(LinkList& L, const size_t n)
{
	Lnode* r = L;
	for (int i = 0; i < n; ++i)
	{
		cout << "������" << i+1 << "�ڵ��������" << endl;
		Lnode* p = new Lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

//�������
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

//����ĺϲ�--����
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
		while (p->next)//����La�������Ƿ�����ͬԪ��
		{
			p = p->next;
			if (p->data == q->data)
			{
				selete = 1;
				break;
			}
		}
		if (selete == 0)//���û�оͽ�����ڵ�������La����
		{
			r = q;
			r->next = NULL;
			p->next = r;
		}
	}
}

//��������ĺϲ�
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


//�˵�
void menu()
{
	cout << "-----------------------------" << endl;
	cout << "-------1������ĺϲ�---------" << endl;
	cout << "-------2����������ĺϲ�-----" << endl;
	cout << "-------0���˳�ϵͳ--------" << endl;
	cout << "-----------------------------" << endl;
}

//����ĺϲ�
void system1()
{
	cout << "��ֱ�Ϊ��������ֵ" << endl;
	cout << "�������һ������ĳ���" << endl;
	int selete1;
	cin >> selete1;
	CreatListTail(LA, selete1);
	cout << "---------------------------" << endl;
	cout << "������ڶ�������ĳ���" << endl;
	int selete2;
	cin >> selete2;
	CreatListTail(LB, selete2);
	cout << "---------------------------" << endl;
	merge_unorder(LA, LB);
	cout << "�ϲ�������Ϊ��" << endl;
	printLink(LA);
	system("pause");
	system("cls");
}

//���������ϲ�
void system2()
{
	cout << "��ֱ�Ϊ��������ֵ" << endl;
	cout << "�������һ������ĳ���" << endl;
	int selete1;
	cin >> selete1;
	CreatListTail(LA, selete1);
	cout << "---------------------------" << endl;
	cout << "������ڶ�������ĳ���" << endl;
	int selete2;
	cin >> selete2;
	CreatListTail(LB, selete2);
	cout << "---------------------------" << endl;
	merge_order(LA, LB, LC);
	cout << "�ϲ�������Ϊ��" << endl;
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
		cout << "����������ѡ��" << endl;
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