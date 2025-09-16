///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name : Generic Doubly Linear Linkedlist
// Description : Implementing Doubly Linear LinkedList in Generic format with operations like Insertion, Deleteion, and traversal
// Input : Generic
// Output : Generic
// Author : Omkar Mahadev Bhargude
// Date : 14/07/2025
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

class dnode<T>
{
    public T data;
    public dnode<T> next;
    public dnode<T> prev;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class DoublyLLL<T>
{
    private dnode<T> first;
    private int iCount;

    public DoublyLLL()
    {
        this.first = null;
        this.iCount = 0;
    }


    public void InsertFirst(T no)
    {
        dnode<T> newn = new dnode<T>();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;

            first = newn;
        }

        iCount++;
    }

    public void InsertLast(T no)
    {
        dnode<T> newn = new dnode<T>();
        dnode<T> temp = null;

        newn.data = no;
        newn.next = null;
        newn.prev = null;

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

            newn.prev = temp;
        }

        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;

            first.prev = null;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        dnode<T> temp = null;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
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
        dnode<T> newn = null;
        dnode<T> temp = null;

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
            newn = new dnode<T>();

            newn.data = no;
            newn.next = null;
            newn.prev = null;

            temp = first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;

            newn.prev = temp;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        int iCnt = 0;
        dnode<T> temp = null;
        dnode<T> target = null;

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

            target = temp.next;

            temp.next = target.next;
            target.next.prev = temp;

            target = null;

            iCount--;
        }
    }

    public void Display()
    {
        dnode<T> temp = first;

        System.out.print("null <=>");
        while(temp != null)
        {
            System.out.print(" | "+temp.data+" | <=> ");

            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }
}


public class DoublyLinearGeneric 
{
    public static void main(String[] args) 
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
            DoublyLLL<Integer> dobj1 = new DoublyLLL<>();

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
                    dobj1.InsertFirst(iValue);
                    break;

                case 2:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    iValue = sobj.nextInt();
                    dobj1.InsertLast(iValue);
                    break;

                case 3:

                    System.out.println("Enter the data : ");
                    iValue = sobj.nextInt();
                    System.out.println("Enter the Position : ");
                    iPos = sobj.nextInt();

                    dobj1.InsertAtPos(iValue,iPos);
                    break;

                case 4:
                    
                    System.out.println("Deleting first element....");
                    dobj1.DeleteFirst();
                    break;

                case 5:

                    System.out.println("Deleting last element : ");
                    dobj1.DeleteLast();
                    break;

                case 6:

                    System.out.println("Enter the position : ");
                    iPos = sobj.nextInt();
                    dobj1.DeleteAtPos(iPos);
                    break;

                case 7:

                    System.out.println("Elements from linkedlist are : ");
                    dobj1.Display();
                    break;

                case 8:
                    
                    iRet = dobj1.Count();
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
          DoublyLLL<Double> dobj2 = new DoublyLLL<>();

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
                    dobj2.InsertFirst(iValue);
                    break;

                case 2:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    iValue = sobj.nextDouble();
                    dobj2.InsertLast(iValue);
                    break;

                case 3:

                    System.out.println("Enter the data : ");
                    iValue = sobj.nextDouble();
                    System.out.println("Enter the Position : ");
                    iPos = sobj.nextInt();

                    dobj2.InsertAtPos(iValue,iPos);
                    break;

                case 4:
                    
                    System.out.println("Deleting first element....");
                    dobj2.DeleteFirst();
                    break;

                case 5:

                    System.out.println("Deleting last element : ");
                    dobj2.DeleteLast();
                    break;

                case 6:

                    System.out.println("Enter the position : ");
                    iPos = sobj.nextInt();
                    dobj2.DeleteAtPos(iPos);
                    break;

                case 7:

                    System.out.println("Elements from linkedlist are : ");
                    dobj2.Display();
                    break;

                case 8:
                    
                    iRet = dobj2.Count();
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
         DoublyLLL<String> dobj3 = new DoublyLLL<>();

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
                    dobj3.InsertFirst(str);
                    break;

                case 2:
                    
                    System.out.println("Enter the data that you want to insert : ");
                    sobj.nextLine();
                    str = sobj.nextLine();
                    dobj3.InsertLast(str);
                    break;

                case 3:

                    System.out.println("Enter the data : ");
                    sobj.nextLine();
                    str = sobj.nextLine();
                    System.out.println("Enter the Position : ");
                    iPos = sobj.nextInt();

                    dobj3.InsertAtPos(str,iPos);
                    break;

                case 4:
                    
                    System.out.println("Deleting first element....");
                    dobj3.DeleteFirst();
                    break;

                case 5:

                    System.out.println("Deleting last element : ");
                    dobj3.DeleteLast();
                    break;

                case 6:

                    System.out.println("Enter the position : ");
                    iPos = sobj.nextInt();
                    dobj3.DeleteAtPos(iPos);
                    break;

                case 7:

                    System.out.println("Elements from linkedlist are : ");
                    dobj3.Display();
                    break;

                case 8:
                    
                    iRet = dobj3.Count();
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
