#include<bits/stdc++.h>
#define max 100
using namespace std;
typedef int item;
typedef int Data;
struct Stack //dinh nghia Stack
{
	int Top;
	item Data[max];
};

void Init(Stack &S); //Khoi tao Stack rong
int Isempty(Stack S); //Kiem tra Stack co rong khong
int Isfull(Stack S); //Kiem tra Stack co day khong
void Push(Stack &S, item x); //them phan tu vao Stack
int Peak(Stack S); //Lay phan tu o dau nhuwng khong xoa
int Pop(Stack &S); //Loai bo phan tu ra khoi Stack

void Init(Stack &S) //Khoi tao Stack rong
{
	S.Top=0; //Stack rong khi Top = 0
}

int Isempty(Stack S) //Kiem tra Stack rong
{
	return (S.Top==0);
}

int Isfull(Stack S) //Kiem tra Stack Day'
{
	return(S.Top==max);
}

void Push(Stack &S, item x) //Them phan tu vao Stack
{
	if(!Isfull(S))
	{
		S.Data[S.Top]=x; //Gan du lieu
		S.Top ++; //Tang Top len 1
	}
}

int Peak(Stack S) //Lay phan tu o dau nhung khong xoa
{
	return S.Data[S.Top-1]; //lay du lieu tai Top
}

int Pop(Stack &S) //Loai bo phan tu khoi Stack
{
	if(!Isempty(S))
	{
		S.Top -- ; //Giam Top
		return S.Data[S.Top]; //Lay du du lieu tai TOP
	}
}
void nhapStack(Stack &S)
{
	int n, m;
	cout<<"Nhap so luong phan tu: ";
	cin>>n;
	if(n>max)
	{
		cout<<"Vuot qua so phan tu cho phep !";
		return;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap phan tu thu "<<i+1<<": ";
		cin>>m;
		Push(S,m);
	}
}
int main()
{
	Stack S;
	Init(S);
	nhapStack(S);
	cout<<"Cac phan tu trong danh sach vua nhap la: ";
	for(int i= S.Top-1;i>=0;i--)
	{
		cout<< S.Data[i]<<" ";
	}
	cout<< endl;
	return 0;
}
