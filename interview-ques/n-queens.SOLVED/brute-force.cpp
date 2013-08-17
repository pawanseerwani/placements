#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;

int now =0; //nop : no of way

#define minimum(x, y) (x>y ? y :x )

void PrintPath(vector<pair<int, int> > ans)
{
    cout << endl ;
    cout << "path len:" << ans.size() << endl;
    cout <<" path : "<< endl ;
    for(vector<pair<int, int> >::iterator it= ans.begin(); it!=ans.end(); ++it)
    {
        cout<< it->first <<" "<< it->second << endl ;
    }
}
bool clashing(vector<pair<int, int> >ans, int n, int x, int y)
{
    for(vector<pair<int, int> >::iterator it = ans.begin(); it!= ans.end(); ++it)
    {
        int mini = minimum(it->first, it->second);
        int i = it->first - mini ;
        int j = it->second - mini ;

        for(;i<n && j< n; i++, j++)
        {
            if(i==x && y==j)
                return true;
        }
        i = it->first ;
        j = it->second ;
        for(;i>=0 && j<n; --i, ++j);

        for(;i<n && j>=0; ++i, --j)
            if(i==x && j==y)
                return true;

        return false;
    }
}

void NQ(bool **visited, int n, vector<pair<int, int> > &ans, int x, int y )
{
    if(visited[0][x] || visited[1][y]) return;
    if(clashing(ans, n, x, y)) return ;

    visited[0][x] = visited[1][y] = true ;
    ans.push_back(make_pair(x,y)) ;

    if(ans.size() == n)
    {
        now++;
       // PrintPath(ans);
        //exit(0);
        return ;
    }

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            NQ(visited, n, ans, i, j);

    ans.erase(ans.end()-1);
    visited[0][x] = visited[1][y] = false ;

}

int main()
{
    int n;

    //cin >> n;
    n= 5;
    vector< pair<int, int> > ans;
    bool **visited ;
    visited = new bool*[2];

    for(int i=0; i<2; ++i)
    {
        visited[i] = new bool [n];
        memset(visited[i], 0, n*sizeof(visited[0][0])) ;
    }



    NQ(visited, n, ans, 0, 1);
    cout << now << endl ;
}
