#include<iostream>
using namespace std;

class Node
{
    public:
    Node * child[26];
    bool isEndOfWord;

    Node()
    {
        for(int i=0;i<26;i++)
        child[i]=NULL;

        isEndOfWord=false;
    }

};
Node* root;
void insert(char* a)
{
    Node*  cur=root;

    int index=0;

    while(a[index]!='\0')
    {

        if(cur->child[a[index]-'a']==NULL)
          cur->child[a[index]-'a']=new Node();

          cur=cur->child[a[index]-'a'];
          index++;
    }

    cur->isEndOfWord=true;


}

void search(char* a)
{
    Node*  cur=root;

    int index=0;

    while(a[index]!='\0')
    {

        if(cur->child[a[index]-'a']==NULL){
            cout<<"Not found";
            return;
        }

          cur=cur->child[a[index]-'a'];
          index++;
    }

    if(cur->isEndOfWord==false)
    {
        cout<<"Not found";
            return;
    }

    cout<<"Happy found";
            return;


}

int main(int argc, char const *argv[])
{
    char str[10]={'h','e','l','l','o','\0'};
    root=new Node();
    insert(str);
    char str1[10]={'h','e','l','l','o','t','\0'};
    search(str1);
    //char * ptr = str;
   // cout<<&ptr[2]<<endl;
    return 0;
}
