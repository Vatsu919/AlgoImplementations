#include<bits/stdc++.h>

using namespace std;

struct Trie{
    map<char,Trie*> children;
    bool isEnd;

    Trie():isEnd(false){}

};

void insert(Trie* root,string s)
{
    Trie* temp=root;
    for(int i=0;i<s.length();i++)
    {
        if(temp->children[s[i]]==NULL)
        {
            temp->children[s[i]]=new Trie();
        }
        temp=temp->children[s[i]];
    }
    temp->isEnd=true;
}

bool search(Trie* root,string s)
{
    Trie* temp=root;

    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if(temp->children[c]==NULL)
        {
            return false;
        }
        temp=temp->children[c];
    }
    return temp->isEnd;
}

void printAllWordsWithGivenPrefix(string prefix,string suffix,Trie* temp)
{
    if(temp->isEnd)
    {
        cout<<prefix+suffix<<endl;
    }
    for(auto it=temp->children.begin();it!=temp->children.end();it++)
    {
        if(it->second)
        {
            printAllWordsWithGivenPrefix(prefix,suffix+it->first,it->second);
        }
    }
}
//Prints all words with given prefix
void printAll(Trie* root,string pre)
{
    Trie *temp=root;

    for(int i=0;i<pre.length();i++)
    {
        char c=pre[i];
        if(temp->children[c]==NULL)
        {
            return ;
        }
        temp=temp->children[c];
    }
    
   
    printAllWordsWithGivenPrefix(pre,"",temp);
}

int main()
{
   Trie* root = new Trie();

   insert(root,"hello");
   insert(root,"hell");
   insert(root,"he");
   insert(root,"gello");
   insert(root,"hgle");
   printAll(root,"h");

    
}