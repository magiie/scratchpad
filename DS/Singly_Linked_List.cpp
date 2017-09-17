/*
    Singly Linked List: insert at beginning, insert at end, insert at position, delete from a position, search
*/

#include<iostream>
using namespace std;

typedef struct linkedlist *node;

struct linkedlist{
    int data;
    struct linkedlist *next;
}*head;

class LL
{
    public:
    node create_node();
    void insert_at_beg();
    void insert_at_end();
    void insert_at_pos();
    void delete_from_pos();
    void search();
};

void display()
{
    node p = head;
    if(head == NULL)
        cout<<"List is empty"<<endl;
    else
    {
        while(p != NULL)
        {
            cout<<p->data<<"->";
            p = p->next;
        }cout<<"NULL"<<endl;
    }
}

int size()
{
    node p = head;
    int count = 0;
    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

node LL::create_node()
{
    node temp;
    cout<<"value: ";
    int value;
    cin>>value;
    temp = new(struct linkedlist);
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void LL::insert_at_beg()
{
    node temp, p;
    temp = create_node();

    if(head == NULL)
        head = temp;
    else
    {
        p = head;
        head = temp;
        temp->next = p;
    }
    display();
}

void LL::insert_at_end()
{
    node temp, p;
    temp = create_node();

    if(head == NULL)   //to check whether the LL is empty
        head = temp;

    else
    {
        p = head;
        while(p->next != NULL)  //to traverse to the end of the LL
            p = p->next;
        p->next = temp;
    }
    display();
}

void LL::insert_at_pos()
{
    node temp, p = head, q;                  //p and q for current and previous node
    int pos;
    cout<<"insert at position: ";
    cin>>pos;

    int n = size();

    if(pos == 1)
    {
        insert_at_beg();
    }
    else if(pos>1 && pos<=n)
    {
        for(int i=1; i<pos; i++)
        {
            q = p;
            p = p->next;
        }
        temp = create_node();

        q->next = temp;
        temp->next = p;
    }
    else
        cout<<"Out of range"<<endl;

    display();
}

void LL::delete_from_pos()
{
    node temp, p = head, q;
    int pos;
    cout<<"Delete from position: ";
    cin>>pos;

    int n = size();

    if(head == NULL)
        cout<<"List is empty."<<endl;
    else
    {
        if(pos == 1)
            head = p->next;
        else if(pos>1 && pos<=n)
        {
            for(int i=1; i<pos; ++i)
            {
                q = p;          //node before the one to be deleted
                p = p->next;    //node to be deleted
            }
            q->next = p->next;      //q points to the node next to p
        }
        else
            cout<<"Out of range"<<endl;

        delete p;
    }

    display();
}

void LL::search()
{
    node p = head;
    int x, i=0, j=0;    //i is index, j is set to false
    cout<<"to search: ";
    cin>>x;

    while(p != NULL)
    {
        i++;
        if(p->data == x)
        {
            cout<<"Found "<<x<<" at "<<i<<endl;
            j = 1;
        }
        p = p->next;
    }
    if(j == 0)
        cout<<x<<" is not in the list"<<endl;
}

int main()
{
    head = NULL;
    LL list;

    cout<<"1. INSERT - Beginning \n2. INSERT - End \n3. INSERT - Position\n4. Delete \n5. Search \n6. Exit"<<endl;
    while(1)
    {
        cout<<"Option: ";
        int option;
        cin>>option;
        switch(option)
        {
            case 1: list.insert_at_beg();
                    break;

            case 2: list.insert_at_end();
                    break;

            case 3: list.insert_at_pos();
                    break;

            case 4: list.delete_from_pos();
                    break;

            case 5: list.search();
                    break;

            case 6: exit(0);

            default: cout<<"choose again"<<endl;
        }
    }
}
