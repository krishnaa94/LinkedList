#include"linkedlist.h"

linkedList mylist;

void addition(int option);
void deletion(int option);
void display(int option);
void find();

int main()
{   
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.append(4);
    mylist.append(5);

    while(1)
    {
        system("cls");
        int operation;

        cout<<string(120,'#')<<endl;
        cout<<string(120,'#')<<endl;
        cout<<string(51,'#')<<"    LINKED LIST    "<<string(50,'#')<<endl;
        cout<<string(120,'#')<<endl;
        cout<<string(120,'#')<<endl;

        cout<<string(3,'\n');
        cout<<"CHOSSE OPERATION:"<<endl;
        cout<<"\t\t 1 ---------- INSERTION IN LIST"<<endl;
        cout<<"\t\t 2 ---------- DELETION FROM LIST"<<endl;
        cout<<"\t\t 3 ---------- DISPLAY THE LIST"<<endl;
        cout<<"\t\t 4 ---------- FIND DATA IN LIST"<<endl;
        cout<<"\t\t 5 ---------- SHOW SIZE OF LIST"<<endl;
        cout<<"\t\t 6 ---------- EXIT PROGRAM"<<endl;
        cin>>operation;

        switch (operation)
        {
            int option;
        case 1: system("cls");
                cout<<string(120,'#')<<endl;
                cout<<string(44,'#')<<"    INSERTION IN LINKED LIST    "<<string(44,'#')<<endl;
                cout<<string(120,'#')<<endl;
                cout<<string(3,'\n');
                cout<<"CHOSSE OPERATION:"<<endl;
                cout<<"\t\t 1 ---------- INSERTION IN BEGGINING OF LIST"<<endl;
                cout<<"\t\t 2 ---------- INSERTION IN ENDING OF LIST"<<endl;
                cout<<"\t\t 3 ---------- INSERTION IN BETWEEN OF LIST"<<endl;
                cin>>option;
                addition(option);
                system("pause")
            break;
        case 2: system("cls");
                cout<<string(120,'#')<<endl;
                cout<<string(45,'#')<<"    DELETION IN LINKED LIST    "<<string(45,'#')<<endl;
                cout<<string(120,'#')<<endl;
                cout<<string(3,'\n');
                cout<<"CHOSSE OPERATION:"<<endl;
                cout<<"\t\t 1 ---------- DELETION FROM BEGGINING OF LIST"<<endl;
                cout<<"\t\t 2 ---------- DELETION FROM ENDING OF LIST"<<endl;
                cout<<"\t\t 3 ---------- DELETION FROM IN BETWEEN OF LIST"<<endl;
                cin>>option;
                deletion(option);
                system("pause");
            break;
        case 3: system("cls");
                cout<<string(120,'#')<<endl;
                cout<<string(47,'#')<<"   DISPLAY LINKED LIST    "<<string(48,'#')<<endl;
                cout<<string(120,'#')<<endl;
                cout<<string(3,'\n');
                cout<<"CHOSSE OPERATION:"<<endl;
                cout<<"\t\t 1 ---------- DISPLAY WHOLE LIST"<<endl;
                cout<<"\t\t 2 ---------- DISPLAY DATA AT CERTAIN POSITION"<<endl;
                cin>>option;
                display(option);
                system("pause");
            break;
        case 4: system("cls");
                cout<<string(120,'#')<<endl;
                cout<<string(43,'#')<<"   FIND DATA IN LINKED LIST    "<<string(43,'#')<<endl;
                cout<<string(120,'#')<<endl;
                cout<<string(3,'\n');
                find();
                system("pause");
            break;
        case 5: system("cls");
                cout<<string(120,'#')<<endl;
                cout<<string(48,'#')<<"   SHOW SIZE OF LIST    "<<string(48,'#')<<endl;
                cout<<string(120,'#')<<endl;
                cout<<string(3,'\n');
                cout<<" SIZE OF THE LIST IS "<<mylist.getsize()<<endl;
                system("pause");
            break;
        case 6: return 0;
            break;
        
        default:system("cls");
                cout<<string(120,'#')<<endl;
                cout<<string(50,'#')<<"..............   SORRY    ..........."<<string(50,'#')<<endl;
                cout<<string(120,'#')<<endl;
                cout<<"wrong Operation choosen, try again";
                system("pause");
            break;
        }
    }

    return 0;
}

void addition(int option)
{
    int data;
    switch (option)
    {
    case 1: cout<<string(3,'\n');
            cout<<string(50,'#')<<"    INSERTION IN BEGGINING OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter data to be inserted"<<endl;
            cin>>data;
            mylist.prepend(data);
        break;
    case 2: cout<<string(3,'\n');
            cout<<string(50,'#')<<"    INSERTION IN ENDING OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter data to be inserted"<<endl;
            cin>>data;
            mylist.append(data);
        break;
    case 3: int pos;
            cout<<string(3,'\n');
            cout<<string(50,'#')<<"    INSERTION IN BETWEEN OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter data to be inserted and position of data to be inserted"<<endl;
            cin>>data>>pos;
            mylist.addatpos(data,pos);
        break;
    default: cout<<"WRONG OPTION";
        break;
    }
}

void deletion(int option)
{
    switch (option)
    {
    case 1: cout<<string(3,'\n');
            cout<<string(50,'#')<<"   DELETION FROM BEGGINING OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            mylist.removefirst();
        break;
    case 2: cout<<string(3,'\n');
            cout<<string(50,'#')<<"    DELETION FROM ENDING OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            mylist.removelast();
        break;
    case 3: int pos;
            cout<<string(3,'\n');
            cout<<string(50,'#')<<"    DELETION FROM IN BETWEEN OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter position from where data to be removed"<<endl;
            cin>>pos;
            mylist.removePos(pos);
        break;
    default: cout<<"WRONG OPTION";
        break;
    }
}
void display(int option)
{
    switch (option)
    {
    case 1: cout<<string(3,'\n');
            cout<<string(50,'#')<<"   DISPLAY WHOLE LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            mylist.displaylist();
        break;
    case 2: int pos;
            cout<<string(3,'\n');
            cout<<string(50,'#')<<"   DISPLAY DATA AT CERTAIN POSITION  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter position to display"<<endl;
            cin>>pos;
            mylist.displaypos(pos);
        break;
    default: cout<<"WRONG OPTION";
        break;
    }
}
void find()
{
    int data;
    cout<<"Enter data to be found"<<endl;
    cin>>data;
    mylist.finddata(data);
}