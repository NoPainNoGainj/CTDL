#include<bits/stdc++.h>
using namespace std;
typedef int Data;
typedef struct tagDNODE
{
	Data Info;
	struct tagDNODE* pPrev;
	struct tagDNODE* pNext;
}DNODE;

typedef struct tagDLIST
{
	DNODE* pHead;
	DNODE* pTail;
}DLIST;

DNODE* GetNODE(Data x)
{
	DNODE *p;
	p = new DNODE;
	if(p==NULL)
	{
		cout<<"Khong su bo nho";
		exit(1);
	}
	p->Info = x;
	p->pPrev = p->pNext = NULL;
	int demptu = 0;
	return p;
}

void ChenPTuDau(DLIST &l, DNODE* new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	} else
	{
		new_ele->pNext = l.pHead;
		l.pHead->pNext = new_ele;
		l.pHead = new_ele;
	}
}

DNODE* ThemGTriDau(DLIST &l, Data x)
{
	DNODE* new_ele = GetNODE(x);
	if(new_ele==NULL)
		return NULL;
	ChenPTuDau(l,new_ele);
	return new_ele;
}

void ChenPTuCuoi(DLIST &l, DNODE* new_ele)
{
	if(l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		new_ele->pPrev = l.pTail;
		l.pTail = new_ele;
	}
}

DNODE* ThemGTriCuoi(DLIST &l, Data x)
{
	DNODE* new_ele = GetNODE(x);
	if(new_ele==NULL)
		return NULL;
	ChenPTuCuoi(l,new_ele);
	return new_ele;
}

