#include<iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class           :   Searching 
//  Description     :   Generic implemention of Searching algorithms.
//  Author          :   Omkar Mahadev Bhargude
//  Date            :   15/10/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Searching
{
    public:

        int *Arr;
        int iSize;
        bool Sorted;

        Searching(
                    int A
                );

        ~Searching();

        void Accept();

        void Display();

        bool LinearSearch(
                            T data
                        );

        bool BiDirectionalSearch(
                                    T data
                                );
                    
        bool BinarySearchInc(
                                T data
                            );

        bool BinarySearchDec(
                                T data
                            );

        bool BinarySearchEfficientInc(
                                        T data
                                    );

        bool BinarySearchEfficientDec(
                                        T data
                                    );

        bool CheckSortedInc();

        bool CheckSortedDec();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   Searching
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is parametrised constructor of class Searching
//  Input Parameter      :   int 
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Searching<T>::Searching(int A)
{
    this->iSize = A;
    this->Arr = new int[iSize];
    this->Sorted = true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name        :   ~Searching ()
//  Function Author      :   Omkar Mahadev Bhargude
//  Function Date        :   15/10/2025
//  Description          :   This is destructor of class Searching
//  Input Parameter      :   NONE
//  Returns              :   NONE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
Searching<T>::~Searching()
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
void Searching<T>::Accept()
{
    int i = 0;
    cout<<"Enter "<<iSize<<" elements : \n";

    for(i = 0; i < iSize; i++)
    {
        cout<<"Enter element s_data : "<<i+1<<"\n";
        cin>>Arr[i];

        // If the the current data is less then previous data then it s_data sorted
        // data should be in asec order -> -> ->
        // [12,24,43,65,89] -> sorted data
        // [11,45,32,78,12,7] -> Unsorted data

        if((Arr[i] < Arr[i - 1]))
        {
            Sorted = false;
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
//  Input Parameter      :   [T] generic type
//
//  Returns              :   s_dataNE
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Searching<T>::Display()
{   
    int i = 0;
    cout<<"Elements of the array are : \n";

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   LinearSearch
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Searches for a given element in the given array using the Linear Search algorithm.
//                          It scans each element sequentially from the beginning until the given element is 
//                          found. if array is sorted it used efficient binary search algorithm
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
//  Time Complexity     :
//        Best Case    : O(1)   -> When the element is at the first position.
//        Worst Case   : O(n)   -> When the element is at the end or s_datat present.
//        Average Case : O(n)
//  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::LinearSearch(
                                    T s_data
                                )
{
    int i = 0;
    bool bFlag = false;

    if(Sorted == true)
    {
        cout<<"[INFO] Data is Sorted : Using BinarySearchEfficientInc\n";
        return BinarySearchEfficientInc(s_data);
    }

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == s_data)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BiDirectionalSearch()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Searches for a given element from both the end simultaneously
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BiDirectionalSearch(
                                            T s_data
                                    )
{
    int istart = 0, iend = 0;
    bool bFlag = false;

    if(Sorted == true)
    {
        cout<<"[INFO] Data is Sorted : Using BinarySearchEfficientInc\n";
        return BinarySearchEfficientInc(s_data);
    }

    for(istart = 0, iend = iSize -1; istart <= iend; istart++,iend--)
    {
        if((Arr[istart] == s_data) || (Arr[iend] == s_data))
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BinarySearchInc()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Searches for a given element in a sorted (increasing order) array using the
//                          Binary Search algorithm.
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BinarySearchInc(
                                        T s_data
                                )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == s_data)
        {
            bFlag = true;
            break;
        }
        else if(s_data < Arr[iMid])         // First half (Left Window)
        {
            iEnd = iMid - 1;
        }
        else if(s_data > Arr[iMid])         // Second half (Right Window)
        {
            iStart = iMid + 1;
        }
    }   // End of While
    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BinarySearchDec()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Searches for a given element in a sorted (Decreaing order) array using the
//                          Binary Search algorithm.
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BinarySearchDec(
                                        T s_data
                                    )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == s_data)
        {
            bFlag = true;
            break;
        }
        else if(s_data > Arr[iMid])         // First half (Left Window)
        {
            iEnd = iMid - 1;
        }
        else if(s_data < Arr[iMid])         // Second half (Right Window)
        {
            iStart = iMid + 1;
        }
    }   // End of While
    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BinarySearchEfficientInc()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Efficiently searches for a given element in a sorted (increasing order) array
//                          using the Binary Search algorithm. Uses an mid-point calculation to
//                          avoid overflow and reduces the search .
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BinarySearchEfficientInc(
                                                T s_data
                                            )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(Sorted == false)       // New
    {
        cout<<"[INFO] Data is s_datat sorted : Using Linear Search Algorithm\n";
        
        return LinearSearch(s_data);            // IMP Change
    }

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == s_data || Arr[iStart] == s_data || Arr[iEnd] == s_data))         // Change
        {
            bFlag = true;
            break;
        }
        else if(s_data < Arr[iMid])         // First half (Left Window)
        {
            iEnd = iMid - 1;
        }
        else if(s_data > Arr[iMid])         // Second half (Right Window)
        {
            iStart = iMid + 1;
        }
    }   // End of While
    return bFlag;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   BinarySearchEfficientDec()
//  class Name          :   class Searching
//  Author Name         :   Omkar Mahadev Bhargude
//  Function Date       :   15/10/2025
//
//  Description         :   Efficiently searches for a given element in a sorted (Decreasing order) array
//                          using the Binary Search algorithm. Uses an mid-point calculation to
//                          avoid overflow and reduces the search .
//                          
//  Input               :   [T] generic type (element to search)
//
//  Return              : BOOLEAN
//                        If the function succeeds it return TRUE;
//                        If the function fails it return FASLE;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::BinarySearchEfficientDec(
                                                T s_data
                                            )
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if((Arr[iMid] == s_data || Arr[iStart] == s_data || Arr[iEnd] == s_data))         // Change
        {
            bFlag = true;
            break;
        }
        else if(s_data > Arr[iMid])         // First half (Left Window)
        {
            iEnd = iMid - 1;
        }
        else if(s_data < Arr[iMid])         // Second half (Right Window)
        {
            iStart = iMid + 1;
        }
    }   // End of While
    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CheckSortedInc()
//  Function Date       :   15/09/2025
//  Function Author     :   Omkar Mahadev Bhargude
//  Parameters          :   NONE
//  Description         :   Checks if array is sorted in Increasing order
//  Returns             :   bool
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::CheckSortedInc()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] < Arr[i - 1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name       :   CheckSortedDec()
//  Function Date       :   15/09/2025
//  Function Author     :   Omkar Mahadev Bhargude
//  Parameters          :   NONE
//  Description         :   Checks if array is sorted in Decreasing order
//  Returns             :   bool
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
bool Searching<T>::CheckSortedDec()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] < Arr[i + 1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}
int main()
{
   int iLength = 0;
    int iValue = 0;
    bool bRet = false;

    cout<<"Enter the size of array : \n";
    cin>>iLength;

    Searching<int> *aobj = new Searching<int>(iLength);

    aobj->Accept();
    aobj->Display();

    
    return 0;
}