// Print all permutations and subset of a string
#include<iostream>
using namespace std;

void permute(string a, string str)
{
	if(str.length() == 1)
	{
		cout << a << str << endl;
	}

	for(int i=0; i<str.length(); ++i)
	{
		string add = a + str[i]; 
		char temp = str[0]; 
		str[0] = str[i];
		str[i] = temp;

		string b = str.substr(1);
		permute(add, b) ;
	}
}

void subset(string a, string  b)
{
//	if( b.length() == 0)
	//	return ;

	for(int i=0; i<b.length(); ++i)
	{
		cout <<  a << b[i] <<endl;
		subset(a+b[i], b.substr(i+1)) ;
	}
}
int main()
{
	string str = "123" ;
	cout << "subsets :" << endl ;
	subset("",str);
	cout << endl ;
	cout << "permutations :"<< endl ;
	permute("", str);
	return 0;
}

