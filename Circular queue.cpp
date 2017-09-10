/*
    DAY 1:
    Circular Queue: Enqueue, Dequeue, front element, size, is empty.
*/
#include<iostream>
using namespace std;
int front=0, rear=0, count=0;

void enqueue(int q[], int n)
{
    if(count == n)
        cout<<"Queue is full!"<<endl;   //overflow condition
    else
    {
        int value;
        cout<<"Value? ";
        cin>>value;

        q[rear]=value;
        rear = (rear + 1)%n;    //rear will be set to the remainder (i.e. vacant space) after reaching 'n';
        count++;

        if(rear>front)
        {
            for(int i=front; i<rear;i++)
                cout<<q[i]<<"\t";
        }
        else
        {
            for(int i=front; i< n;i++)
                cout<<q[i]<<"\t";

            for(int i=0; i<rear;i++)
                cout<<q[i]<<"\t";
        }

    }
    cout<<endl;
}

void dequeue(int q[], int n)
{
    if(count == 0)
        cout<<"Queue is empty!"<<endl;      //underflow condition
    else
    {
        q[front]=0;
        front=(front+1)%n;
        count--;

       if(rear>front)
        {
            for(int i=front; i<rear;i++)
                cout<<q[i]<<"\t";
        }
        else
        {
            for(int i=front; i< n;i++)
                cout<<q[i]<<"\t";

            for(int i=0; i<rear;i++)
                cout<<q[i]<<"\t";
        }
    }
    cout<<endl;
}

int main()
{
    int n, option;
    cout<<"Size of queue? ";
    cin>>n;
    int q[n];

    cout<<"1. Enqueue \n2. Dequeue \n3. Front element \n4. Size of Queue \n5. Exit"<<endl;
    while(1)
    {
        cout<<"Option: ";
        cin>>option;
        switch(option)
        {
        case 1: enqueue(q, n);
                break;
        case 2: dequeue(q, n);
                break;
        case 3: cout<<q[front]<<endl;   //front element
                break;
        case 4: cout<<count<<endl;     //size of queue
                break;
        case 5: exit(0);
        default: cout<<"choose again"<<endl;
        }
    }
}
