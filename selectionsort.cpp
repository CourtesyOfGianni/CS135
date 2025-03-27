#include <iostream>
using namespace std;

void selection_sort(int a[], int size);

int main()
{
    int a[] = {11, 9, 17, 5, 12};
    int size = 5;
    selection_sort(a, size);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

void selection_sort(int a[], int size)
{ //outer loop goes through array and updates sorted region, adds elements to sorted region, initially empty
    for (int i = 0; i < size - 1; i++)
    { //go through array starting from first index, until size-2, last element is already sorted nothing to compare to
        int min_pos = i; //assuming first value is smallest value of array
        for (int j = i + 1; j < size; j++)
        { //check rest of elements to find one that is less than min pos
            if (a[j] < a[min_pos])
            { //if true
                min_pos = j; //update it to that element 
            } //stores smalles element of unsorted portion
        }
        if (min_pos != i)
        {
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        } //swap the elements inside the unsorted portion of array, update as sorted
    }   
}