#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

double mini(int n, double *x){//求最小值 
	double min = x[0];
	for(int i = 1; i < n; i++)
	{
		if(min > x[i]) min = x[i];
	}
	return min;
}
double maxi(int n, double *x){//求最大值 
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
	double *x = new double[n];//注意fin>>n要写在申请动态数组前面 


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

	
	
	double bar_len = (max_all-min_all)/(n-1);//计算子区间长度(注意类型定义要为double，不能为整形） 
	for(int i = 0; i < n; i++)
	{
		int index = (int)((x[i]-min_all)/bar_len);
//		cout << index << " ";
		count[index]++;
		if(x[i]<low[index]) low[index] = x[i];
		if(x[i]>high[index]) high[index] = x[i];
	}//将n-2个数字放入n-1个桶中
	
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
