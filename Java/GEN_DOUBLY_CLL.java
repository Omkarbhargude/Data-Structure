///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name : Generic Doubly Circular Linkedlist
// Description : Implementing Doubly Circular LinkedList in Generic format with operations like Insertion, Deleteion, and traversal
// Input : Generic
// Output : Generic
// Author : Omkar Mahadev Bhargude
// Date : 14/07/2025
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

import java.util.Scanner;

class dnode<T>
{
    public dnode<T> prev;
    public T data;
    public dnode<T> next;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class DoublyCLL<T>
{
    private dnode<T> first;
    private dnode<T> last;
    private int iCount;

    public DoublyCLL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(
                                T no
                            )
    {
        dnode<T> newn = new dnode<T>();

        newn.data = no;
        newn.prev = null;
        newn.next = null;

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        first.prev = last;
        last.next = first;

        iCount++;
    }

    public void InsertLast( 
                                T no
                        )
    {
        dnode<T> newn = new dnode<T>();

        newn.data = no;
        newn.prev = null;
        newn.next = null;

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;

            last = newn;
        }

        first.prev = last;
        last.next = first;

        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = last;
            last.next = first;
        }

        iCount--;
    }

    public void DeleteLast()
    {
          if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;

            last.next = first;
            first.prev = last;
        }

        iCount--;
    }

    public void InsertAtPos(    
                                T no, 
                                int pos
                            )
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


    public void DeleteAtPos(
                                int pos
                            )
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

            iCount--;
        }
    }

    public void Display()
    {
        dnode<T> temp = first;

        System.out.print(" <=> ");
        do
        {
            System.out.print(" | "+temp.data+" | <=> ");

            temp = temp.next;
        }while(temp != first);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }
}

class DoublyCircularGeneric
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
            DoublyCLL<Integer> dobj1 = new DoublyCLL<>();

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
          DoublyCLL<Double> dobj2 = new DoublyCLL<>();

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
         DoublyCLL<String> dobj3 = new DoublyCLL<>();

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