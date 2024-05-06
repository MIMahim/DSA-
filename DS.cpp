#include<bits/stdc++.h>
using namespace std;
#define NULL 0
int length = 0;
/**
 * @author Mainul Islam Mahim
*/
struct node
{
    int num;
    struct node *link;
};
node *start,*ptr;

void LinkedList()
{
    int i,j,n;
    start = new node;
    ptr = start;
    
    cout<<"How many elements: ";
    cin>>n;
    
    for(i=1; i<=n; i++)
    {
        cout << "Input element " << i << ": ";
        cin >> ptr->num;

        if(i!=n)
        {
            ptr->link = new node;
            ptr = ptr->link;
        }
    }
    ptr->link = NULL;
    length = n;
}

void Insert(int value,int pos)
{
    if(pos == 1)
    {
        node* t;
        t = new node;
        t->num = value;
        t->link = start;
        start = t;
    }
    else if(pos>0 && pos<=(length+1))
    {
        node* t = start;
        node* prev;
        for(int i=1; i<pos; i++)
        {
            prev = t;
            t = t->link;
        }
        node* New = new node;
        prev->link = New;
        New->num = value;
        New->link = t;
    }
    else cout<<"Invalid position"<<endl;
    length++; //increment the size of LL
}
void Delete(int pos)
{
    if(pos==1)
    {
        node* t = start;
        start = t->link;
        delete t;
        return ;
    }
    node* t = start;
    node* prev;
    for(int i=1; i<pos; i++)
    {
        prev = t;
        t = t->link;
    }
    prev->link = t->link;
    delete t;
    length--; //decrement the size of LL
}
void Display()
{
    cout<<"Elements in the Link list are: "<<endl;
    ptr = start;
    while(ptr != NULL)
    {
        cout<<ptr->num<<" ";
        ptr= ptr->link;
    }
    cout<<endl;
}
int main()
{
    int n,item,pos;
    /// This function initializes a linked list where the user inputs n elements
    LinkedList();

    while(1)
    {
        cout<<endl;
        cout<<"1.Insert an element in specific position "<<endl;
        cout<<"2.Delete an element in specific position "<<endl;
        cout<<"3.Exit"<<endl;

        cin>>n;
        if(n==1)
        {
            cout<<"Value : ";
            cin>>item;
            cout<<"Position : ";
            cin>>pos;
            Insert(item,pos);
            Display();
        }
        else if(n==2)
        {
            cout<<"Position : ";
            cin>>pos;
            Delete(pos);
            Display();
        }
        else if(n==3) return 0;
    }
}
