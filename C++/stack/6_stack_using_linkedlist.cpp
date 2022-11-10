#include <iostream>
#include <climits>
using namespace std;
template <typename T> // we have to use this line for every class where we use Template variable
class node
{
public:
    T data;
    node<T> *next;
    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class stack
{
    node<T> *head;
    int size; // number of element present in stack
public:
    stack()
    { // no size require in constructore because there is no concern of size in linked list
        head = NULL;  //right now our stack is empty
        size = 0;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size == 0;
    }
    void push(T element)   //head will point to topmost element
    {
        node<T> *newnode = new node<T>(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    T pop()
    {
        if (isempty())
        {
            cout << "stack is empty ";
            return 0;
        }
        T ans = head->data;
        node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    T top()
    {
        if (isempty())
        {
            return 0;
        }
        return head->data;
    }
};
int main()
{
    stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getsize() << endl;
    cout << s.isempty() << endl;
}