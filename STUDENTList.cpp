#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct SV
{
	int msv; // ma sinh vien
	char tsv[30]; // ten sinh vien
	int ns; // nam sinh
};
typedef struct NODE{
	SV		Info;  	
	struct NODE * 	pNext; 	
};
typedef struct STUDENT_LIST	// kieåu danh saùch lieân keát
{
	NODE* pHead;
	NODE* pTail; 	
	int slsv;// optional
};	
void khoitao(STUDENT_LIST &l);
void nhap_SV(SV &sv);
void in_SV(SV sv);
void Hoan_vi(SV &a, SV &b);
void sort_dssv(STUDENT_LIST &l);
NODE* tim_SV(STUDENT_LIST l,char ten[30]);
NODE*	GetNode(SV x);
void AddTail(STUDENT_LIST &l, NODE *new_ele);
void nhapds(STUDENT_LIST &l); 
void xuatds(STUDENT_LIST l);
void timxoa_ptds(STUDENT_LIST &l);
NODE* PickHead(STUDENT_LIST &l);
NODE* PickAfter (STUDENT_LIST &l, NODE *q);
NODE* PickNode(STUDENT_LIST &l, int msv);
void RemoveSTUDENTList(STUDENT_LIST &l);
int main()
{
	STUDENT_LIST l;
	int chon;
	do
	{
		cout << "Chon hanh dong " << endl;
		cout << "1. Nhap ds sinh vien \n";
		cout << "2. Xuat ds sinh vien \n";
		cout << "3. Xoa 1 sinh vien \n";
		cout << "4. Tim 1 sinh vien \n";
		cout << "5. Sap xep ds sinh vien \n";
		cout << "8 Huy ds sinh vien va thoat chuong trinh\n";
		
		cout << "Nhap so de chon: "; cin >> chon;
		switch (chon)
		{
			case 1:
				nhapds(l);
				break;
			case 2:
				xuatds(l);
				break;
			case 3:
				timxoa_ptds(l);
				break;
			case 4:
				in_SV(tim_SV(l,"Nguyen Van A")->Info);
				break;
			case 5:
				sort_dssv(l);
				break;
			case 8:
				RemoveSTUDENTList(l);
				break;
		}
	}while (chon != 8);
	return 0;
}

void RemoveSTUDENTList(STUDENT_LIST &l)
{
	NODE	*p;
	while (l.pHead!= NULL) {
		p = l.pHead;
		l.pHead = p->pNext;
	   delete p;
	}
	l.pTail = NULL;
}
void khoitao(STUDENT_LIST &l)
{
	l.pHead = l.pTail = NULL;
	l.slsv = 0;
}
NODE*	GetNode(SV x)
{
	NODE *p;
	// Caáp phaùt vuøng nhôù cho phaàn töû
	p = new NODE;
	if (p==NULL)   { 
		printf("Khoâng ñuû boä nhôù"); return NULL; 
	}
	p->Info = x; // Gaùn thoâng tin cho phaàn töû p
	p->pNext = NULL;
	return p; 
}
void AddTail(STUDENT_LIST &l, NODE *new_ele)
{
	if (l.pHead==NULL)  
		l.pHead = l.pTail = new_ele;
	else
		l.pTail = l.pTail->pNext = new_ele;
}
void nhapds(STUDENT_LIST &l)
{
	SV x;
	int n;
	NODE *p;
	if (l.pHead != NULL)
		RemoveSTUDENTList(l);
	else
		khoitao(l);
	cout << "Can nhap so luong sv = "; cin >> n;
	for(int i = 0; i < n; i++)
	{
	cout << "Nhap sv: " << endl; nhap_SV(x);
	p = GetNode(x);
	if (p != NULL)
		AddTail(l,p);
		l.slsv++;	
	}
}
void xuatds(STUDENT_LIST l)
{
	cout << "Danh sach sinh viên: \n";
	int dem = 1;
	for(NODE *p = l.pHead;p != NULL; p = p->pNext)
			in_SV(p->Info);
}
NODE* PickNode(STUDENT_LIST &l, int msv)
{	
	NODE	*p = l.pHead;
	NODE	*q = NULL;
	while ((p != NULL) && ((p->Info).msv != msv))
	{
			q = p;
			p = p->pNext;
	}
	if(p == NULL) return NULL; 
	return PickAfter(l, q);
}
NODE* PickAfter (STUDENT_LIST &l, NODE *q)
{	
	NODE	*p;
	if ( q != NULL) {
		p = q ->pNext ;
		if ( p != NULL) {
			if (p == l.pTail)  l.pTail = q;
	       	q->pNext = p->pNext;
			p->pNext = NULL;
		}
	}
	else  
		p = PickHead(l);   
	return p;
}
NODE* PickHead(STUDENT_LIST &l)
{	
	NODE	*p = NULL;
	if (l.pHead != NULL)	{   
		p = l.pHead; 
		l.pHead = l.pHead->pNext;
		p->pNext = NULL;
		if(l.pHead == NULL)	
			l.pTail =  NULL;
	}  
	return p;    
}
void timxoa_ptds(STUDENT_LIST &l)
{
 int x;

 cout << "Nhap ma sinh vien can thoi hoc: "; cin >> x;
 NODE * ele = PickNode(l,x);
 if (ele != NULL)
 {
	cout << "Da xoa sinh vien " << (ele->Info).tsv << " khoi ds" << endl;
	delete ele;
}
 else
	cout << "Khong tim thay sinh vien co ma " << x << " can xoa";	
}
void sort_dssv(STUDENT_LIST &l)
{
	NODE	*min, *p,*q;	
	p = l.pHead;
	while(p != l.pTail) {
		q = p->pNext; min = p;
		while(q != NULL) {
			if((q->Info).ns > (min->Info).ns) 
				min = q; // ghi nhaän vò trí phaàn töû min hieän haønh
			q = q->pNext;
		} 
		Hoan_vi(min->Info, p->Info); 
		p = p->pNext;
	}
}
void nhap_SV(SV &sv)
{
	cout << "Nhap msv: "; cin >> sv.msv;
	fflush(stdin);
	cout << "Nhap ten sinh vien: "; gets(sv.tsv);
	fflush(stdin);
	cout << "Nhap nam sinh sv: "; cin >> sv.ns;
}
void in_SV(SV sv)
{
	cout << sv.msv << "\t" << sv.tsv << "\t" << sv.ns << endl;
}
void Hoan_vi(SV &a, SV &b)
{
	SV tg = a;
	a = b;
	b = tg;
}
NODE* tim_SV(STUDENT_LIST l,char *ten)
{
	NODE *p;
	p = l.pHead;
	while ((p != NULL) && (strcmp((p->Info).tsv,ten) != 0))
		p = p->pNext;
	return p;
			
}

