#include<iostream>
#include<vector>
#include<utility>
using namespace std;

struct trie_node
{
    char data ;
    bool valid;
    int frequency;
    struct trie_node* children[26];
};

vector<string> mapp ;
typedef struct trie_node tn_t ;

struct trie_node *root = new struct trie_node ;



void Dict2Trie(vector<pair<string, int> > dict)
{
    tn_t *curr , *temp;
    for(int i=0; i<dict.size(); ++i)
    {
        curr = root ;
        string word = dict[i].first ;
        int frequency = dict[i].second ;
        for(int j=0; j<word.length(); ++j)
        {
            int index = word[j] - 'a' ;
            temp = curr->children[index] ;
            if(!temp)
            {
                //cout << "new node " << endl ;
                temp = new tn_t ;
                temp->data = index +'a' ;
                temp -> valid = false ;
                temp->frequency = 0 ;
                for(int k=0; k<26; ++k)
                    temp->children[k] = NULL ;

                curr->children[index] = temp ;
            }
            curr = curr->children[index] ;
        }
        temp->valid = 1;
        temp->frequency = frequency ;
    }
}

void PrintTrie(tn_t *root, string str)
{
    if(!root)
        return ;
    if(root && root->valid)
    {
        cout << (str+root->data).substr(1) << endl;
    }
        for(int i=0;i<26; ++i)
        {
            PrintTrie(root->children[i],str+root->data);
        }
}

void AutoSuggest(tn_t *root, string num, vector<pair<string, int> > &ans, string str)
{
    if(!root)
        return  ;
    if(num.length()==0)
    {
        if(root->valid)
        {
               //ans.first =  ans.first.substr(0,ans.first.length()-1)+root->data ;
                //ans.second = root->frequency ;
                ans.push_back(make_pair(str+root->data,root->frequency)) ;
                    return;
        }
    }


    int index = num[0] - '0' ;
    string possible = mapp[index] ;
    for(int i=0; i< possible.length(); ++i)
    {

        index = possible[i] - 'a' ;

        AutoSuggest(root->children[index],num.substr(1), ans, str+root->data);
    }

}

int main()
{
    mapp.push_back("");
    mapp.push_back("");
    mapp.push_back("abc");
    mapp.push_back("def");
    mapp.push_back("ghi");
    mapp.push_back("jkl");
    mapp.push_back("mno");
    mapp.push_back("pqrs");
    mapp.push_back("tuv");
    mapp.push_back("wxyz");
    root->data = ' ';
    root->frequency = 0;
    root->valid = 0;
    for(int i=0; i<26; ++i)
        root->children[i] = NULL ;
    vector<pair<string, int> > dict ;
    dict.push_back(make_pair("came", 100));
    dict.push_back(make_pair("band",80));
    dict.push_back(make_pair("cane",50));
//  dict.push_back(make_pair("a",50));
// dict.push_back(make_pair("b",100));
    Dict2Trie(dict) ;

//    PrintTrie(root, "");

    vector<pair<string, int> > ans;
    AutoSuggest(root, "2263", ans,"");
    for(int i=0; i<ans.size();++i)
        cout << ans[i].first << " " << ans[i].second << endl ;

    return 0;
}
