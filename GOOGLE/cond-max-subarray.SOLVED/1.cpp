#include<iostream>
using namespace std;

int main()
{
	int n,i,t1 = 0,t2 = 0,max = 0, skip = 0;
	cin >> n;
	int a[n];
	
	for(i=0; i<n; ++i)
		cin >> a[i] ;
	
	for(i=0; i<n; ++i)
	{
		if (a[i] < 0 && skip == 0 )
		{
			t2 = t1; 
			t1 += a[i];
			skip = 1;
		}
		else
		{
			t1 += a[i];
			t2 = t1;
		}

		if(max < t2 && t1 <= t2)
			max = t2;
		else if(max < t1 && t2 <= t1)
			max = t1;
		
		if(t2 < 0)
		{
			t1 = t2 = 0;
			skip = 0;
		}

		cout << "i:" << i << " max:"<< max << " t1:" << t1 <<" t2:" << t2 << endl;
		
	}
	cout << max << endl;
	return 0;
}

