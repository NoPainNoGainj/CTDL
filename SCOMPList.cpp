#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct COMP
{
	int ml; // ma loai may tinh
	char tlmt[30]; // ten loai may tinh
	int tk; // so luong ton kho
};
typedef struct NODE{
	COMP		Info;  	
	struct NODE * 	pNext; 	
};
typedef struct COMP_LIST	// kieåu danh saùch lieân keát
{
	NODE* pHead;
	NODE* pTail; 	
	int slmt;
};	
void khoitao(COMP_LIST &l);
void nhap_mt(COMP &c);
void in_mt(COMP c);
NODE*	GetNode(SV x);
void nhap_dsmt(COMP_LIST &l);
void in_dsmt(COMP_LIST l, int tk); // in ds loai mt co sl ton kho toi thieu tk

void them_mt(COMP_LIST &l);
void sua_mt_theo_mlmt(COM_LIST l);
void xoa_mt_theo_mlmt(COMP_LIST &l);
NODE* tim_mt_theo_mlmt(COM_LIST l);
int main()
{
	COMP_LIST l;
	COMP c;
	
	khoitao(l);
	cout << "Nhap danh sach loai may tinh: " << endl;
	nhap_dsmt(l);
	cout << "Danh sach may tinh vua nhap \n";
	in_dsmt(l);
	
	int chon;
	do
	{
		cout << "1. Them may tinh \n";
		cout << "2. Sua thong tin may tinh \n";
		cout << "3. Xoa loai may tinh \n";
		cout << "4. Tim loai may tinh \n";
		cout << "5. In ds loai may tinh theo ton kho toi thieu k";
		cout << "Chon hanh dong tu danh sach sau: " << endl; cin >> chon;
		switch (chon)
		{
			case 1:
				them_mt(l);
				break;
			case 2:
				sua_mt_theo_mlmt(l);
				break;
			case 3:
				xoa_mt_theo_mlmt(l);
				break;
			case 4:
				tim_mt_theo_mlmt(l);
				break;
			case 5:
				in_dsmt(l,10);
				break;
		}
				
	} while (chon <= 5) ;
	
}
