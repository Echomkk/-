#include<iostream>
using namespace std;
#include"标头.h"

//定义一个节点
struct Lnode
{
	int data;//结点的数据域
	Lnode* next;//结点的指针域
};
typedef Lnode* LinkList;

//链表的初始化
bool InitList(LinkList& L)//插入题外话：LinkList &L等价于 Lnode *&L，Lnode *&L是一个指向指针的引用
{
	L = new Lnode; //堆区开辟一个头结点，结点的数据类型为Lnode
	L->next = NULL;  //空表，也就是说头结点的指针指向为空
	return true;
}

//尾插法创建单链表
void CreatListTail(LinkList& L, const size_t n)
{
	Lnode* r = L;
	cout << "请输入节点的数据域" << endl;
	for (int i = 0; i < n; ++i)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

//头插法创建单链表
void CreateList(LinkList& L, size_t n)
{
	cout << "请输入节点的数据域" << endl;
	for (int i = 0; i < n; i++)
	{
		Lnode* p = new Lnode;//创建新节点
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//链表的输出
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

//将链表中第i个数据元素删除
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
	cout << "请输入要添加的节点个数：" << endl;
	int n;
	cin >> n;
	CreateList(L, n);
	printList(L);

	/*CreatListTail(L, n);
	printList(L);
	cout << "请输入要删除的节点位置" << endl;
	int m;
	cin >> m;
	DeleteList(L, m);
	printList(L);*/
	system("pause");
	system("cls");
	return 0;
}