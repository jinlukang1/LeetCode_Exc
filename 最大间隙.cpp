#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

double mini(int n, double *x){//����Сֵ 
	double min = x[0];
	for(int i = 1; i < n; i++)
	{
		if(min > x[i]) min = x[i];
	}
	return min;
}
double maxi(int n, double *x){//�����ֵ 
	double max = x[0];
	for(int i = 1; i < n; i++)
	{
		if(max < x[i]) max = x[i];
	}
	return max;
}

int main()
{
	int n = 0;
	fin >> n;
	double *x = new double[n];//ע��fin>>nҪд�����붯̬����ǰ�� 


//	cout << n; 
	for(int i = 0; i < n; i++) 
	{
	fin >> x[i];
//	cout << x[i] << " ";
	}
	double max_all = 0, min_all = 0;
	

	
	max_all = maxi(n, x);
	min_all = mini(n, x);
	
//	cout << max_all << " ";
//	cout << min_all << " "; 
	
	int *count = new int[n]; 
	double *low = new double[n];
	double *high = new double[n];
	
	for(int i = 0; i < n; i++)
	{
		count[i] = 0;
		low[i] = max_all;
		high[i] = min_all;
	}

	
	
	double bar_len = (max_all-min_all)/(n-1);//���������䳤��(ע�����Ͷ���ҪΪdouble������Ϊ���Σ� 
	for(int i = 0; i < n; i++)
	{
		int index = (int)((x[i]-min_all)/bar_len);
//		cout << index << " ";
		count[index]++;
		if(x[i]<low[index]) low[index] = x[i];
		if(x[i]>high[index]) high[index] = x[i];
	}//��n-2�����ַ���n-1��Ͱ��
	
//	for(int i=0; i < n; i++) cout << endl << count[i] << " " << low[i] << " " << high[i] << endl;
	
	double temp = 0, max_distance = 0,left = high[0];
	for(int i = 1; i < n-1; i++)
	{
		if(count[i])
		{
			temp = low[i] - left;
			if(max_distance < temp) max_distance = temp;
			left = high[i];
		}
	 }
	fout << max_distance;

	return 0;
} 
