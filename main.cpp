#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
int count = 0;

double solve(int n){//�ݹ�Ľ��� 
	count++;//������һ�� 
	for(int i = 2; i <= n/2; i++)
	{
		if(n%i==0) solve(i);// i -> n/iҲ�ǿ��Ե� 
	}
}

int main()
{
	int n = 0;
	fin >> n;
	solve(n);
	fout << count;

	return 0;
} 
