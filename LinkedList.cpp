#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int d)
        {
            data=d;
            next=NULL;
            prev=NULL;
        }
};
Node* head=NULL;
Node* tail=NULL;
int count=0;
void insertFront(int item)
{
    
    Node * temp=new Node(item);

    temp->next=head->next;
    temp->prev=head;
    head->next->prev=temp;
    head->next=temp;
    count++;
    
}

void insertRear(int item)
{
    
    Node * temp=new Node(item);

    temp->prev=tail->prev;
    temp->next=tail;
    tail->prev->next=temp;
    tail->prev=temp;
    count++;
    
}

void insertAfter(Node* cur,int item)
{
    
    Node * temp=new Node(item);

   temp->next=cur->next;
   cur->next->prev=temp;
   temp->prev=cur;
   cur->next=temp;

    count++;
    
}

void removeFront()
{
    if(count<=0)
    return;

    Node* cur=head->next;
    head=head->next;
    head->prev=NULL;
    cout<<"Deleted : "<<cur->data<<endl;
    delete(cur);
    count--;

}

void removeRear()
{
    if(count<=0)
    return;

    Node* cur=tail->prev;
    tail=tail->prev;
    tail->next=NULL;
    cout<<"Deleted : "<<cur->data<<endl;
    delete(cur);
    count--;

}

void display()
{
    if(count<=0){
    cout<<"List is empty\n";
    return;
    }
    Node* cur=head->next;
   while(cur->next!=NULL)
   {
       cout<<cur->data<<endl;
       cur=cur->next;
   }
}

void displayReverse()
{
    if(count<=0){
    cout<<"List is empty\n";
    return;
    }
    Node* cur=tail->prev;
   while(cur->prev!=NULL)
   {
       cout<<cur->data<<endl;
       cur=cur->prev;
   }
}

int main(int argc, char const *argv[])
{
    head = new Node(0);
    tail=new Node(0);
    head->next=tail;
    tail->prev=head;
    for(int i=10;i<=100;i+=10)
    //insertFront(i);
    insertRear(i);


    insertAfter(tail->prev->prev,500);
    //for(int i=0;i<10;i++)
    //removeFront();
    //removeRear();
    cout<<"\nDisplay"<<endl;
    display();
    cout<<"Display Reverse"<<"\t count :"<<count<<endl;
    displayReverse();

    Node** hm;
    hm = new Node* [10];
    hm[0]=head;
    cout<<head->next->next->data<<endl;
    cout<<hm[0]->next->next->next->data<<endl;

    return 0;
}

