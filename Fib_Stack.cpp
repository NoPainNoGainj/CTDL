#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

int tinhFib(int n);
long tinhgt(int n);
int main()
{
	int n;
	cout << "Nhap n = "; cin >> n;
	cout << n << "!= " << tinhgt(n) << endl;
	cout << "Fib(" << n << ")=" << tinhFib(n);
	return 0;
}

long tinhgt(int n)
{
	stack<long> s;
	long gt;
	s.push(1);
	for(int i =2;i <= n;i++)
		{
			gt = s.top(); s.pop();
			gt *= i;
			s.push(gt);
		}
	return (s.top());
}

int tinhFib(int n)
{
	stack<int> s;
	int a, b, c;
	
	s.push(1);
	s.push(1);
	
	for(int i = 3;i <=n;i++)
	{
		a = s.top(); s.pop();
		b = s.top(); s.pop();
		c= a+b;
		
		
		s.push(c);
		s.push(b);
	}
	s.pop(); // pop Fib(n-1)
	return s.top(); // tra ve Fib(n) dau stack
}
