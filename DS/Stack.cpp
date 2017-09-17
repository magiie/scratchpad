/*
    Stack: Push, Pop, Overflow, Underflow, Top Element, Size of stack.
*/

#include<iostream>
using namespace std;
int top=-1;

void push(int st[])
{
    int value;

    if (top == 3)
        cout<<"Stack is full!"<<endl;      //overflow condition
    else
    {
        cout<<"Value: ";
        cin>>value;
        top = top + 1;
        st[top]=value;

        for(int i=top; i>=0; i--)
            cout<<st[i]<<endl;
    }
}

bool underflow()    //to check whether the stack is empty or not
{
    if (top == -1)
        return true;
    else
        return false;
}

void pop(int st[])
{
    if (underflow())
        cout<<"Stack is empty!";     //checking underflow condition
    else
    {
        top = top - 1;

        for(int i=top; i>=0; i--)
            cout<<st[i]<<endl;
    }
}

void size()
{
    cout<<top+1<<endl;
}

void topElement(int st[])
{
    cout<<st[top]<<endl;
}

int main()
{
    int st[4], value, option;
    //size of stack is 4;

    for(int i=0; i<4; i++)
        st[i]=0;

    cout<<"1. Insert \n2. Delete \n3. Current size of stack \n4. Top Element \n5. Is the stack empty? \n6. Exit"<<endl;
    while (1)
    {
        cout<<"OPTION: ";
        cin>>option;
        switch(option)
        {
            case 1: push(st);
                    break;

            case 2: pop(st);
                    break;

            case 3: size();
                    break;

            case 4: topElement(st);
                    break;

            case 5: underflow();
                    break;

            case 6: exit(0);

            default: cout<<"choose again";
        }
    }
}
