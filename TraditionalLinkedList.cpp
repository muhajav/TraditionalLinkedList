#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

void InitLinkedList(Node *&head)
{
    head = NULL;
}

void InsertAtBeginning(Node *&head, int inserted_value)
{
    Node *p = new Node;
    p->value = inserted_value;
   
    p->next = head;
    head = p;
}

void InsertAtEnd(Node *&head, int inserted_value)
{
    Node *p = head;
   
    while (p->next != NULL)
        p = p->next;
       
    Node *r = new Node;
    r->value = inserted_value;
   
    r->next = NULL;
    p->next = r;
}

int GetLinkedListLength(Node *head)
{
    Node *p = head;
    int counter = 0;
   
    while (p != NULL)
    {
        counter++;
        p = p->next;
    }
   
    return counter;
}

void PrintLinkedList(Node *head)
{
    Node *p = head;
   
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
   
    cout << endl;
}

int TakeAtBeginning(Node *&head)
{
    Node *p = head;
    head = head->next;
   
    int returned_value = p->value;
    delete p;
   
    return returned_value;
}

int TakeAtEnd(Node *&head)
{
    if (head == NULL)
    {
        cout << "Error: List is empty!" << endl;
        return -1; // Indicating an error (assuming -1 is not a valid list value)
    }

    if (head->next == NULL)
    {
        int returned_value = head->value;
        delete head;
        head = NULL;
        return returned_value;
    }
    else
    {
        Node *p = head;
        while (p->next->next != NULL)
            p = p->next;

        Node *q = p->next;
        p->next = NULL;

        int returned_value = q->value;
        delete q;

        return returned_value;
    }
}

Node *head1;
Node *head2;

int main()
{
    InitLinkedList(head1);
    InitLinkedList(head2);
   
    InsertAtBeginning(head1, 10);
    InsertAtBeginning(head1, 20);
    InsertAtEnd(head1, 30);
   
    PrintLinkedList(head1);
    cout << GetLinkedListLength(head1) << endl;
   
    TakeAtBeginning(head1);
    PrintLinkedList(head1);
   
    return 0;
}
