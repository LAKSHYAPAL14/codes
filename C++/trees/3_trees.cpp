#include <iostream>
#include<queue>
#include <vector>
using namespace std;
template <typename T>
class treenode
{   public:
    T data;
    vector<treenode*>children; // here no need to mention datatype of object because if parent is integer by default childeren will also be integer
    treenode(T data)           // here children act as next in linked list
    {
        this->data=data;
    }
};
treenode<int>*takeinput()  
{
    int rootdata;
    cout<<"enter data"<<endl;
    cin>>rootdata;
    treenode<int>*root=new treenode<int>(rootdata);
    int n;
    cout<<"enter num of children of"<<rootdata<<endl;
    cin>>n;
    for(int i=0 ; i<n ;i++)
    {
        treenode<int>*child=takeinput();
        root->children.push_back(child);
    }
    return root;
}
treenode<int>* takeinputlevelwise()
{
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    treenode<int>*root=new treenode<int>(rootdata);
    queue<treenode<int>*> pendingnodes; //here we use header file for this because we are making pendingnodes queue which is storing address of treenode in queue manner
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        treenode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<" enter num of children "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0 ; i<numchild ; i++)
        {
            int childdata;
            cout<<"enter "<<i<<" th child of"<<front->data<<endl;
            cin>>childdata;
            treenode<int>*child = new treenode<int>(childdata); //we have to create it dynamically because in for memory get lost everytime with iteration in static allocation (treenode<int>child(childdata);)
            front->children.push_back(child); //here we are storing children children of each node in vector
            pendingnodes.push(child);//also we are children of each node in queue

        }
    }
    return root;

}
void printtree(treenode<int> *root)
{
    if (root == NULL)  //it is not a base case . it is just for checking whether tree is empty or not
    {
        return;
    }
    cout << root->data << " ; ";    // this code doesn't require base case below both for loop automatically act as base condition
    for (int i = 0; i < root->children.size(); i++) // this loop is for printing child node of current node  
    {
        cout << root->children[i]->data << " , ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)  //this loop is for to traverse each node of a tree
    {
        printtree(root->children[i]); // except root node this is way to access children node
    }
}
int main()
{
  /*  treenode<int> *root = new treenode<int>(1);
    treenode<int> *node1 = new treenode<int>(2);
    treenode<int> *node2 = new treenode<int>(3); // till now we just created nodes which are not linked
    root->children.push_back(node1);
    root->children.push_back(node2);*/
    treenode<int>*root=takeinputlevelwise();
    printtree(root);
}