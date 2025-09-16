#include<string.h>
#include<iostream>
using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////
//
// This is generic implementation of Binary Search Tree
//
//////////////////////////////////////////////////////////////////////////////////////////////
 
#define TRUE 1
#define FALSE 0

typedef int     BOOL;
//
//  Structure of Node
//
template<class T>
struct GEN_BST
{
    T data;                                  // Generic data s tored in node
    struct GEN_BST<T> * rightchild;         // rightchild node
    struct GEN_BST<T> * leftchild;          // leftchild node
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name       :   BST
//  Description      :   This is generic implementation of Binary Search Tree
//  Class Author     :   Omkar Mahadev Bhargude
//  Class Date       :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class BST
{
    public:

        struct GEN_BST<T> * p_Head;
        int iCount;

        BST();

        BOOL InsertNewNode(
                                T data
                             );
        
        void InorderTraversal(
                                GEN_BST<T> * first
                            );
        
        void PreorderTraversal(
                                GEN_BST<T> * first
                            );

        void PostorderTraversal(
                                GEN_BST<T> * first
                            );

        BOOL SearchNode(
                            T s_data
                         );

        int CountNode();

        BOOL CountLeafNode(
                                GEN_BST<T> *first
                          );

        BOOL CountParentNode(
                                GEN_BST<T> *first
                            );
};

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   BST
//  class Name           :   BinarySearchTree (BST)
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is constructor of class BST
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BST<T>::BST()
{
    this->p_Head = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   InsertNewNode()
//  class Name           :   BinarySearchTree (BST)
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   14/10/2025
//
//  Description          :   This function insert new node in BST
//
//  Input Parameter      :   [T] generic data
//
//  Returns              :   BOOLEAN
//                           If the function succeeds then it return TRUE.
//                           If the function fails then it return FALSE
//
//////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL BST<T>::InsertNewNode(
                                T no
                         )
{
    struct GEN_BST<T> * temp = NULL;
    struct GEN_BST<T> * newn = NULL;
    newn =  new GEN_BST<T>();

    newn->data =  no;
    newn->leftchild = NULL;
    newn->rightchild = NULL;

    if(p_Head == NULL)
    {
        p_Head = newn;
    }
    else
    {
        temp = p_Head;

        while(1)
        {
            if(temp -> data == no)
            {
                cout<<"[WARN] Duplicate Data : Unable to insert data\n";
                delete newn;
                return FALSE;
            }

            else if(no > temp->data)
            {
                if(temp->rightchild == NULL)
                {
                    temp -> rightchild = newn;
                    iCount++;
                    break;
                }

                temp = temp -> rightchild;
            }

            else if(no < temp -> data)
            {
                if(temp -> leftchild == NULL)
                {
                    temp -> leftchild = newn;
                    iCount++;
                    break;
                }

                temp = temp-> leftchild;
            }
        }
    }

    return TRUE;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   InorderTraversal
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   Performs an in-order traversal** of the binary search tree.
//                          Visits the nodes  (Left → Node → Right)
//                          and displays the value stored in each node.
//
//  Input Parameter     :    Node<T>* node
//                         
//  Return              :    void   
//
////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BST<T>::InorderTraversal(
                                GEN_BST<T> *first
                            )
{
    if(first != NULL)
    {
        InorderTraversal(first->leftchild);
        cout<<first->data<<" -> ";
        InorderTraversal(first->rightchild);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   PostorderTraversal
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   Performs an Psot-order traversal of the binary search tree.
//                          Visits the nodes (Left → Right → Node)
//                          and displays the value stored in each node.
//
//  Input Parameter     :    Node<T>* node
//                         
//  Return              :    void
//
////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BST<T>::PostorderTraversal(
                                    GEN_BST<T> *first
                                )
{
    if(first != NULL)
    {
        PostorderTraversal(first->leftchild);
        PostorderTraversal(first->rightchild);
        cout<<first->data<<" -> ";
    }
}


////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   PreorderTraversal
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   Performs an in-order traversal** of the binary search tree.
//                          Visits the nodes  (Node → Left → Right)
//                          and displays the value stored in each node.
//
//  Input Parameter     :    Node<T>* node
//                         
//  Return              :    void   
//
////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void BST<T>::PreorderTraversal(
                                    GEN_BST<T> *first
                                )
{
    if(first != NULL)
    {
        cout<<first->data<<" -> ";
        PostorderTraversal(first->leftchild);
        PostorderTraversal(first->rightchild);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CountNode()
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   This function counts the number of nodes present in BST
//
//  Input Parameter     :    NONE
//                         
//  Return              :    int 
//
////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountNode()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   SearchNode
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   This function searches the given data in BST
//
//  Input Parameter     :    [T] generic type
//                         
//  Return              :    BOOLEAN
//                           if the function succeeds it returns TRUE.
//                           if the function fails it returns FALSE.
//
////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL BST<T>::SearchNode(
                            T s_data
                        )
{
    struct GEN_BST<T> * temp = NULL;

    if(p_Head == NULL)
    {
        cout<<"[WARN] Cannot Search : BST is empty\n";
        return FALSE;
    }

    temp = p_Head;

    while(temp != NULL)
    {
        if(s_data == temp->data)
        {
            return TRUE;
            break;
        }

        else if(s_data  < temp->data)
        {
            temp = temp->leftchild;
        }

        else if(s_data > temp->data)
        {
            temp = temp->rightchild;
        }
    }

    return FALSE;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CountLeafNode ()
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   This function counts the total number of leaf nodes present in
//                          BinarySearchTree (BST)
//
//  Input Parameter     :   GEN_BST<T>* node
//                         
//  Return              :   int
//                          Returns the number total leaf nodes present
//
////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountLeafNode(
                            GEN_BST<T> *first
                        )
{
    static int iCount = 0;

    if(p_Head == NULL)
    {
        cout<<"[WARN] : BST is empty\n";
        return FALSE;
    }

    if(first != NULL)
    {
        if((first->leftchild == NULL) && (first->rightchild == NULL))
        {
            iCount++;
        }
        CountLeafNode(first -> leftchild);
        CountLeafNode(first -> rightchild);
    }
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CountParentNode ()
//  Class Name          :   BinarySearchTree (BST)
//  Author              :   Omkar Mahadev Bhargude
//  Date                :   14/09/2025
//
//  Description         :   This function counts the total number of Parent nodes present in
//                          BinarySearchTree (BST)
//
//  Input Parameter     :   GEN_BST<T>* node
//                         
//  Return              :   int
//                          Returns the number total parent nodes present
//
////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int BST<T>::CountParentNode(
                            GEN_BST<T> *first
                        )
{
    static int iCount = 0;

    if(p_Head == NULL)
    {
        cout<<"[WARN] : BST is empty\n";
        return FALSE;
    }
    
    if(first != NULL)
    {
        if((first->leftchild != NULL) || (first->rightchild != NULL))
        {
            iCount++;
        }
        CountParentNode(first -> leftchild);
        CountParentNode(first -> rightchild);
    }

    return iCount;
}
int main()
{
    BST<int> bobj;   // BST of integers
    int value = 0;
    int iRet = 0, choice = 0;
    BOOL bRet;

    while (1)
    {
        cout << "\n\n=================== BST MENU ===================\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Inorder Traversal\n";
        cout << "3. Display Preorder Traversal\n";
        cout << "4. Display Postorder Traversal\n";
        cout << "5. Search Element\n";
        cout << "6. Count Total Nodes\n";
        cout << "7. Count Leaf Nodes\n";
        cout << "8. Count Parent Nodes\n";
        cout << "0. Exit\n";
        cout << "==============================================\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> value;
            bobj.InsertNewNode(value);
            cout << value << " inserted successfully.\n";
            break;

        case 2:
            cout << "Inorder Traversal : ";
            bobj.InorderTraversal(bobj.p_Head);
            cout << "\n";
            break;

        case 3:
            cout << "Preorder Traversal : ";
            bobj.PreorderTraversal(bobj.p_Head);
            cout << "\n";
            break;

        case 4:
            cout << "Postorder Traversal : ";
            bobj.PostorderTraversal(bobj.p_Head);
            cout << "\n";
            break;
            
        case 5:
            cout << "Enter element to search : ";
            cin >> value;
            bRet = bobj.SearchNode(value);
            if (bRet == TRUE)
            {
                cout << value << " found in BST.\n";
            }
            else
            {
                cout << value << " not found in BST.\n";
            }
            break;

        case 6:
            iRet = bobj.CountNode();
            cout << "Total nodes : " <<iRet<< "\n";
            break;

        case 7:
            iRet = bobj.CountLeafNode(bobj.p_Head);
            cout << "Leaf nodes : " <<iRet<< "\n";
            break;

        case 8:
            iRet = bobj.CountParentNode(bobj.p_Head);
            cout << "Parent nodes : " <<iRet<< "\n";
            break;

        case 0:
            cout << "Exiting program. Thank you!\n";
            return 0;

        default:
            cout << "Invalid choice. Try again!\n";
        }
    }
    return 0;
}