#include<bits/stdc++.h>
using namespace std;
// #include<TrieNode.h>


 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    // INsert fuction
    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertWord(root, word);
    }
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        //    bool ans;
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return search(child, word.substr(1));
        
    }

    bool search(string word)
    {
        return search(root, word);
    }
    int advsearch(TrieNode * root,string word)
    {
        static int k=0;
        if(root->isTerminal)
        {
            return 0;
        }
        int index=word[0]-'a';
        TrieNode * child;
        if( root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else 
        {
            return -1;
        }
        return advsearch(child,word.substr(1))+1;
    }
   
     void  workbreak(string a)
    {
        if(a.size()==0)
        {
            cout<<"yes"<<endl;
            return ;
        }
        
        int k=advsearch(this->root,a);
        if(k>0)
        {
            cout<<k<<"   ";
           workbreak(a.substr(k));
        }
    }
    
};

 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s[]={"i","like","sam","sung","samsung","mobile","ice","cream",
           "icecream","man","go","mango"};
string a;
cin>>a;
int n=sizeof(s)/sizeof(s[0]);
Trie m;
for(int i=0;i<n;i++)
{
    m.insertWord(s[i]);
}
m.workbreak(a);


return 0;}
 /*INPUT: 



OUTPUT:

*/