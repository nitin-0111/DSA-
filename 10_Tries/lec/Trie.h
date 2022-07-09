#include "TrieNode.h"
#include <string>
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
    void RemoveWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        // Small Calulation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            //Word not found
            return;
        }
        RemoveWord(child, word.substr(1));
        // Remove child if it is useless
        //   we are returning from end last kye element h child or second last element h root 
                                        // basicly we are retruning from the bottom to top in recursion humane last element kye is 
                                        // is terminal ko false kar de or ab ye kam kar rhe h        
       if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    //remove fuction for user
    void RemoveWord(string word)
    {
        RemoveWord(root, word);
    }
};