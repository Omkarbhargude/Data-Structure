#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int     BOOL;

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class           :   Sorting
//  Description     :   Generic implemention of Searching algorithms.
//  Author          :   Omkar Mahadev Bhargude
//  Date            :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Sorting
{
    public:

        int *Arr;
        int iSize;
        bool Sorted;

        Sorting(
                    int A                           // Parametrised constructor
                );
    
        ~Sorting();                                 // Destructor

        void AcceptElement();

        void DisplayElement();

        
        BOOL BubbleSort();

        BOOL BubbleSortEfficient();

        BOOL InsertionSort();

        BOOL SelectionSort();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Sorting ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is parametrised constructor of class Sorting
//  Input Parameter      :   int
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Sorting<T>::Sorting(
                        int A
                    )
{
    this->iSize = A;
    this->Arr = new int[iSize];
    this->Sorted = true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   ~Sorting ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is destructor of class Sorting
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Sorting<T>::~Sorting()
{
    delete []Arr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Accpet()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//
//  Description          :   This function accpets input from user and store it in array
//
//  Input Parameter      :   [T] generic type
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Sorting<T>::AcceptElement()
{
    int i = 0;

    cout<<"Enter "<<iSize<<" elements : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter element no : "<<i+1<<"\n";
        cin>>Arr[i];

        if((i > 0) && (Sorted == true))
        {
            if(Arr[i] < Arr[i - 1])
            {
                Sorted = false;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Display()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//
//  Description          :   This function displays the array
//
//  Input Parameter      :   NONE
//
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Sorting<T>::DisplayElement()
{
    int i = 0;

    cout<<"Elements from array are : \n";
    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }

    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BubbleSort()
//  class Name          :   class Sorting
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Sorts an array of elements in ascending order using the Bubble Sort algorithm by
//                          repeatedly swapping adjacent elements if they are in the wrong order.
//                          
//  Input               :   NONE
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Sorting<T>::BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;

    // Filter
    if(Sorted == true)
    {
        return TRUE;
    }

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize - 1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout<<"[INFO] Data after pass : "<<i + 1<<"\n";
        DisplayElement();
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BubbleSortEfficient()
//  class Name          :   class Sorting
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   sorts an array in ascending order using an optimized Bubble Sort algorithm that stops
//                          early if no swaps are made in a pass, improving efficiency for nearly sorted array
//                          
//  Input               :   NONE
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Sorting<T>::BubbleSortEfficient()
{
    int i = 0, j = 0, temp = 0;
    bool bFlag = false;

    // Filter
    if(Sorted == true)
    {
        return TRUE;
    }

    for(i = 0; (i < iSize && bFlag == true); i++)
    {
        for(j = 0; j < iSize -1; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;

                bFlag = false;
            }
        }

        cout<<"[INFO] Data after pass : "<<i + 1<<"\n";
        DisplayElement();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   SelectionSort()
//  class Name          :   class Sorting
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   sorts an array in ascending order by repeatedly selecting the minimum element from 
//                          the unsorted portion and placing it at its correct position
//                          
//  Input               :   NONE
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Sorting<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for(i = 0; i < iSize - 1; i++)
    {   
        min_index = i;
        for(j = i + 1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }

        }
        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   InsertionSort()
//  class Name          :   class Sorting
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Sorts an array in ascending order by repeatedly picking the next element and 
//                          inserting it into its correct position in the already sorted portion of the array.
//                          
//  Input               :   NONE
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Sorting<T>::InsertionSort()
{
    int i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i - 1, selected = Arr[i]; (j >= 0 && Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }

        Arr[j + 1] = selected;
    }

    return TRUE;
}

int main()
{
    int i = 0;

    cout<<"Enter the size of array : \n";
    cin>>i;

    Sorting<int> sobj(i);

    sobj.AcceptElement();
    sobj.DisplayElement();
    sobj.BubbleSort();

    return 0;
}