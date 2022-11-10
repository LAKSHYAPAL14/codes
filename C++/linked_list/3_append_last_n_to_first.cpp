#include <iostream>
using namespace std;
class linkedlist
{
public:
    class node
    {
    public:
        int data;
        node *next;
        node(int data)
        {
            this->data = data;
            next = NULL;
        }
    };

    node *takeinput()
    {
        cout << "data for take input\n";
        int data;
        cin >> data;
        node *tail = NULL;
        node *head = NULL;
        while (data != -1)
        {
            node *nn = new node(data);
            if (head == NULL)
            {
                head = nn;
                tail = nn;
            }
            else
            {
                tail->next = nn;
                tail = tail->next;
            }
            cout << "\n enter data again\n";
            cin >> data;
        }
        return head; // this head is refering to the address of first node of a linked list which have two value data and next.. that's why return type is node* not int *
    }
  node *appendlastntofirst(node *head, int n)    // 1 2 3 4 5 
{                                                //  3
    //Write your code here                       // 3 4 5 1 2 
    if(head==NULL)                                
    {
        return NULL;
    }
    if(n==0)
    {
        return head;
    }
    int count =0;
    node*temp=head;
    while(temp!=NULL) 
    {
        count++;
        temp=temp->next;
    }
    temp=head;
    node *k=head;
    int i=0;
    node *copy;
    while(temp->next!=NULL) 
    {
        if(i ==(count-n-1))       //when i will be at 2
        {
            head=temp->next;  // here head store 3
            copy=temp;    //copy store temp=2
        }
        i++;
        temp=temp->next;
       
    }
    temp->next=k;  //temp will point to 5 and 5 next store address of 1 
    copy->next=NULL;  //copy store 2 and 2 next is null
    return head;
}
    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    linkedlist ll;
    linkedlist ::node *head = ll.takeinput();  // if i remove linkedlist:: then error will come on node and head.because node and head is not defined in main
    int n;
    cout<<"enter element for last to search"<<endl;
    cin>>n;
    head=ll.appendlastntofirst(head ,n );
    ll.display(head);
}