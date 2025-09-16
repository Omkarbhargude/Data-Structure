#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Enqueue(PPNODE first, int no)                   // InerstLast()
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

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

    }

}

int Dequeue(PPNODE first)                           // DeleteFirst()
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*first == NULL)
    {
        printf("Unable to remove the element as queue is empty\n\n");
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

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|  %d  | -",first->data);

        first = first->next;
    }

    printf("\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;

        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    printf("================================================\n");
    printf("=========== Queue using Singly Linear ==========\n");
    printf("================================================\n");

    while(iChoice != 0)
    {
        printf("\n=============================================\n");
        printf("------------- Select the option --------------\n");
        printf("==============================================\n");
        printf("1 : Enqueue new node \n");
        printf("2 : Dequeue first node\n");
        printf("3 : Display elements from queue\n");
        printf("4 : Count the elements from queue\n");
        printf("0 : Terminate Program\n");
        printf("===============================================\n");

        printf("Enter the Option : \n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the data that you want insert : \n");
                scanf("%d",&iValue);
                Enqueue(&head,iValue);
                break;

            case 2:
                printf("Removing first Element from Queue\n\n");
                iRet = Dequeue(&head);

                printf("Removed Element is : %d\n",iRet);
                break;

            case 3:
                Display(head);
                break;

            case 4:
                iRet = Count(head);
                printf("Number of elements in Queue are : %d\n",iRet);
                break;

            case 0:
               printf("--Program Exited--\n");
               return 0;

            default:
               printf("Invalid Choice\n");
               break;
        }

    }

    return 0;
}