/*
    DAY 1:
    Queue: Enqueue, Dequeue.
*/
#include<iostream>
using namespace std;
int front=0, rear=0;

void enqueue(int q[], int n)
{
    if(rear == n)
        cout<<"Queue is full!"<<endl;   //overflow condition
    else
    {
        int value;
        cout<<"Value? ";
        cin>>value;
        q[rear]=value;
        rear++;

    for(int i=front; i<rear;i++)
        cout<<q[i]<<"\t";
    }
    cout<<endl;
}

void dequeue(int q[])
{
    if(front == rear)
        cout<<"Queue is empty!"<<endl;      //underflow condition
    else
    {
        q[front]=0;
        front++;

    for(int i=front; i<rear;i++)
        cout<<q[i]<<"\t";

    }
    cout<<endl;
}

void size()
{
    cout<<rear - front<<endl;
}

int main()
{
    int n, option;
    cout<<"Size of queue? ";
    cin>>n;
    int q[n];

    cout<<"1. Enqueue \n2. Dequeue \n3. Size of queue \n4. Exit"<<endl;
    while(1)
    {
        cout<<"Option: ";
        cin>>option;
        switch(option)
        {
        case 1: enqueue(q, n);
                break;
        case 2: dequeue(q);
                break;
        case 3: size();
                break;
        case 4: exit(0);
        default: cout<<"choose again"<<endl;
        }
    }
}
