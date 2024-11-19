#include<bits/stdc++.h>
using namespace std;
typedef int Data;
typedef struct NODE{
	Data Info;
	struct NODE * pNext;
};

typedef 	struct SLIST 
{
	NODE* pHead;
	NODE* pTail; 	
};	

NODE*	GetNode(Data x) 
{	
	NODE *p;
	p = new NODE;
	if (p==NULL)   { 
		printf("Khong du bo nho"); return NULL; 
	}
	p->Info = x;
	p->pNext = NULL;
	return p; 
}

void Init(SLIST &l)
{
	l.pHead = l.pTail = NULL;
}

void AddFirst(SLIST &l, NODE* new_ele)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = new_ele;
	else {	
		new_ele->pNext = l.pHead;  
		l.pHead = new_ele; 	
	}
}

NODE* InsertHead(SLIST &l, Data x)
{	
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
		return NULL;
	AddFirst(l, new_ele);
	return new_ele;
}

void AddTail(SLIST &l, NODE *new_ele)
{
	if (l.pHead==NULL)  
		l.pHead = l.pTail = new_ele;
	else
		l.pTail = l.pTail->pNext = new_ele;	
}

NODE* InsertTail(SLIST &l, Data x)
{
	NODE* new_ele = GetNode(x);
	
	if (new_ele == NULL)  
		return NULL;
	AddTail(l, new_ele);
	return new_ele;
}

void Nhap(SLIST &l,int n)
{
	Init(l);
	for(int i=0;i<n;i++)
	{
		Data x;
		cin>>x;
		NODE* new_ele=GetNode(x);
		if(new_ele!=NULL){
		InsertTail(l,x);
		}
		
	}
}
void Xuat(SLIST l)
{
	NODE *p = l.pHead;
	while(p!=NULL)
	{
		cout<<p->Info<<" ";
		p = p->pNext;
	}
	cout<<endl;
}

int main()
{
	int n;
	SLIST l;
    Init(l);
    cout<<"Nhap so phan tu: ";
	cin>>n;
    Nhap(l,n);
    Xuat(l);
    return 0;
}
