/*
    Double-ended Queue: insert at back, insert at front, delete from back, delete from front, get front element, get rear element.
*/

#include<iostream>
using namespace std;
int front=0, rear=0;

void insert_at_back(int q[], int n)     //normal enqueue in standard queue
{
    if(rear == n)
        cout<<"Queue is full!"<<endl;   //overflow condition
    else
    {
        int value;
        cout<<"Value? ";
        cin>>value;
        q[rear]=value;
        rear = rear + 1;

    for(int i=front; i<rear;i++)
        cout<<q[i]<<"\t";
    }
    cout<<endl;
}

void insert_at_front(int q[], int n)
{
    if(rear == n)
        cout<<"Queue is full!"<<endl;   //overflow condition
    else
    {
        int value;
        cout<<"Value? ";
        cin>>value;

        for(int i=rear; i>front; i--)
            q[i] = q[i-1];

        q[front]=value;
        rear=rear+1;

        for(int i=front; i<rear;i++)
            cout<<q[i]<<"\t";
    }
    cout<<endl;
}

void delete_from_front(int q[])     //normal dequeue in standard queue
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

void delete_from_back(int q[])
{
    if(front == rear)
        cout<<"Queue is empty!"<<endl;      //underflow condition
    else
    {
        rear = rear - 1;
        q[rear]=0;

        for(int i=front; i<rear;i++)
            cout<<q[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int n, option;
    cout<<"Size of queue? ";
    cin>>n;
    int q[n];

    cout<<"1. Insert at front \n2. Insert at back \n3. Delete from front \n4. Delete from back \n5. Get front element \n6. Get rear element \n7. Exit"<<endl;
    while(1)
    {
        cout<<"Option: ";
        cin>>option;
        switch(option)
        {
        case 1: insert_at_front(q, n);
                break;
        case 2: insert_at_back(q, n);
                break;
        case 3: delete_from_front(q);
                break;
        case 4: delete_from_back(q);
                break;
        case 5: cout<<q[front]<<endl;   //front element
                break;
        case 6: cout<<q[rear-1]<<endl;     //rear element
                break;
        case 7: exit(0);
        default: cout<<"choose again"<<endl;
        }
    }
}
