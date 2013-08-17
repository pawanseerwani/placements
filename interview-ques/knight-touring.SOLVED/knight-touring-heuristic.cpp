#include<iostream>
#include<vector>
#include<utility>
#include<cstdlib>
#include <windows.h>

using namespace std ;
int n;
int nop; //no of paths

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
    nop++;
    /*
    cout << endl ;
    cout << "path len :" << path.size() << endl;
    cout << "path :" << endl;
    int count = 1;
    for(vector<pair< int, int> >::iterator it=path.begin(); it!=path.end(); ++it)
    {
        cout << count++ << " "<< it->first<<" " << it->second << " " << endl ;
    }
  *///  exit(0);

}

void KT(bool** visited, int x, int y, vector<pair<int, int> >** moves, vector<pair<int, int> > ans)
{
    visited[x][y] = true;
    ans.push_back(make_pair(x,y)) ;

    if(IsGameOver(visited))
        PrintPath(ans);

    vector<pair<int, int> > possible = moves[x][y] ;
    vector<pair<int, int> > sorted ;
    int min=0;

    for(vector<pair<int, int> > ::iterator it = possible.begin(); it!= possible.end(); ++it )
    {
        if(!visited[it->first][it->second])
        {
            KT(visited, it->first, it->second, moves, ans);
        }
    }
    ans.erase(ans.end()-1);
    visited[x][y] = false;
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

     /*   vector<pair<int, int> > possible = moves[i][j];
     vector<pair<int, int> > ::iterator t, temp ;
    for(vector<pair<int, int> > ::iterator i1 = possible.begin(); i1!=possible.end(); ++i1)
    {
        t = i1;
        for(vector<pair<int, int> > ::iterator j1 = i1+1; j1!=possible.end(); ++j1)
        {
            if(moves[t->first][t->second].size() > moves[j1->first][j1->second].size())
                t = j1;
        }
        temp = i1;
        i1 = t ;
        t = temp ;
    }
*/
        }
    }
  //  for(int i=0;i<n; ++i)
    //    for(int j=0; j<n; ++j)
       // KT(visited, i, j, moves, ans);
        //   KT(visited, 0, 0, moves, ans);

    cout << nop << endl;
    return 0;
}
