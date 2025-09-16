///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name : Generic Singly Linear Linkedlist
// Description : Implementing Singly Linear LinkedList in Generic format with operations like Insertion, Deleteion, and traversal
// Input : Generic
// Output : Generic
// Author : Omkar Mahadev Bhargude
// Date : 14/07/2025
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

class snode<T>
{
    public T data;
    public snode<T> next;
}

class SinglyLLL<T>
{
    private snode<T> first;
    private int iCount;

    public SinglyLLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(T no)
    {
        snode<T> newn = new snode<T>();

        newn.data = no;
        newn.next = null;

        newn.next = first;
        first = newn;

        iCount++;
    }

    public void InsertLast(T no)
    {
        snode<T> newn = new snode<T>();
        snode<T> temp = null;

        newn.data = no;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else
        {
            first = first.next;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        snode<T> temp = null;

        if(first == null)
        {
            return;
        }
        else
        {
            temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        iCount--;
    }

    public void InsertAtPos(T no, int pos)
    {
        int iCnt = 0;
        snode<T> newn = null;
        snode<T> temp = null;

        if((pos < 1) || (pos > iCount+1))
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount+1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new snode<T>();

            newn.data = no;
            newn.next = null;

            temp = first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            } 

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        int iCnt = 0;
        snode<T> temp = null;

        if((pos < 1) || (pos > iCount))
        {
            System.out.println("Invalid Position");
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
            temp = first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            iCount--;
        }
    }

    public void Display()
    {
        snode<T> temp = null;

        if(first == null)
        {
            System.out.println("Linked list is empty");
            return;
        }

        temp = first;

        while(temp != null)
        {
            System.out.print(" | "+temp.data+" | -> ");

            temp = temp.next;
        }

        System.out.println(" null ");
    }

    public int Count()
    {
        return iCount;
    }

}

class SinglyLinearGeneric
{
    public static void main(String A[])
    {
        int iDataChoice = 0;
        Scanner sobj = new Scanner(System.in);


       System.out.println("Enter the data type you want to insert : ");
       System.out.println("1 : Integer");
       System.out.println("2 : Double ");
       System.out.println("3 : String");

       iDataChoice = sobj.nextInt();

       if(iDataChoice == 1)
       {
            SinglyLLL<Integer> sobj1 = new SinglyLLL<>();

            int iRet = 0;
            int iPos = 0;
            int iValue = 0;
            int iChoice = 1;

            while(iChoice != 0)
          {
            System.out.println("\n========================================================================");
            System.out.println("------------------------- Select the Option ----------------------------");
            System.out.println("========================================================================");
            System.out.println("1 : Insert new node at first position");
            System.out.println("2 : Insert new node at last position");
            System.out.println("3 : Insert new node at given position");
            System.out.println("4 : Delete the node at first position");
            System.out.println("5 : Delete the node at last position");
            System.out.println("6 : Delete the node at given position");
            System.out.println("7 : Display elements from linkedlist");
            System.out.println("8 : Count the elements from linkedlist");
            System.out.println("0 : Terminate the application");
            System.out.println("========================================================================\n");

            System.out.println("Enter the option : ");
            iChoice = sobj.nextInt();
            System.out.println("-------------------------------------------------------------------------");

            switch(iChoice)
            {
                case 1:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    iValue = sobj.nextInt();
                    sobj1.InsertFirst(iValue);
                    break;

                case 2:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    iValue = sobj.nextInt();
                    sobj1.InsertLast(iValue);
                    break;

                case 3:

                    System.out.println("Enter the data : ");
                    iValue = sobj.nextInt();
                    System.out.println("Enter the Position : ");
                    iPos = sobj.nextInt();

                    sobj1.InsertAtPos(iValue,iPos);
                    break;

                case 4:
                    
                    System.out.println("Deleting first element....");
                    sobj1.DeleteFirst();
                    break;

                case 5:

                    System.out.println("Deleting last element : ");
                    sobj1.DeleteLast();
                    break;

                case 6:

                    System.out.println("Enter the position : ");
                    iPos = sobj.nextInt();
                    sobj1.DeleteAtPos(iPos);
                    break;

                case 7:

                    System.out.println("Elements from linkedlist are : ");
                    sobj1.Display();
                    break;

                case 8:
                    
                    iRet = sobj1.Count();
                    System.out.println("Number of elements are : "+iRet);
                    break;

                case 0:

                    System.out.println("--------------- Thanks for using our application -------------");
                    return;

                default:

                    System.out.println("Invalid Option");
                    break;

                }
            }
 
        }
        else if(iDataChoice == 2)
        {
          SinglyLLL<Double> sobj2 = new SinglyLLL<>();

            int iRet = 0;
            int iPos = 0;
            double iValue = 0;
            int iChoice = 1;

            while(iChoice != 0)
          {
            System.out.println("\n========================================================================");
            System.out.println("------------------------- Select the Option ----------------------------");
            System.out.println("========================================================================");
            System.out.println("1 : Insert new node at first position");
            System.out.println("2 : Insert new node at last position");
            System.out.println("3 : Insert new node at given position");
            System.out.println("4 : Delete the node at first position");
            System.out.println("5 : Delete the node at last position");
            System.out.println("6 : Delete the node at given position");
            System.out.println("7 : Display elements from linkedlist");
            System.out.println("8 : Count the elements from linkedlist");
            System.out.println("0 : Terminate the application");
            System.out.println("========================================================================\n");

            System.out.println("Enter the option : ");
            iChoice = sobj.nextInt();
            System.out.println("-------------------------------------------------------------------------");

            switch(iChoice)
            {
                case 1:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    iValue = sobj.nextDouble();
                    sobj2.InsertFirst(iValue);
                    break;

                case 2:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    iValue = sobj.nextDouble();
                    sobj2.InsertLast(iValue);
                    break;

                case 3:

                    System.out.println("Enter the data : ");
                    iValue = sobj.nextDouble();
                    System.out.println("Enter the Position : ");
                    iPos = sobj.nextInt();

                    sobj2.InsertAtPos(iValue,iPos);
                    break;

                case 4:
                    
                    System.out.println("Deleting first element....");
                    sobj2.DeleteFirst();
                    break;

                case 5:

                    System.out.println("Deleting last element : ");
                    sobj2.DeleteLast();
                    break;

                case 6:

                    System.out.println("Enter the position : ");
                    iPos = sobj.nextInt();
                    sobj2.DeleteAtPos(iPos);
                    break;

                case 7:

                    System.out.println("Elements from linkedlist are : ");
                    sobj2.Display();
                    break;

                case 8:
                    
                    iRet = sobj2.Count();
                    System.out.println("Number of elements are : "+iRet);
                    break;

                case 0:

                    System.out.println("--------------- Thanks for using our application -------------");
                    return;

                default:

                    System.out.println("Invalid Option");
                    break;

                }
            }
        }
       else if(iDataChoice == 3)
       {
         SinglyLLL<String> sobj3 = new SinglyLLL<>();

            int iRet = 0;
            int iPos = 0;
            int iChoice = 1;
            String str;

            while(iChoice != 0)
          {
            System.out.println("\n========================================================================");
            System.out.println("------------------------- Select the Option ----------------------------");
            System.out.println("========================================================================");
            System.out.println("1 : Insert new node at first position");
            System.out.println("2 : Insert new node at last position");
            System.out.println("3 : Insert new node at given position");
            System.out.println("4 : Delete the node at first position");
            System.out.println("5 : Delete the node at last position");
            System.out.println("6 : Delete the node at given position");
            System.out.println("7 : Display elements from linkedlist");
            System.out.println("8 : Count the elements from linkedlist");
            System.out.println("0 : Terminate the application");
            System.out.println("========================================================================\n");

            System.out.println("Enter the option : ");
            iChoice = sobj.nextInt();
            System.out.println("-------------------------------------------------------------------------");

            switch(iChoice)
            {
                case 1:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    sobj.nextLine();
                    str = sobj.nextLine();
                    sobj3.InsertFirst(str);
                    break;

                case 2:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    sobj.nextLine();
                    str = sobj.nextLine();
                    sobj3.InsertLast(str);
                    break;

                case 3:

                    System.out.println("Enter the data : ");
                    sobj.nextLine();
                    str = sobj.nextLine();
                    System.out.println("Enter the Position : ");
                    iPos = sobj.nextInt();

                    sobj3.InsertAtPos(str,iPos);
                    break;

                case 4:
                    
                    System.out.println("Deleting first element....");
                    sobj3.DeleteFirst();
                    break;

                case 5:

                    System.out.println("Deleting last element : ");
                    sobj3.DeleteLast();
                    break;

                case 6:

                    System.out.println("Enter the position : ");
                    iPos = sobj.nextInt();
                    sobj3.DeleteAtPos(iPos);
                    break;

                case 7:

                    System.out.println("Elements from linkedlist are : ");
                    sobj3.Display();
                    break;

                case 8:
                    
                    iRet = sobj3.Count();
                    System.out.println("Number of elements are : "+iRet);
                    break;

                case 0:

                    System.out.println("--------------- Thanks for using our application -------------");
                    return;

                default:

                    System.out.println("Invalid Option");
                    break;

                }
            }
        }
    }
}