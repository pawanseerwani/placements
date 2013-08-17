#include<iostream>
#include<vector>
#include<utility>
#include<cstdlib>
#include <windows.h>
using namespace std ;
int n;
SYSTEMTIME st, lt;

bool IsGameOver(bool** &visited)
{
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
         if(!visited[i][j])
            return false;
    return true;
}
void PrintPath(vector<pair<int, int> > &path)
{
    cout << endl ;
    cout << "path len :" << path.size() << endl;
    cout << "path :" << endl;
    int count = 1;
    for(vector<pair< int, int> >::iterator it=path.begin(); it!=path.end(); ++it)
    {
        cout << ++count << " "<< it->first<<" " << it->second << " " << endl ;
    }
    exit(0);

}

void KT(bool** visited, int x, int y, vector<pair<int, int> >** moves, vector<pair<int, int> > ans)
{
    if(IsGameOver(visited))
        PrintPath(ans);

    vector<pair<int, int> > possible = moves[x][y] ;

    for(vector<pair<int, int> > ::iterator it = possible.begin(); it!= possible.end(); ++it )
    {

        pair<int, int> step = *it;
        if(!visited[step.first][step.second])
        {

            visited[step.first][step.second] = true ;
            ans.push_back(step) ;
            KT(visited, step.first, step.second, moves, ans);
            ans.erase(ans.end()-1);
            visited[step.first][step.second] = false ;
        }

    }

}

void TryInsert(vector<pair<int, int> > &moves, int x, int y)
{
    if( x>=0 && x<n && y>=0 && y<n )
        moves.push_back(make_pair(x,y));
}

int main()
{
    vector<pair<int, int> > **moves ;
    bool **visited ;

   // cin >> n;
   n=5;
    vector<pair<int,int> > ans ;

    moves = new vector<pair<int,int> >*[n] ;
    visited = new bool* [n];
    for(int i=0; i<n; ++i)
    {
        moves[i] = new vector<pair<int,int> >[n] ;
        visited[i] = new bool [n] ;

        for(int j=0; j<n; ++j)
        {
            TryInsert(moves[i][j], i-2, j+1) ;
            TryInsert(moves[i][j], i-2, j-1) ;
            TryInsert(moves[i][j], i-1, j+2) ;
            TryInsert(moves[i][j], i-1, j-2) ;
            TryInsert(moves[i][j], i+2, j+1) ;
            TryInsert(moves[i][j], i+2, j-1) ;
            TryInsert(moves[i][j], i+1, j+2) ;
            TryInsert(moves[i][j], i+1, j-2) ;
        }
    }

    visited[0][0] = true ;
    KT(visited, 0, 0, moves, ans);
    return 0;
}
