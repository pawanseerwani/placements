// Ques : find maximum sum subarray (condition-you may skip at max one element)
#include<iostream>
using namespace std;

#define maximum(a,b) (a>b?a:b)
int main()
{
	int n,i,t1 = 0,t2 = 0,max = 0, skip = 0;
	cin >> n;
	int a[n];
	
	for(i=0; i<n; ++i)
		cin >> a[i] ;
	
	for(i=0; i<n; ++i)
	{
	  if(!skip)
		{
			if(a[i] > 0)
				t1 +=a[i];
			else
				skip = 1;
		}
		else
		{
			if(a[i] > 0)
			{
				t1 += a[i] ;
				t2 += a[i];
			}
			else
			{
				t1 = t2 ;
				t2 = 0;
			}

		}

		max = maximum(max, t1) ;

//		cout << "i:" << i << " max:"<< max << " t1:" << t1 <<" t2:" << t2 << endl;
		
	}
	cout << max << endl;
	return 0;
}

