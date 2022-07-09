#include<iostream>
#include<queue>

using namespace std;

class huffmanNode{
    public:
     char data;
     int freq;
     huffmanNode *left;
     huffmanNode *right;

     huffmanNode( char c, int freq)
     {
         data=c;
         this->freq=freq;
         left=right=nullptr;
     }
};

class compare{
    public:
    bool operator()(huffmanNode *a,huffmanNode *b){
        return a->freq>b->freq;
    }
};