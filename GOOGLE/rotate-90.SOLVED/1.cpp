//QUESTION : Rotate a matrix of integers by 90 degrees
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,i,j;
	cin >> n;
	//vector<int> mat[n];
	int mat[n][n] ;
	for( i=0; i<n; ++i)
		for( j=0; j<n; ++j)
			cin >> mat[i][j] ;

	for( i=0; i<n/2; ++i)
	{
		for( j=i; j<n-i-1; ++j)
		{
			int lt, rt, lb, rb;
			lt = mat[i][j] ;
			rt = mat[j][n-1-i] ;
			lb = mat[n-1-j][i] ;
			rb = mat[n-1-i][n-1-j] ;

			mat[i][j] = rt ;
			mat[j][n-1-i] = rb ; 
			mat[n-1-j][i] = lt ;
			mat[n-1-i][n-1-j] = lb ; 
		}
	}

	for( i=0; i<n; ++i)
	{
		for( j=0; j<n; ++j)
			cout << mat[i][j] <<" ";
		cout << endl ;
	}

	return 0 ;
}
