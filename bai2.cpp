#include<iostream>
using namespace std;
struct SinhVien
{
	int masv;
    string ten;
    string lop;
    int namsinh;
};uer
void nhap( SinhVien &DS)
{
    cout<<"Nhap masv: ";
    cin>>DS.masv;
    cin.ignore();
    cout<<"Nhap ten: ";
    getline(cin,DS.ten);
    cout<<"Nhap lop: ";
    getline(cin,DS.lop);
    cout<<"Nhap nam sinh: ";
    cin>>DS.namsinh;
}
void swap(int &x, int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}
void QuickSort(SinhVien DS[], int l, int r)
{
    if(l >= r)
    {
        return ;
    }
    int x=DS[(l+r)/2].masv;
    int i=l; int j=r;
    while(i<=j)
    {
        while(DS[i].masv < x)
        {
            i++;
        }
        while(DS[j].masv > x)
        {
            j--;
        }
        if(i <= j)
        {
            swap(DS[i],DS[j]);
            i++;
            j++;
        }
    }
    QuickSort(DS, l, j);
    QuickSort(DS, i, r);
}
int main()
{
    int n;
    cout << "so luong sinh vien: ";
    cin>>n;
    SinhVien DS[n];
    for(int i=0;i<n;i++)
    {
        nhap(DS[i]);
    }
    cout << "sap xep theo tang dan: " << endl;
    QuickSort(DS,0,n-1);
    for (int i = 0; i < n; i++) {
        cout << "Ma SV: " << DS[i].masv << ", Ten: " << DS[i].ten
             << ", Lop: " << DS[i].lop << ", Nam sinh: " << DS[i].namsinh << endl;
    }
    return 0;
}
