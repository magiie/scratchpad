/*
    DAY 1:
    Balanced parenthesis problem using Stack.
*/

#include<iostream>
using namespace std;
int top=-1;

void push(char st[])
{
    top = top + 1;
    st[top]= '(';
}

void pop()
{
    top = top - 1;
}

bool isEmpty()
{
    if(top==-1)
        return true;
    else
        return false;
}

int main()
{
    string mystring;
    getline(cin,mystring);

    char st[mystring.length()];

    for(int i=0; i<mystring.length(); i++)
    {
        if (mystring[i] == '(' || mystring[i] == ')')   //to check whether the first parenthesis is ')' or '('
        {
            int a = mystring[i];
            if(a == ')')
            {
                cout<<"Parenthesis cannot start with ')'";
                return (0);
            }
            else    //if the first bracket is not ')'
            {
                for(int i=0; i<mystring.length(); i++)
                {
                    if(mystring[i] == '(')
                        push(st);
                    else if (mystring[i] == ')')
                        pop();
                    else
                        continue;
                }
            }break;
        }break;
    }

    if (isEmpty())
        cout<<"Parenthesis are balanced!";
    else
        cout<<"Parenthesis are not balanced!";
}
