// ////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name         : Binary Search Tree (BST)
// Description  : Impementing Binar Search Tree with operations like Insertion, Searching, Counting and etc.
// Input        : Integer
// Output       : Integer
// Author       : Omkar Mahadev Bhargude
// Date         : 05/08/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct node
{
    int data;
    struct node *Lchild;
    struct node *Rchild;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Insert(PPNODE first, int no);
void Inorder(PNODE first);
void Preorder(PNODE first);
void Postorder(PNODE first);
bool Search(PNODE first, int no);
int Count(PNODE first);
int CountLeafNodes(PNODE first);
int CountParentNodes(PNODE first);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Insert(
                PPNODE first,
                int no
            )
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->Lchild = NULL;
    newn->Rchild = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(1)
        {
            if(no == temp->data)
            {
                printf("Duplicate Element : Unable to insert data\n");
                free(newn);
                return;
            }
            else if(no > temp->data)
            {
                if(temp->Rchild == NULL)
                {
                    temp->Rchild = newn;
                    break;
                }
                temp = temp->Rchild;
            }
            else if(no < temp->data)
            {
                if(temp->Lchild == NULL)
                {
                    temp->Lchild = newn;
                    break;
                }

                temp = temp->Lchild;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Inorder :- 9  11  17
void Inorder(
                PNODE first
            )
{
    if(first != NULL)
    {
        Inorder(first->Lchild);
        printf("| %d | -> ",first->data);
        Inorder(first->Rchild);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Preorder :- 11  9  17
void Preorder(
                PNODE first
            )
{
    if(first != NULL)
    {
        printf("|  %d  | -> ",first->data);
        Preorder(first->Lchild);
        Preorder(first->Rchild);                // Use of Tree Recursion
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Postorder :- 9  17  11
void Postorder(
                PNODE first
            )
{
    if(first != NULL)
    {
        Postorder(first->Lchild);
        Postorder(first->Rchild);               // Use of Tree Recursion
        printf("|  %d  | -> ",first->data);

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Search(
                PNODE first, 
                int no
            )
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(no == first->data)
        {
            bFlag = true;
            break;
        }
        else if(no > first->data)
        {
            first = first->Rchild;
        }
        else if(no < first->data)
        {
            first = first->Lchild;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(
            PNODE first
        )
{
    static int iCount = 0;

    if(first != NULL)
    {
        iCount++;
        Count(first->Lchild);
        Count(first->Rchild);
    }

    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CountLeafNodes(
                    PNODE first
                )
{
    static int iCount = 0;

    if(first != NULL)
    {
        if(first->Lchild == NULL && first->Rchild == NULL)
        {
            iCount++;
        }
        CountLeafNodes(first->Lchild);
        CountLeafNodes(first->Rchild);
    }

    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CountParentNodes(
                        PNODE first
                    )
{
    static int iCount = 0;

    if(first != NULL)
    {
        if(first->Lchild != NULL && first->Rchild != NULL)
        {
            iCount++;
        }
        CountParentNodes(first->Lchild);
        CountParentNodes(first->Rchild);
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
    int iRet = 0;
    bool bRet = false;

    Insert(&head,11);
    Insert(&head,9);
    Insert(&head,17);
    Insert(&head,25);
    Insert(&head,7);
    Insert(&head,35);
    Insert(&head,10);

    Postorder(head);

    bRet = Search(head,25);

    if(bRet == true)
    {
        printf("\nELement is present\n");
    }
    else
    {
        printf("\nThere is no such element\n");
    }

    iRet = Count(head);

    printf("%d\n",iRet);

    return 0;
}