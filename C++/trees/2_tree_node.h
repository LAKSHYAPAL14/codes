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