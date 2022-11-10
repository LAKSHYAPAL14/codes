#include<iostream>
using namespace std;
class linkedlist
{  public :
    class node
    {
      public:
      int data;
      node*next;
      node (int data)
      {
        this->data=data;
        next=NULL;
      }
    };

    node*takeinput()
    {   cout<<"data for take input\n";
        int data;
        cin>>data;
        node*tail=NULL;
        node*head=NULL;
        while(data!=-1)
        {    
            node*nn=new node(data);
            if (head==NULL)
            { 
                head=nn;
                tail=nn;
            }
            else
            {   tail->next=nn;
                tail=tail->next;
            }
            cout<<"\n enter data again\n";
            cin>>data;
        }
        return head; 
    }
    void insert_after(node*head , int newdata ,int givendata)
    {
        node*nn=new node(newdata);
        
        node*temp=head;
        while(temp->data!=givendata && temp!=NULL)
        {
            temp=temp->next;
        }
            if(temp->data==givendata)
            {
                nn->next=temp->next;
                temp->next=nn;
            }
           else
        cout<<"given data is not present in the linked list";
    }
   
   
    void display( node*head)
    { 
        node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    }
    void rearrange(node*list)
    {
        node *p , *q;
        int temp;
        if(!list)
        return;
        p=list;
        q=list->next;
        while(q)
        {
            temp=p->data;
            p->data=q->data;
            q->data=temp;
            p=q->next;
            q=q?p->next:0;
        }
    }
    
};
int main()
{ linkedlist ll;
   linkedlist :: node*head=ll.takeinput(); //if i remove linkedlist:: then error will come on node and head.because node and head is not defined in main 
  int newdata , givendata;
  /*cout<<"enter new data ";
  cin>>newdata;
  cout<<"enter given data";
  cin>>givendata;
  ll.insert_after(head , newdata ,givendata);*/
 ll. rearrange(head);
  ll.display(head);
}