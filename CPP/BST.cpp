// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name : Binary Search Tree
// Description : Impementing Binar Search Tree with operations like Insertion, Searching, Counting and etc.
// Input : Integer
// Output : Integer
// Author : Omkar Mahadev Bhargude
// Date : 05/08/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

//
//  node structure
//
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

//
//  typedef
//
typedef struct node NODE;
typedef struct node * PNODE;

///////////////////////////////////////////////////////////////////////////////////////////////
class BST
{
    public:

    PNODE first;
    int iCount;

    BST();

    void Insert(
                int no
            );

    void Inorder(PNODE temp);

    void Preorder(PNODE temp);

    void Postorder(PNODE temp);

    bool Search(
                    int no
                );

    int CountLeafNodes(
                        PNODE temp
                    );
    
    int CountParentNodes(
                            PNODE temp
                        );

};

///////////////////////////////////////////////////////////////////////////////////////////////

BST::BST()
{
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BST :: Insert(
                        int no
                    )
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = new NODE;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate Element : Unable to insert data\n";
                delete newn;
                return;
            }
            else if(no > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }

                temp = temp->lchild;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BST :: Inorder(
                        PNODE temp
                    )
{   
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        cout<<"| "<<temp->data<<" | -> ";
        Inorder(temp->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BST :: Preorder(
                        PNODE temp
                    )
{
    if(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        Inorder(temp->lchild);
        Inorder(temp->rchild);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BST :: Postorder(  
                        PNODE temp
                    )
{
    if(temp != NULL)
    {
        Inorder(temp->lchild);
        Inorder(temp->rchild);
        cout<<"| "<<temp->data<<" | -> ";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool BST :: Search(
                        int no
                    )
{
    PNODE temp = first;
    bool bFlag = false;

    while(temp != NULL)
    {
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int BST :: CountLeafNodes(
                            PNODE temp
                        )
{
    static int iCount = 0;

    if(temp != NULL)
    {
        if(temp->lchild == NULL && temp->rchild == NULL)
        {
            iCount++;
        }
        CountLeafNodes(temp->lchild);
    }

    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int BST :: CountParentNodes(
                                PNODE temp
                            )
{
    static int iCount = 0;

    if(temp != NULL)
    {
        if(temp->lchild != NULL && temp->rchild != NULL)
        {
            iCount++;
        }

        CountParentNodes(temp->lchild);
        CountParentNodes(temp->rchild);
    }

    return iCount;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    BST bobj;
    int iRet = 0;

    bobj.Insert(11);
    bobj.Insert(9);
    bobj.Insert(17);
    bobj.Insert(25);
    bobj.Insert(7);
    bobj.Insert(35);
    bobj.Insert(10);

    bobj.Postorder(bobj.first);

    iRet = bobj.CountLeafNodes(bobj.first);

    cout<<iRet<<"\n";

    

    return 0;
}