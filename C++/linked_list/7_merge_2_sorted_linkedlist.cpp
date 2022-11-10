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
        return head;
    }
    node *mergetwosortedlinkedlists(node *head1, node *head2)
    {
        node *result = NULL;
        if (head1 == NULL)
        {
            return head2;
        }
        if (head2 == NULL)
        {
            return head1;
        }
        if (head1->data < head2->data)
        {
            result = head1;  
            result->next = (mergetwosortedlinkedlists(head1->next, head2));
        }
        else
        {
            result = head2;
            result->next = (mergetwosortedlinkedlists(head1, head2->next));
        }
        return result;
    }
    void display(node *head)
    {
        while (head != NULL)
        {
            cout << head->data;
            head = head->next;
        }
    }
};
int main()
{
    linkedlist ll1, ll2,ll3;
    cout<<"enter first linked list"<<endl;
    linkedlist::node *head1 = ll1.takeinput();
    cout<<"enter second linked list"<<endl;
    linkedlist::node *head2 = ll2.takeinput();
    linkedlist :: node*result=ll3.mergetwosortedlinkedlists(head1 ,head2);
    cout<<"sprted linked will be"<<endl;
    ll3.display(result);

}