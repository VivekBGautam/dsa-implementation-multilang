////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Application Name : Singly Linear Linked List (C++)
//  Description      : This program demonstrates implementation of Singly Linked List
//                     using C++ (Object Oriented Approach). It supports insertion,
//                     deletion, display, and count operations on linked list.
//  Author           : Vivek Bhauraj Gautam
//  Date             : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1) 

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name : node
//  Description    : Represents a single node of singly linked list
//  Members        :
//      data  → Stores integer data
//      next  → Pointer to next node
//
////////////////////////////////////////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name : SinglyLL
//  Description: Encapsulates all operations of singly linked list such as
//               insertion, deletion, display, and counting of nodes.
//               It maintains head pointer and node count internally.
//
////////////////////////////////////////////////////////////////////////////////////////////////////
class SinglyLL
{
    public:
        PNODE first;        // Head pointer of linked list
        int iCount;         // Number of nodes in linked list

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Constructor Name : SinglyLL
        //  Description      : Initializes empty linked list by setting head pointer
        //                     to NULL and node count to zero.
        //  Author           : Vivek Bhauraj Gautam
        //  Date             : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        SinglyLL()
        {
            cout<<"Object of SinglyLL get created.\n";
            first = NULL;
            iCount = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : Display
        //  Description   : Displays all elements of the singly linked list.
        //  Input         : void
        //  Output        : Prints all node data on screen
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void Display()
        {
            PNODE temp = first;

            while(temp != NULL)
            {
                cout<<"| "<< temp->data <<" | ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : Count
        //  Description   : Returns total number of nodes present in linked list.
        //  Input         : void
        //  Output        : Integer count of nodes
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        int Count()
        {
            return iCount;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertFirst
        //  Description   : Inserts a new node at the beginning of linked list.
        //  Input         : int no → Data to be inserted
        //  Output        : Modifies linked list by adding node at first position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertFirst(int no)
        {
            PNODE newn = new NODE;

            newn->data = no;
            newn->next = first;
            first = newn;

            iCount++;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertLast
        //  Description   : Inserts a new node at the end of linked list.
        //  Input         : int no → Data to be inserted
        //  Output        : Modifies linked list by adding node at last position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertLast(int no)
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                PNODE temp = first;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
            }
            iCount++;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertAtPos
        //  Description   : Inserts a new node at a specific position in linked list.
        //  Input         : int no  → Data to be inserted
        //                  int pos → Position where node is to be inserted
        //  Output        : Modifies linked list by inserting node at given position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertAtPos(int no,int pos)
        {
            if(pos < 1 || pos > iCount + 1)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                PNODE newn = new NODE;
                newn->data = no;

                PNODE temp = first;
                for(int i = 1; i < pos-1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteFirst
        //  Description   : Deletes the first node of linked list.
        //  Input         : void
        //  Output        : Removes first node and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }

            PNODE temp = first;
            first = first->next;
            delete temp;

            iCount--;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteLast
        //  Description   : Deletes the last node of linked list.
        //  Input         : void
        //  Output        : Removes last node and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteLast()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                PNODE temp = first;
                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteAtPos
        //  Description   : Deletes node from a specific position in linked list.
        //  Input         : int pos → Position of node to be deleted
        //  Output        : Removes node from given position and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteAtPos(int pos)
        {
            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                PNODE temp = first;
                for(int i = 1; i < pos-1; i++)
                {
                    temp = temp->next;
                }

                PNODE target = temp->next;
                temp->next = target->next;
                delete target;

                iCount--;
            }
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : main
//  Description   : Entry point of program which demonstrates all linked
//                  list operations.
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Total node in linked list is : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    cout<<"Total node in linked list is : "<<obj.Count()<<"\n";

    obj.DeleteFirst();
    obj.Display();
    cout<<"Total node in linked list is : "<<obj.Count()<<"\n";

    obj.DeleteLast();
    obj.Display();
    cout<<"Total node in linked list is : "<<obj.Count()<<"\n";

    obj.InsertAtPos(105,4);
    obj.Display();
    cout<<"Total node in linked list is : "<<obj.Count()<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
    cout<<"Total node in linked list is : "<<obj.Count()<<"\n";

    return 0;
}
