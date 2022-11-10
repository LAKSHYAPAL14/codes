#include<iostream>
using namespace std;
#include<stack>
bool isbalanced(string s) 
{
stack <char>st;
    for(int i=0 ;i<s.length() ;i++)
    {
        char ch=s[i];
       if(ch=='(' || ch=='[' || ch=='{')
       {
           st.push(ch);
       }
      else if( ch==')' && st.top()==')' )
      {
          st.pop();
      }
        else if( ch==']' && st.top()==']' )
      {
          st.pop();
      }
        else if( ch=='}' && st.top()=='}' )
      {
          st.pop();
      }
      else{
        return false;
      }
        
    }
     return true;
}
int main()
{   cout<<"enter string\n ";
    string s;
    cin>>s;
    bool balanced=isbalanced(s);
    cout<<"balanced = "<<balanced;

}