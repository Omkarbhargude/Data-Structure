///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name : Singly Circular LinkedList
// Description : Impementing Singly Circular LinkedList with operations like Insertion, Deletion and traversal
// Input : Integer
// Output : Integer
// Author : Omkar Mahadev Bhargude
// Date : 01/07/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

//
// Structure of node
//
struct node 
{
    int data;
    struct node *next;
};

//
// typedefs
//
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first, PNODE last);
int Count(PNODE first, PNODE last);
void InsertFirst(PPNODE first, PPNODE last, int no);
void InsertLast(PPNODE first, PPNODE last, int no);
void InsertAtPos(PPNODE first, PPNODE last, int no, int pos);
void DeleteFirst(PPNODE first, PPNODE last);
void DeleteLast(PPNODE first, PPNODE last);
void DeleteAtPos(PPNODE first, PPNODE last, int pos);

////////////////////////////////////////////////////////////////////////////////////

// Displays all elements from linkedlist
void Display(
                PNODE first, 
                PNODE last
            )
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    do
    {
        printf("| %d | -> ",first->data);

        first = first->next;

    }while(first != last->next);

    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////

// Counts number of elements present in Linkedlist
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

////////////////////////////////////////////////////////////////////////////////////

// Inserts new node at Beginning of LinkedList
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

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
    }
    else
    {
        newn -> next = *first;
        *first = newn;

        (*last)->next = *first;
    }
}

////////////////////////////////////////////////////////////////////////////////////

// Inserts new node at End of LinkedList
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

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;

        (*last)->next = *first;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;

        (*last)->next = *first;
    }
}

////////////////////////////////////////////////////////////////////////////////////

// Inserts new node at given position at runtime
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

    if((pos < 1) || (pos > iCount+2))
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
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        (*last)->next = *first;
    }
}

////////////////////////////////////////////////////////////////////////////////////

// Deletes first node of LinkedList
void DeleteFirst(
                    PPNODE first, 
                    PPNODE last
                )
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if((*first)->next == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;

        free((*last)->next);

        (*last)->next = *first;
    }
}

////////////////////////////////////////////////////////////////////////////////////

// Delete Last node of LinkedList
void DeleteLast(
                    PPNODE first, 
                    PPNODE last
                )
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if((*first)->next == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        do 
        {
            temp = temp->next;
        }while(temp->next->next != *first);

        *last = temp;
        
        free(temp->next);

        (*last)->next = *first;
    }

}

////////////////////////////////////////////////////////////////////////////////////

// Deletes the node from given position at runtime
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

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid Position\n");
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

        free(target);
    }
}

////////////////////////////////////////////////////////////////////////////////////

// Search if element is present or not
int SearchElement(
                    PNODE first, 
                    PNODE last, 
                    int no
                )
{ 
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return -1;
    }

    do
    {
        iCount++;

        if((first)->data == no)
        {
            return iCount;
        }
        
        first = first->next;

    }while(first != last->next);

    return -1;
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
    int iPos = 0;
    int iRet = 0;
    int iValue = 0;

    printf("-----------------------------------------------------------------------------------------\n");
    printf("----------------------------- SINGLY CIRCULAR LINKEDLIST --------------------------------\n");
    printf("-----------------------------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("-----------------------------------------------------------------------------------------\n");
        printf("-------------------------------- Select the Option --------------------------------------\n");
        printf("-----------------------------------------------------------------------------------------\n");

        printf("1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete node at first position\n");
        printf("5 : Delete node at last position\n");
        printf("6 : Delete node from given position\n");
        printf("7 : Count number elements present\n");
        printf("8 : Display all elements from Linkedlist\n");
        printf("9 : Enter the element and search the position of that element\n");
        printf("0 : Terminate application\n");
        printf("-----------------------------------------------------------------------------------------\n");

        printf("Enter the Option : \n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the data you want to insert : \n");
                scanf("%d",&iValue);
                InsertFirst(&head,&tail,iValue);
                break;

            case 2:
                printf("Enter the data you want to insert : \n");
                scanf("%d",&iValue);
                InsertLast(&head,&tail,iValue);
                break;

            case 3:
                printf("Enter the data that you want to insert : \n");
                scanf("%d",&iValue);

                printf("Enter the Position at which you want to insert the data\n");
                scanf("%d",&iPos);

                InsertAtPos(&head,&tail,iValue,iPos);
                break;

            case 4:
                printf("Deleting first element from linkedlist...\n");
                DeleteFirst(&head,&tail);
                break;

            case 5:
                printf("Deleting last element from linkedlist...\n");
                DeleteLast(&head,&tail);
                break;

            case 6:
                printf("Enter the position from which you want to delete the node : \n");
                scanf("%d",&iPos);
                DeleteAtPos(&head,&tail,iPos);
                break;

            case 7:
                iRet = Count(head,tail);

                printf("Number of elements in linkedlist are : %d\n",iRet);
                break;

            case 8:
                printf("Elements from Linkedlist are : \n");
                Display(head,tail);
                break;

            case 9:
               printf("Enter the element that you want to search : \n");
               scanf("%d",&iValue);

               iRet = SearchElement(head,tail,iValue);
               
               if(iRet == -1)
               {
                   printf("Element not found\n");
               }
               else
               {
                   printf("Element found at position : %d\n",iRet);
               }
               break;

            case 0:
                printf("---------------------------- Thanks for using our application ----------------------------\n");
                return 0;

            default:
                 printf("Invalid Option\n");
                 printf("-----------------------------------------------------------------------------------------------\n");
                 break;
        }
    }

    return 0;
}