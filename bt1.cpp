#include<bits/stdc++.h>
using namespace std;
typedef int Data;
typedef struct NODE{
	Data Info;
	struct NODE *pNext;
};
typedef struct SLIST 
{
	NODE* pHead;
	NODE* pTail;
};
NODE* GetNode(Data x)
{
	NODE* p;
	p = new NODE;
	if(p==NULL)
	{
		cout<<"Khong du bo nho";
		return NULL;
	}
	p->Info = x;
	p->pNext = NULL;
	return p;
}
void Inist(SLIST &l)
{
	l.pHead = l.pTail = NULL;
}
void AddFrist(SLIST &l, NODE* new_ele)
{
	if(l.pHead == NULL)
		l.pHead = l.pTail = new_ele;
	else{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}
NODE* InsertHead(SLIST &l, Data x)
{
	NODE* new_ele = GetNode(x);
	if(new_ele == NULL)
		return NULL;
	AddFrist(l,new_ele);
	return new_ele;
}
void AddTail(SLIST &l, NODE* new_ele)
{
	if(l.pHead==NULL)
		l.pHead = l.pTail = new_ele;
	else
		l.pTail = l.pTail->pNext = new_ele;
}
NODE* InsertTail(SLIST &l, Data x)
{
	NODE* new_ele = GetNode(x);
	if(new_ele == NULL)
		return NULL;
	AddTail(l,new_ele);
	return new_ele;
}
void AddAfter(SLIST &l, NODE *q, NODE* new_ele)
{
	if(q!=NULL)
	{
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
		if(q == l.pTail)
			l.pTail = new_ele;
	}
	else 
		AddFrist(l,new_ele);
}
NODE *Search(SLIST l, Data x)
{
	NODE *p;
	p = l.pHead;
	while((p!=NULL)&&(p->Info!=x))
		p = p->pNext;
	return p;
}
NODE* PickHead(SLIST &l)
{
	NODE*p = NULL;
	if(l.pHead!=NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		p->pNext = NULL;
		if(l.pHead == NULL)
			l.pTail = NULL;
	}
	return p;
}
Data RemoveHead(SLIST &l)
{
	if(l.pHead == NULL)
		return -1;
	NODE* p = PickHead(l);
	Data x = p->Info;
	delete p;
	return x;
}
NODE* PickAfter(SLIST &l, NODE *q)
{
	NODE *p;
	if(q!=NULL)
	{
		p = q->pNext;
		if(p!=NULL){
			if(p==l.pTail)
				l.pTail=q;
			q->pNext = p->pNext;
			p->pNext = NULL;
		}
	}
	else p=PickHead(l);
	return p;
}
NODE* PickNode(SLIST &l,Data k)
{
	NODE *p=l.pHead;
	NODE *q=NULL;
	while((p!=NULL)&&(p->Info!=k))
	{
		q=p;
		p=p->pNext;
	}
	if(p==NULL)
		return NULL;
	return PickAfter(l,q);
}
void Nhap(SLIST &l, int n)
{
	Inist(l);
	cout<<"Nhap "<<n<<"gia tri: ";
	for(int i=0;i<n;i++)
	{
		Data x;
		cin>>x;
		InsertTail(l,x);
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
bool IsPrime(Data x)
{
	if(x<2)
		return false;
	for(int i=2;i<= sqrt(x);i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}
void XuatSoNguyenTo(SLIST l)
{
	NODE *p = l.pHead;
	bool foundPrime = false;
	while(p!=NULL)
	{
		if(IsPrime(p->Info))
		{
			cout<<p->Info<<" ";
			foundPrime = true;
		}
		p=p->pNext;
	}
	if(!foundPrime)
	{
		cout<<"Khong co so nguyen to torng danh sach.";
	}else{
		cout<<endl;
	}
}
void RemoveElement(SLIST &l, Data x) {
    NODE *p = l.pHead, *prev = NULL;
    
    // If the element to remove is the head
    if (p != NULL && p->Info == x) {
        l.pHead = p->pNext;
        delete p;
        cout << "Element " << x << " removed from the list.\n";
        return;
    }
    while (p != NULL && p->Info != x) {
        prev = p;
        p = p->pNext;
    }

    // If element was not found
    if (p == NULL) {
        cout << "Element " << x << " not found in the list.\n";
        return;
    }

    // Unlink the node from the list
    prev->pNext = p->pNext;
    delete p;
    cout << "Element " << x << " removed from the list.\n";
}
int main()
{
	SLIST l;
    Inist(l);

    int chon;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Insert Head\n";
        cout << "2. Insert Tail\n";
        cout << "3. Search Element\n";
        cout << "4. Remove Head\n";
        cout << "5. Xuat\n";
        cout << "6. Nhap\n";
        cout << "7. Xuat danh sach so nguyen to\n";
        cout << "8. Xoa phan tu da chon\n";
        cout << "0. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> chon;

        switch (chon) {
            case 1: {
            	Data x;
                cout << "Enter value to insert at head: ";
                cin >> x;
                InsertHead(l, x);
                break;
            }
            case 2: {
                Data x;
                cout << "Enter value to insert at tail: ";
                cin >> x;
                InsertTail(l, x);
                break;
            }
            case 3: {
                Data x;
                cout << "Enter value to search: ";
                cin >> x;
                NODE *found = Search(l, x);
                if (found)
                    cout << "Element " << x << " found in the list.\n";
                else
                    cout << "Element " << x << " not found.\n";
                break;
            }
            case 4: {
                Data removed = RemoveHead(l);
                if (removed != -1)
                    cout << "Removed head element: " << removed << endl;
                else
                    cout << "List is empty, nothing to remove.\n";
                break;
            }
            case 5: {
                cout << "Danh sach da nhap: ";
                Xuat(l);
                break;
            }
            case 6: {
                int n;
                cout << "Nhap so phan tu: ";
                cin >> n;
                Nhap(l, n);
                break;
            }
            case 7: {
            	cout<<"Danh sach so nguyen to gom: ";
            	XuatSoNguyenTo(l);
				break;
			}
			case 8: {
                Data x;
                cout << "Enter value to remove: ";
                cin >> x;
                RemoveElement(l, x);
                break;
            }
            case 0: {
                cout << "Thoat chuong trinh\n";
                break;
            }
            default:
                cout << "Khong tim thay thao tac vui long nhap lai.\n";
        }
    } while (chon != 7);

    return 0;
}
