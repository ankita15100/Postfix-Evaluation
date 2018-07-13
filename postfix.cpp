#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int evaluate_exp(string s);
bool isoperator(char c);
bool isdigit(char c);
int perform_operation(char op, int op1, int op2);
int main()
{
    string str;
    cout<<"Enter the exp\n";
    getline(cin,str);
    int z=evaluate_exp(str);
    cout<<"value is "<<z;

}
int evaluate_exp(string s)
{
    int i=0,n;
    stack<int> stk;
    n=s.length();
    cout<<"length n= "<<n<<"\n";
    for(i=0;i<n;i++)
        {
        if(s[i]==' ')
            continue;
        else if(isoperator(s[i]))
        {
            int z1,z2,out;
            z2=stk.top();
            stk.pop();
            z1=stk.top();
            stk.pop();
            out=perform_operation(s[i],z1,z2);
            stk.push(out);
            cout<<"ope "<<s[i]<<" "<<z1<<" "<<z2<<" "<<out<<"\n";
        }
        else if(isdigit(s[i]))
        {
             int operand=0;
            while(i<n && isdigit(s[i])==true)
            {

                operand=(operand*10)+ (s[i]-'0');
                i++;
            }
            cout<<"operand is "<<operand<<"\n";
            stk.push(operand);
            i--;
        }
    }
    return stk.top();
}
bool isoperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    return false;
}
bool isdigit(char c)
{
    if(c>='0' && c<='9')
        return true;
    return false;
}
int perform_operation(char op, int op1, int op2)
{
    int r;
    if(op=='+')
       r=op1+op2;
    else if(op=='-')
       r=op1-op2;
    else if(op=='*')
       r=op1*op2;
    else if(op=='/')
        r=op1/op2;
    return r;
}
