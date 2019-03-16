#include<iostream>
using namespace std;

struct Node
{
	long data;
	Node *next;
};
long n,m;
Node *head, *r, *p;

int main()
{
	long i,j,k,l;
	cin >> n >> m;
	head = new Node;
	head->data = 1;
	head->next = NULL;
	r = head;
	for(int i = 2; i <= n; i++)
	{
		p = new Node;
		p->data = i;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	r->next = head;
	r = head;
	for(int i = 1; i <= n; i++)
	{
		if(m==1) 
		{
		for(j=1;j<=n;j++)
		{
			cout << r->data << " ";
			r=r->next;
		}
		return 0;
		}
		for(j = 1; j <= m-2; j++) r=r->next;
		cout << r->next->data << " ";
		r->next = r->next->next;
		r = r->next;
	}
	return 0;
} 
