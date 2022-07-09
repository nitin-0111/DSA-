#include<bits/stdc++.h>

using namespace std;

///https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
 #define ll long long
#define loop(i,a,n) for(int i=a;i<n;i++)

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int freq;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal=false;
        freq=1;
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
            root->children[index]->freq+=1;
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


    void print_unique(TrieNode * root,string word)
    {
        // find index 
        int index=word[0]-'a';
        // its child node
        TrieNode * child=root->children[index];
        // print it 
        cout<<child->data;

        // and check its freq is it 1?  if yes stop 
        if(child->freq==1)
        {
            return ;
        }
        print_unique(child,word.substr(1));
    }
    // for user 
    void print_unique(string word)
    {
        print_unique(root,word);
    }




   void shortest_unique(string s[],int n)
   {
       for(int i=0;i<n;i++)
       {
           insertWord(s[i]);
       }

       for(int i=0;i<n;i++)
       {
           print_unique(s[i]);
           cout<<endl;
       }

   }
};
 
int main ()
{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);
string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr)/sizeof(arr[0]);
    Trie a;
    a.shortest_unique(arr,n);

return 0;}
 /*INPUT: 



OUTPUT:

*/