#include <iostream> 
using namespace std;

//class define
class Node {
    public:
    int data ;
    Node *next;

    Node(int data);
};

class linkedList{
    private: 
        Node *head;
        Node *tail;
        int size;
    public:
        linkedList();
        ~linkedList();
        int getsize();    
        //insertion
        void append(int data);
        void prepend(int data);
        void addatpos(int data,int pos);
        //displayfunction
        void displaylist();
        void displaypos(int pos);
        //deletion
        void removefirst();
        void removelast();
        void removePos(int pos);
        //findFunstion
        void finddata(int data); 
};

//------------------------------------------------------ member functions -------------------------------------

//------------------------------------------------------   constructors   -------------------------------------

Node::Node(int data)
{
    this->data = data;
    next = NULL;
}

linkedList::linkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
    cout<<"Program initailised press Enter to proceed.........."<<endl;
    system("pause");
}

//------------------------------------------------------   constructors   -------------------------------------
linkedList::~linkedList()
{
    Node *temp = head;
    while(temp)
    {
        temp=head->next;
        delete head;
        head=temp;
    }
    cout<<"list deleted";
}

//------------------------------------------------------ get size function -------------------------------------
int linkedList::getsize()
{
    return size;
}

//------------------------------------------------------ insertion functions -------------------------------------

void linkedList::prepend(int data)
{
    Node *n = new Node(data);
    //if list is empty
    if(head == NULL)
    {
        head = n;
        tail = n;
    }
    else 
    {
        n->next = head;
        head = n; 
    }
    size++;
    cout<<"Insertion succesfull !!"<<endl;
}

void linkedList::append(int data)
{
    Node *n = new Node(data);
    //if list is empty
    if(head == NULL)
    {
        head = n;
        tail = n;
    }
    else 
    {
        tail->next = n;
        tail = n; 
    }
    size++;
    cout<<"Insertion succesfull !!"<<endl;
}

void linkedList::addatpos(int data, int pos)
{
    if(pos>size || pos<1)
    {
        int desire;
        cout<<"linkedlist is to smaller than desired position"<<endl;
        cout<<"Press :\n1 ------> insert at begining \n2 -----> insert at last\n";
        cin>>desire;
        switch(desire)
        {
            case 1  : append(data);     break;
            case 2  : prepend(data);    break;
            default :                   break;
        }
    }
    else if(pos == 1)
        prepend(data);
    else if(pos == size)
        append(data);
    else 
    {
        Node *temp = head;
        for (int i = 1; i < pos-1; i++)
            temp = temp->next;        
        
        Node *n = new Node(data);
        n->next = temp-> next;
        temp-> next = n;
        size++;
    }
}
//------------------------------------------------------ display functions -------------------------------------

void linkedList::displaylist()
{
    Node *temp = head;
    if(!temp)
    cout<<"List is empty"<<endl;
    else 
    cout<<"\t LIST   !!"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" --> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void linkedList::displaypos(int pos)
{
    Node *temp = head;
    for (int i = 1; i < pos; i++)
            temp = temp->next;
        
    cout<<"Data at"<<pos<<"th position is "<<temp->data<<endl;
}

//------------------------------------------------------ delete data -------------------------------------

 void linkedList::removefirst()
 {
    //no list
    if(tail == NULL)
        cout<<"list is empty --> not possible to delete";
    //list exist
    else
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        size--;
    }
    cout<<"Deletion succesfull !!"<<endl;
 }

void linkedList::removelast()
{
    //no list
    if(tail == NULL)
        cout<<"list is empty --> not possible to delete";
    //list exist with 1 element
    else if(head->next == NULL)
    {
        removefirst();
    }
    //list exist with more than 1 element
    else     
    {
        Node *prev,*curr = head;
        while(curr != tail)
        {
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        tail->next = NULL;
        delete curr;
        size--;
    }
    cout<<"Deletion succesfull !!"<<endl;
}

void linkedList::removePos(int pos)
{
    if(pos>size || pos<1)
        cout<<"desired position is more than the size of list"<<endl;
    else if (pos == 1)
        removefirst();
    else if(pos == size)
        removelast();
    else
    {
        Node  *prev, *curr = head;
        for (int i = 1; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        cout<<"deleteing data --> "<<curr->data<<" from "<<pos<<"th position"<<endl;
        delete curr;
        size--;
    } 
}

//------------------------------------------------------   find function   -------------------------------------

void linkedList::finddata(int data)
{
    int pos = 1;
    bool found = false;
    Node *temp = head;
    while(temp)
    {   
        if(data == temp->data)
            {
                found = true;
                cout<<"data --> "<<data<<" is found at "<<pos<<"th postition of list"<<endl;
            }
        pos++;
        temp=temp->next;
    }

    if(!found)
        cout<<"DATA NOT FOUND"<<endl;
}
