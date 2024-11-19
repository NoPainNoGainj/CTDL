#include<bits/stdc++.h>
#define max 100
using namespace std;
typedef int item;
typedef int Data;
struct NODE
{
	item Data;
	NODE *Next;
};
typedef struct Stack
{
	NODE* Top;
};

void Init(Stack &S); //Khoi tao Stack rong
int Isempty(Stack S); //Kiem tra Stack co rong khong
int Lenght(Stack S); //Do dai Stack
void Push(Stack &S, item x); //them phan tu vao Stack
int Peak(Stack S); //Lay phan tu o dau nhuwng khong xoa
int Pop(Stack &S); //Loai bo phan tu ra khoi Stack

void Init(Stack &S) //Khoi tao Stack rong
{
	S.Top=NULL; 
}

int Isempty(Stack S) //Kiem tra Stack rong
{
	return (S.Top==NULL);
}
int Lenght (Stack S)
{
	NODE* p=S.Top;
	int i=0;
	while (p!=NULL)// trong khi chua het Stack thi van duyet
	{
		i++;
		p=p->Next;
	}
	return i;
}

NODE* TaoNODE(item x) //tao 1 NODE
{
	NODE* p=(NODE*) malloc(sizeof(NODE));
	p->Next = NULL;
	p->Data = x;
	return p;
}

void Push(Stack &S, item x)
{
	NODE* p = TaoNODE(x);
	p->Next = S.Top;
	S.Top = p;
}

int Peak(Stack S)
{
	return S.Top->Data;
}

int Pop(Stack &S)
{
	if(!Isempty(S))
	{
		item x =S.Top->Data;
		S.Top = S.Top->Next;
		return x;
	}
}

void nhapStack(Stack &S)
{
	int n,m;
	cout<<"Nhap vao so luong phan tu: ";
	cin>>n;
	for(int i =0;i<n;i++)
	{
		cout<<"Nhap phan tu thu "<<i+1<<": ";
		cin>>m;
		Push(S,m);
	}
}

void xuatStack(Stack S)
{
	cout<<"Cac phan tu vua nhap vao danh sach la: ";
	while(!Isempty(S))
	{
		cout<< Pop(S)<<" ";
	}
	cout<<endl;
}

int main()
{
	Stack S;
	Init(S);
	nhapStack(S);
	xuatStack(S);
	
	return 0;
}
