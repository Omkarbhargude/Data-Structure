///////////////////////////////////////////////////////////////////////////////////////////
//
// Name         : Singly Linear LinkedList
// Description  : Impementing Stack with operations like push, pop, display etc.
// Input        : Integer
// Output       : Integer
// Author       : Omkar Mahadev Bhargude
// Date         : 01/07/2025
//
///////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>

//
//  node structure
//
struct node
{
    int data;
    struct node *next;
};

//
//  typedef
//
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

//
//  Functions implemented
//
void Push(PPNODE first, int no);
int Pop(PPNODE first);
void Display(PNODE first)
int Count(PNODE first)

///////////////////////////////////////////////////////////////////////////////////////////

void Push(
            PPNODE first, 
            int no
        )           
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    newn->next = *first;
    *first = newn;
}

///////////////////////////////////////////////////////////////////////////////////////////

int Pop(
            PPNODE first
        )                     
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*first == NULL)
    {
        printf("Unable to pop as stack is empty\n");
        return NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;

        iValue = temp->data;

        free(temp);

        return iValue;

    }

}

///////////////////////////////////////////////////////////////////////////////////////////

void Display(
                PNODE first
            )
{
    while(first != NULL)
    {
        printf("| %d | - ",first->data);

        first = first->next;
    }

    printf("\n");

}

///////////////////////////////////////////////////////////////////////////////////////////

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
    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    printf("===================================================\n");
    printf("=========== Stack using Singly Linear =============\n");
    printf("===================================================\n");

    while(iChoice != 0)
    {
        printf("\n=============================================\n");
        printf("============== Select the Option ============\n");
        printf("=============================================\n");
        printf("1 : PUSH Element\n");
        printf("2 : POP the Element\n");
        printf("3 : Display all elements\n");
        printf("4 : Count the elements \n");
        printf("0 : Terminate Program\n");
        printf("=============================================\n");

        printf("Enter the option : \n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
               printf("Enter the data that you want push : \n");
               scanf("%d",&iValue);

               Push(&head,iValue);
               break;

            case 2:
               iRet = Pop(&head);
               printf("Poped Element is : %d\n",iRet);
               break;

            case 3:
               Display(head);
               break;

            case 4:
               iRet = Count(head);
               printf("Number of elements in Stack are : %d\n",iRet);
               break;

            case 0:
               printf("---Program Exited---\n");
               return 0;

            default:
               printf("Invalid Opiton\n");
               break;
        }

    }




    return 0;
}