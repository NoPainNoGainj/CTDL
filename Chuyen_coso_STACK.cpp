#include <iostream>
using namespace std;

typedef int Data;
typedef struct NODE  {
	Data		Info;  	
	struct NODE * 	pNext; 	
};	
typedef struct INT_STACK 	// kieåu danh saùch lieân keát
{
	NODE* Top;
	//NODE* pTail; 	
	int soptu;
};	
void khoitao(INT_STACK &l);
int isEmpty(INT_STACK l);
NODE*	GetNode(Data x);
void AddFirst(INT_STACK &l, NODE *new_ele);
int Pop(INT_STACK &l);
void Push(INT_STACK &l, int x);
char chuyen_chu(int x); // chuyen ky tu cho hexa >=10

int main()
{
	int x, du;
	INT_STACK stack; // khai bao
	khoitao(stack); // khoi tao
	cout << "Nhap so can chuyen: "; cin >> x;
	while (x)
	{
		du = x % 16;
		Push(stack,du); // them vao stack
		x /=16;	
	} 
	while (!isEmpty(stack))
	{
		int y = Pop(stack); // lay ra stack
		char kt;
		if (y >= 10)
		{
		   kt = chuyen_chu(y);
		   cout << kt;
	    }
	    else
	    	cout << y;	
	}
}
void khoitao(INT_STACK &l)
{
	l.Top = NULL;
	l.soptu = 0;
}
int isEmpty(INT_STACK l)
{
	return (l.Top == NULL);
}
NODE*	GetNode(Data x)
{
	NODE *p;
	// Caáp phaùt vuøng nhôù cho phaàn töû
	p = new NODE;
	if (p==NULL)   { 
		printf("Khong du bo nho..."); return NULL; 
	}
	p->Info = x; // Gaùn thoâng tin cho phaàn töû p
	p->pNext = NULL;
	return p; 
}
void AddFirst(INT_STACK &l, NODE *new_ele)
{
	if (l.Top == NULL)  //Xaâu roãng
		l.Top = new_ele;
	else {	
		new_ele->pNext = l.Top;  
		l.Top = new_ele;
	}
}
int Pop(INT_STACK &l) {
	NODE	*p = NULL;
	if (l.Top != NULL)	{   
		p = l.Top; 
		l.Top = l.Top->pNext;
		p->pNext = NULL;
	}
	int x = p->Info;
	delete p;  // GIAI PHONG VUNG NHO CHUA PTU DAU INT_STACK
	return x;    

}

void Push(INT_STACK &l, int x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele != NULL)
		AddFirst(l, new_ele);
}
char chuyen_chu(int x) // chuyen ky tu cho hexa >=10
{
	char kq;
	switch (x)
	{
		case 10:
			kq = 'A';
			break;
		case 11:
			kq = 'B';
			break;
		case 12:
			kq = 'C';
			break;
		case 13:
			kq = 'D';
			break;
		case 14:
			kq = 'E';
			break;
		case 15:
			kq = 'F';
		}
		return kq;
}
