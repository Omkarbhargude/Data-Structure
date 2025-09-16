///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name         : Doubly Linear LinkedList
// Description  : Implementing Doubly linear LinkedList with operations like Insertion, Deletion,searching and traversal
// Input        : Integer
// Output       : Integer
// Author       : Omkar Mahadev Bhargude
// Date         : 01/07/2025
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//
// Structure of node
//
struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

////////////////////////////////////////////////////////////////////////////////////////

//
//  typedef
//
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first);
int Count(PNODE first);
void InsertFirst(PPNODE first, int no);
void InsertLast(PPNODE first, int no);
void InsertAtPos(PPNODE first, int no, int pos);
void DeleteFirst(PPNODE first);
void DeleteLast(PPNODE first);
void DeleteAtPos(PPNODE first, int pos);

////////////////////////////////////////////////////////////////////////////////////////

// Displays all elements from linkedlist
void Display(
                PNODE first
            )
{
    printf("NULL <=>");
    while(first != NULL)
    {
        printf(" | %d | <=> ",first->data);

        first = first->next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////////////////

// Counts all elements from linkedlist
int Count(
            PNODE first
        )
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;

        first = first->next;
    }

    return iCount; 
}

////////////////////////////////////////////////////////////////////////////////////////

// Insert new node at first position
void InsertFirst(
                    PPNODE first, 
                    int no
                )
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;

    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Inserts new node at last position
void InsertLast(
                    PPNODE first, 
                    int no
                )
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Insert new node at given position
void InsertAtPos(
                    PPNODE first, 
                    int no, 
                    int pos
                )
{
    int iCount = 0, iCnt = 0;

    iCount = Count(*first);

    PNODE newn = NULL;
    PNODE temp = NULL;

    if((pos < 1) || (pos > iCount + 2))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Deletes first node from linkedlist
void DeleteFirst(
                    PPNODE first
                )
{

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);
        (*first)->prev = NULL;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Delete last node from linkedlist
void DeleteLast(
                    PPNODE first
                )
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);

        temp->next = NULL;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Deletes node at given position
void DeleteAtPos(
                    PPNODE first, 
                    int pos
                )
{
    int iCount = 0, iCnt = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        free(target);

    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Searches element from linkedlist and returns the position
int SearchElement(
                    PNODE first, 
                    int no
                )
{
    int i = 0;

    while(first != NULL)
    {
        i++;
        if((first->data) == no)
        {
            return i;
        }
        
        first = first->next;
    }

    return -1;
}

////////////////////////////////////////////////////////////////////////////////////////

// Displays elements in reversed format
void ReverseDisplay(
                        PNODE first
                    )
{
    while(first->next != NULL)
    {
        first = first->next;
    }

    printf("NULL ");

    while(first != NULL)
    {
        printf(" <=> | %d | ",first->data);

        first = first->prev;
    }

    printf("NULL\n");

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   main()
//  Description     :   Entry point function of program
//  Author Name     :   Omkar Mahadev Bhargude
//  Function Date   :   05/08/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

    PNODE head = NULL;
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    printf("----------------------------------------------------------------------------\n");
    printf("------------------------- DOUBLY LINEAR LINKEDLIST -------------------------\n");
    printf("----------------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("-------------------------------------------------------------------------\n");
        printf("-------------------------- Select the Option ----------------------------\n");
        printf("-------------------------------------------------------------------------\n");
        printf("1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete new node at first position\n");
        printf("5 : Delete new node at last position\n");
        printf("6 : Delete new node at given position\n");
        printf("7 : Display all element from LinkedList\n");
        printf("8 : Count number of elements from LinkedList\n");
        printf("9 : search element from linkedlist\n");
        printf("10 : Display linkedlist in reverse\n");
        printf("0 : Terminate LinkedList\n");
        printf("------------------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1: 
                    printf("Enter the data that you want to insert : \n");
                    scanf("%d",&iValue);
                    InsertFirst(&head,iValue);
                    break;

            case 2:
                    printf("Enter the data that you want to insert : \n");
                    scanf("%d",&iValue);
                    InsertLast(&head,iValue);
                    break;

            case 3:
                    printf("Enter the data that you want to insert : \n");
                    scanf("%d",&iValue);

                    printf("Enter the position at which you want to insert the node : \n");
                    scanf("%d",&iPos);

                    InsertAtPos(&head,iValue,iPos);
                    break;

            case 4:
                    printf("Deleting first element from LinkedList\n");
                    DeleteFirst(&head);
                    break;

            case 5:
                    printf("Deleting last element from LinkedList\n");
                    DeleteLast(&head);
                    break;

            case 6:
                    printf("Deleting element from given position of LinkedList\n");
                    printf("Enter the position at which you want delete the  node : \n");
                    scanf("%d",&iPos);

                    DeleteAtPos(&head,iPos);
                    break;

            case 7: 
                   printf("Displaying all the elements from LinkedList\n");
                   Display(head);
                   break;

            case 8:
                    iRet = Count(head);
                    printf("Number of elements in LinkedList are : %d\n",iRet);
                    break;

            case 9:
                    printf("Enter the element that you want to search : \n");
                    scanf("%d",&iValue);

                    iRet = SearchElement(head,iValue);

                    if(iRet == -1)
                    {
                        printf("Element not found\n");
                    }
                    else
                    {
                        printf("Element found at position : %d\n",iRet);
                    }

                    break;

            case 10:
                   printf("Reversed Elements are : \n");
                   ReverseDisplay(head);
                   break;


            case 0:
                   printf("------------------- THANKS FOR USING OUR APPLICATION ---------------\n");
                   return 0;
            
            default:
                   printf("Invalid Choice\n");
                   printf("--------------------------------------------------------------------\n");
                   break;
                   
        }            
    }
    return 0;
}