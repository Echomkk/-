#include"��ͷ.h"
#include<iostream>
using namespace std;

//˫������ķ�װ
typedef struct DuLnode
{
	int data;
	DuLnode* pair, * next;
} DuLnode, * DuLinkList;

DuLinkList L;

//˫������ĳ�ʼ��
void InitList(DuLinkList &L)
{
	L = new DuLnode;
	L->pair = NULL;
	L->next = NULL;
}

//ͷ�巨����˫������
void CreatListHand(DuLinkList &L,size_t n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "���ڵ��������" << endl;
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

//β�巨����˫������
void CreatListTair(DuLinkList& L,size_t n)
{
	DuLinkList q = L;
	while (q->next != NULL)
	{
		q = q->next;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "�������"<<i+1<<"���ڵ��������" << endl;
		DuLinkList p = new DuLnode;
		cin >> p->data;
		p->pair = q;
		q->next = p;
		p->next = NULL;
		q = p;
	}
}

//�������в�������
bool ListInsert_DuL(DuLinkList& L, size_t i, int num)//����λ�ã�������
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

//��������ָ��λ��Ԫ�ؽ���ɾ��
bool ListDelete_DuL(DuLinkList& L, size_t i)//����λ��
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

//����ָ��λ�ýڵ�����
int Find_Pos_DuL(DuLinkList &L,size_t i)
{
	DuLinkList p = L;
	for (int j = 0; j < i; j++)
	{
		p = p->next;
	}
	if (p)
	{
		cout << "���ҳɹ�" << endl;
		return p->data;
	}
	else
	{
		cout << "����ʧ��" << endl;
		return false;
	}
}

//����ָ�����ݽڵ�λ��
size_t Find_Data_DuL(DuLinkList &L,int data)
{
	DuLinkList p = L->next;
	size_t cit = 1;
	while (p)
	{
		if (p->data == data)
		{
			cout << "���ҳɹ�" << endl;
			return cit;
		}
		cit++;
		p = p->next;
	}
	cout << "����ʧ��" << endl;
	return false;
}

void MenuLnode()
{
	cout << "---------------------------" << endl;
	cout << "------1������˫������------" << endl;
	cout << "------2����������Ԫ��------" << endl;
	cout << "------3��ɾ������Ԫ��------" << endl;
	cout << "------4��������������------" << endl;
	cout << "------5�������������------" << endl;
	cout << "------6���˳�ϵͳ----------" << endl;
	cout << "---------------------------" << endl;
}

//����˫������
void system1()
{
	while (1)
	{
		cout << "1��ͷ�巨��������" << endl;
		cout << "2��β�巨��������" << endl;
		cout << "����������ѡ��" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			cout << "������Ҫ��ӵĽڵ����" << endl;
			int select1;
			cin >> select1;
			CreatListHand(L, select1);
			cout << "�������ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 2)
		{
			cout << "������Ҫ��ӵĽڵ����" << endl;
			int select1;
			cin >> select1;
			CreatListTair(L, select1);
			cout << "�������ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "���������������������룡" << endl;
		}
	}

}

//������������
void system2()
{
	while (1)
	{
		cout << "������Ҫ�����λ�ã�" << endl;
		size_t i = 0;
		cin >> i;
		cout << "���������ڵ��������" << endl;
		int num;
		cin >> num;
		if (ListInsert_DuL(L, i, num))
		{
			cout << "����ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "����ʧ�ܣ�������ѡ�����λ��" << endl;
		}
	}
}

//ɾ����������
void system3()
{
	while (1)
	{
		cout << "������Ҫɾ����λ�ã�" << endl;
		size_t i = 0;
		cin >> i;
		if (ListDelete_DuL(L, i))
		{
			cout << "ɾ���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�������ѡ��ɾ��λ��" << endl;
		}
	}
}

//������������
void system4()
{
	cout << "1������ָ��λ�ýڵ�����" << endl;
	cout << "2������ָ�����ݽڵ�λ��" << endl;
	cout << "����������ѡ��" << endl;
	int selete;
	cin >> selete;
	while (1)
	{
		if (selete == 1)
		{
			size_t i;
			cout << "������Ҫ���ҵĽڵ��λ��" << endl;
			cin >> i;
			int num = Find_Pos_DuL(L, i);
			cout << "����λ��ֵΪ��" << num << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (selete == 2)
		{
			int data;
			cout << "��������Ҫ���ҵ�������" << endl;
			cin >> data;
			cout << "��ֵ��λ��Ϊ��" << Find_Data_DuL(L, data) << endl;
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "����������������������" << endl;
		}
	}
}

//�������
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
		cout << "��������Ҫѡ��Ĳ���" << endl;
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
