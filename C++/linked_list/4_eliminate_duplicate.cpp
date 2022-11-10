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
     node *removeduplicates(node *head)
    {                          //when duplicates arrive right most element gets always return 
        if (head == NULL || head->next == NULL)
            return head;
        head->next = removeduplicates(head->next);
        if (head->data == head->next->data)
            return head->next;
        else
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
    head=ll.removeduplicates(head);
}