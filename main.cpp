#include <iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int value;
    node *next_node;
};

int length = 0;
node *start = NULL;

void create(int a)
{
    if(length == 0)
    {
        start = new node;
        start->value = a;
        start->next_node = NULL;
        length = length + 1;
    }
    else
    {
        cout<<"Try create() function , List is not empty\n";
    }
    return;
}

void add_start()
{
    if(length != 0)
    {
        node *b;
        b= new node;
        cout<<"Enter the intergral number for value of node:";
        cin>>b->value;
        b->next_node = start;
        start = b;
        length = length + 1;
    }
    else
    {
        cout<<"Given list is Empty try create:\n";

    }
    return;
}

void add_last(int x)
{
    node *a;
    a = start;
    while(a->next_node != NULL)
    {
        a = a->next_node;
    }
    node *b;
    b = new node;
    b->value=x;
    b->next_node = NULL;
    a->next_node = b;
    length= length + 1;
}

void del()
{
    if(length == 0) cout<<"List is Empty:";
    else
    {
        int x;
        cout<<"Enter the intergral number for value of node";
        cin>>x;
        node *current, *previous;
        current = start;
        while((current->value != x) && (current->next_node != NULL))
        {
            previous = current;
            current = current->next_node;
        }
        if(current->next_node == NULL) cout<<"Entered value not found";
        else
        {
            if(current == start )
                start = current->next_node;
            else
                previous->next_node = current->next_node;
            delete current;
            length = length -1;
            cout<<"Node deleted successfully:";
        }
    }
    return;
}

void traverse()
{
    if(length == 0) cout<<"Empty list:\n";
    else
    {
        node *a;
        a = start;
        while(a -> next_node != NULL)
        {
            cout<<a->value<<"\t";
            a= a->next_node;
        }
        cout<<a->value;
    }
    cout<<endl;
}
 void len()
 {
    cout<<"The length of given linked list:"<<length<<endl;
 }

void choose()
{
    int choosen_function;
    cout<<" 1: Create \n 2: Add at start \n 3: Add at end \n 4: Detele \n 5: Length \n 6: Print \n 7:Exit\n";
    cout<<"\n Enter the number(1-7)";
    cin>>choosen_function;
    if(choosen_function == 1)
    {
        int x;
        cout<<"Enter the integer value:";
        cin>>x;
        create(x);
    }

    else if(choosen_function == 2)
        add_start();
    else if(choosen_function == 3)
    {
        int x;
        cout<<"Enter the integer value:";
        cin>>x;
        add_last(x);
    }

    else if(choosen_function == 4)
        del();
    else if(choosen_function == 5)
        len();
    else if(choosen_function == 6)
        traverse();
    else if(choosen_function == 7)
    {}
    else
        {
            cout<<"Enter the correct value";
        }

}

int main(int argc, char const *argv[])
{
    try
    {
    if(argc != 2)
        throw argc;
    else
    {
    char reset;

    string line_;
    ifstream file_(argv[1]);
    if(file_.is_open())
    {
        while(file_>>line_)
        {
            int a;
            stringstream ss;
            ss<<line_;
            ss>>a;

            if(length==0)
            {
                create(a);
            }
            else
                add_last(a);

        }
        file_.close();

    }

    else
    {
        cout<<"file not found\n";
    }
    again:
    choose();
    cout<<"You want to restart (y/n):";
    cin>>reset;
    if(reset == 'y' || reset == 'Y')
        goto again;
    else
    {
        cout<<"Thank you\n";
        ofstream file_(argv[1]);
        node *a;
        a = start;
        while(a -> next_node != NULL)
        {
            file_<<a->value<<endl;
            a= a->next_node;
        }
        file_<<a->value<<endl;
        file_.close();

    }
    }
    }
    catch(...)
    {
        cout<<"This funtion require two arguments:";
        cout<<"For Example: ./check HW_3.txt:";
    }

}
