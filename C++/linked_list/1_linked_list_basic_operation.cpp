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
    node *deletenode(node *head, int pos) //  3 4 5 2 6 1 9 -1  input
    {                                     //  3                 pos
        if (head == NULL)                 //  3 4 5 6 1 9       output
        {
            return NULL;
        }
        if (pos == 0)
        {
            head = head->next;
            return head;
        }
        int count = 0;
        node *temp = head;
        while (temp != NULL && count < pos - 1) // at the end temp will be at 5 and count at 2nd index
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL && temp->next != NULL)
        {
            node *a = temp->next;
            node *b = a->next;
            temp->next = b;
            return head;
        }
        if (pos >= count)
        {
            return head;
        }
    }
    node *deletenodeRec(node *head, int pos) // delete node recursively
    {
        if (head == NULL)
        {
            return head;
        }
        if (pos == 0)
        {
            head = head->next;
            return head;
        }
        node *a = deletenodeRec(head->next, pos - 1);
        if (pos == 1)
        {
            head->next = a;
        }
        return head;
    }

    void printlinkedlist(node *head) // printing linked list with recursion
    {
        if (head != NULL)
        {
            return;
        }
        else
        {
            cout << head->data << " ";
            printlinkedlist(head->next);
        }
    }

    void printreverseLL(node *head) // printing reverse linked list
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            printreverseLL(head->next);
            cout << head->data << " ";
        }
    }
    // first method
    node *reverselinkedlist(node *head)
    {
        node *temp = head;
        int i = 0;
        int a[100];
        while (temp != NULL)
        {
            a[i] = temp->data;
            temp = temp->next;
            i++;
        }
        i--;
        temp = head;
        while (temp != head)
        {
            temp->data = a[i];
            i--;
            temp = temp->next;
        }
        return head;
    }
    // second method
    node *reverselinkedlistrec(node *head)                 // reverse linkedlist recursively
    {                                                      // time complexity is O(n^2)
        if (head == NULL || head->next == NULL)            //  1 2 3 4 5  head=1 ,smallans=5 4 3 2 1
        {                                                  //    2 3 4 5  head=2 ,smallans=5 4 3 2
            return head;                                   //      3 4 5  head=3 ,smallans=5 4 3
        }                                                  //        4 5  head=4 ,smallans=5 4
        node *smallans = reverselinkedlistrec(head->next); //          5  head=5 ,smallans=5              (flow bottom to up)
        node *temp = smallans;                             // when base condition reach head will return which is 5 and store in smallans.now it will store in temp temp->next is null so it will not enter in the loop and we put head which is 4 in this case
        while (temp->next != NULL)
        { // ahead of 5 and null ahead 4 like 5 4 NULL and return smallans (5 4) ...in next case 5 4 store in temp we traverse till last node and put head(3) ahead of 4 and null ahead of 3 like 5 4 3 NULL
            temp = temp->next;
        }
        temp->next = head;
        head->next = NULL;
        return smallans;
    }
    // third method
    class pair
    { // time complexity O👎
    public:
        node *head;
        node *tail;
    };
    pair reverselinkedlist_2(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            pair ans;
            ans.head = head;
            ans.tail = head;
            return ans;
        }
        pair smallans = reverselinkedlist_2(head->next);
        smallans.tail->next = head;
        head->next = NULL;
        pair ans;
        ans.head = smallans.head;
        ans.tail = head;
        return ans;
    }
    node *reverselinkedlist_better(node *head)
    {
        return reverselinkedlist_2(head).head;
    }
    // fourth method
    node *reversedlinkedlist_3(node *head) // 1 2 3 4 5 supposte recursion done it's work so 1 [5 4 3 2] to place 1 beyond 2 we get easily get 2 by using head->next which is 1->next
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *smallans = reverselinkedlistrec(head->next);
        node *tail = head->next;
        tail->next = head;
        head->next = NULL;
        return smallans;
    }
    node *midpoint(node *head) // 1 2 3 4 5
    {                          // 3
        if (head == NULL)      // 1 2 3 4
        {                      // 2
            return head;
        }

        node *slow = head;
        node *fast = head->next; // to get output 2 when we enter even no of element that why we increase fast step ahead of slow
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    linkedlist ::node *head = ll.takeinput(); // if i remove linkedlist:: then error will come on node and head.because node and head is not defined in main
   /* head = ll.reverselinkedlistrec(head);
    ll.display(head);
    head = ll.reverselinkedlist_better(head);
    ll.display(head);
    head = ll.reversedlinkedlist_3(head);
    ll.display(head);*/
    head=ll.removeduplicates(head);
    ll.display(head);
}