#include<iostream>
using namespace std;
#include"��ͷ.h"

//����һ���ڵ�
struct Lnode
{
	int data;//����������
	Lnode* next;//����ָ����
};
typedef Lnode* LinkList;

//����ĳ�ʼ��
bool InitList(LinkList& L)//�������⻰��LinkList &L�ȼ��� Lnode *&L��Lnode *&L��һ��ָ��ָ�������
{
	L = new Lnode; //��������һ��ͷ��㣬������������ΪLnode
	L->next = NULL;  //�ձ�Ҳ����˵ͷ����ָ��ָ��Ϊ��
	return true;
}

//β�巨����������
void CreatListTail(LinkList& L, const size_t n)
{
	Lnode* r = L;
	cout << "������ڵ��������" << endl;
	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

//ͷ�巨����������
void CreateList(LinkList& L, size_t n)
{
	cout << "������ڵ��������" << endl;
	for (int i = 0; i < n; i++)
	{
		Lnode* p = new Lnode;//�����½ڵ�
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//��������
void printList(LinkList& L)
{
	Lnode* p;
	p = L->next;
	while (p)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

//�������е�i������Ԫ��ɾ��
bool DeleteList(LinkList& L, size_t i)
{
	Lnode* p;
	int j = 0;
	p = L;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
		return false;
	Lnode* q = new Lnode;
	q = p->next;
	p->next = q->next;
	delete q;
	return true;
}

int main()
{

	LinkList L;
	Lnode* p;
	InitList(L);
	cout << "������Ҫ��ӵĽڵ������" << endl;
	int n;
	cin >> n;
	CreateList(L, n);
	printList(L);

	/*CreatListTail(L, n);
	printList(L);
	cout << "������Ҫɾ���Ľڵ�λ��" << endl;
	int m;
	cin >> m;
	DeleteList(L, m);
	printList(L);*/
	system("pause");
	system("cls");
	return 0;
}