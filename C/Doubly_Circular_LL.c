///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name : Doubly Circular LinkedList
// Description : Impementing Doubly Circular LinkedList with operations like Insertion, Deletion, and traversal
// Input : Integer
// Output : Integer
// Author : Omkar Mahadev Bhargude
// Date : 01/07/2025
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

void Display(PNODE first, PNODE last);
int Count(PNODE first, PNODE last);
void InsertFirst(PPNODE first, PPNODE last, int no);
void InsertLast(PPNODE first, PPNODE last, int no);
void InsertAtPos(PPNODE first, PPNODE last, int no, int pos);
void DeleteFirst(PPNODE first, PPNODE last);
void DeleteLast(PPNODE first, PPNODE last);
void DeleteAtPos(PPNODE first, PPNODE last, int pos);

////////////////////////////////////////////////////////////////////////////////////////

// Displays all element from linkedlist
void Display(
                PNODE first,
                PNODE last
            )
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    printf(" <=> ");
    do
    {
        printf("| %d | <=> ",first->data);

        first = first->next;

    }while(first != last->next);

    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////

// Counts number of elements in linkedlist
int Count(
            PNODE first,
            PNODE last
        )
{ 
    int iCount = 0; 
    if(first == NULL && last == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;

        first = first->next;

    }while(first != last->next);

    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////

// Inserts new node at first position
void InsertFirst(
                    PPNODE first,
                    PPNODE last,
                    int no
                )
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*first)->prev = *last;
        (*last)->next = *first;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;

        (*first)->prev = *last;
        (*last)->next = *first;

    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Inserts new node at last position
void InsertLast(
                    PPNODE first, 
                    PPNODE last, 
                    int no
                )
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*first)->prev = *last;
        (*last)->next = *first;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;

        (*last)->next = *first;
    }

}

////////////////////////////////////////////////////////////////////////////////////////

// Insert new node at given position
void InsertAtPos(
                    PPNODE first, 
                    PPNODE last, 
                    int no, 
                    int pos
                )
{
    int iCount = 0, iCnt = 0;

    iCount = Count(*first,*last);

    PNODE newn = NULL;
    PNODE temp = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,last,no);
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
        temp->next->prev = newn;
        temp->next = newn;

        (*first)->prev = *last;
        (*last)->next = *first;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Deletes node at position
void DeleteFirst(
                    PPNODE first, 
                    PPNODE last
                )
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;

        free((*first)->prev);

        (*first)->prev = *last;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Deletes node at last position
void DeleteLast(
                    PPNODE first, 
                    PPNODE last
                )
{
    
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last)->prev;

        free((*last)->next);

        (*first)->prev = *last;
        (*last)->next = *first;
    }
}

////////////////////////////////////////////////////////////////////////////////////////

// Deletes node at given position
void DeleteAtPos(
                    PPNODE first, 
                    PPNODE last, 
                    int pos
                )
{
    int iCount = 0, iCnt = 0;

    iCount = Count(*first,*last);

    PNODE temp = NULL;
    PNODE target = NULL;

    if((pos < 1) || (pos > iCount+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
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
        temp->next->prev = temp;

        free(target);

        (*first)->prev = *last;
        (*last)->next = *first;
    }

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
    PNODE tail = NULL;

    int iChoice = 0;
    int iRet = 0;
    int iValue = 0;
    int iPos = 0;

    printf("---------------------------------------------------------------------\n");
    printf("----------------------- DOUBLY CIRCULAR LINKEDLIST ------------------\n");
    printf("---------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("-------------------------------------------------------------------\n");
        printf("---------------------- Select the Option --------------------------\n");
        printf("-------------------------------------------------------------------\n");
        printf("1 : Insert new node at first Position\n");
        printf("2 : Insert new node at last Position\n");
        printf("3 : Insert new node at given Position\n");
        printf("4 : Delete new node at first Position\n");
        printf("5 : Delete new node at last Position\n");
        printf("6 : Delete new node at given Position\n");
        printf("7 : Display all elements of LinkedList\n");
        printf("8 : Count number of node from LinkedList\n");
        printf("0 : Terminate LinkedList\n");
        printf("------------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                 printf("Enter the data that you want to insert : \n");
                 scanf("%d",&iValue);

                InsertFirst(&head,&tail,iValue);
                break;

            case 2:
                printf("Enter the data that you want to insert : \n");
                scanf("%d",&iValue);

                InsertLast(&head,&tail,iValue);
                break;

            case 3:
                printf("Enter the data that you want to insert : \n");
                scanf("%d",&iValue);

                printf("Enter the position at which you want to insert the node : \n");
                scanf("%d",&iPos);

                InsertAtPos(&head,&tail,iValue,iPos);
                break;

            case 4:
                printf("Deleting first element from LinkedList... \n");
                DeleteFirst(&head,&tail);
                break;
            
            case 5:
                printf("Deleting Last element from LinkedList... \n");
                DeleteLast(&head,&tail);
                break;

            case 6:
                printf("Enter the position at which you want delete the new node\n");
                scanf("%d",&iPos);

                DeleteAtPos(&head,&tail,iPos);

                printf("Deleting the element from given position in LinkedList...\n");
                break;

            case 7:
                printf("Elements from LinkedList are : \n");
                Display(head,tail);
                break;

            case 8:
                iRet = Count(head,tail);
                printf("Number of elements in LinkedList are : %d\n",iRet);
                break;

            case 0:
                printf("------------ THANKS FOR USING OUR APPLICATION -----------\n");
                return 0;

            default:
                printf("Invalid Choice\n");
                break;
                printf("------------------------------------------------------------------\n");
        }
    }

    return 0;
}