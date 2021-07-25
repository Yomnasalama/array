// Below is the implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

class myArray
{
public:

    void rvereseArray(int arr[], int start, int end)
    {
        while (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    //Rearrange array in alternating positive & negative items with O(1) extra space
    void fill1(int a[], int neg, int pos)
    {
        if (neg % 2 == 1)
        {
            for(int i = 1; i < neg; i += 2)
            {
                int negative = a[i];
                int positive = a[i + neg];
                int temp = negative;
                a[i] = positive;
                a[i + neg] = temp;
            }
        }
        else
        {
            for(int i = 1; i <= neg; i += 2)
            {
                int negative = a[i];
                int positive = a[i + neg - 1];
                int temp = negative;
                a[i] = positive;
                a[i + neg - 1] = temp;
            }
        }
    }

    void fill2(int a[], int neg, int pos)
    {
        if (pos % 2 == 1)
        {
            for(int i = 1; i < pos; i += 2)
            {
                int positive = a[i];
                int negative = a[i + pos];
                int temp = positive;
                a[i] = negative;
                a[i + pos] = temp;
            }
        }
        else
        {
            for(int i = 1; i <= pos; i += 2)
            {
                int c = a[i];
                int d = a[i + pos - 1];
                int temp = c;
                a[i] = d;
                a[i + pos - 1] = temp;
            }
        }
    }

    void swapp(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void rearrangeFill(int arr[], int n)
    {
        int neg = 0, pos = 0;
        for(int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                neg++;
            else
                pos++;
        }

        sort(arr, arr + n);

        if (neg <= pos)
        {
            fill1(arr, neg, pos);
        }
        else
        {
            rvereseArray(arr, 0, n-1);
            fill2(arr, neg, pos);
        }
    }


    //Rearrange array such that even positioned are greater than odd
    void rearrange(int arr[], int n)
    {
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                if (arr[i] > arr[i - 1])
                    swapp(&arr[i - 1], &arr[i]);
            }
            else {
                if (arr[i] < arr[i - 1])
                    swapp(&arr[i - 1], &arr[i]);
            }
        }
    }

    //Rearrange positive and negative numbers with constant extra space
    void RearrangePosNeg(int arr[], int n)
    {
        int i = 0;
        int j = n - 1;
        while (true) {
            while (i < n && arr[i] < 0)
                i++;

            while (j >= 0 && arr[j] > 0)
                j--;

            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else
                break;
        }
    }

    //Move all negative numbers to beginning and positive to end with constant extra space
    void rearrange2(int arr[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                if (i != j)
                    swap(arr[i], arr[j]);
                j++;
            }
        }
    }

    //Rearrange array such that even index elements are smaller and odd index elements are greater
    void rearrange3(int* arr, int n)
    {
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 0 && arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);

            if (i % 2 != 0 && arr[i] < arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
    }

    //replace every element with the next greatest element
    void nextGreatest(int arr[], int size)
    {
        int max_from_right = arr[size-1];
        arr[size-1] = -1;

        for(int i = size-2; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = max_from_right;
            if(max_from_right < temp)
                max_from_right = temp;
        }
    }

    void print(int a[], int n)
    {
        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};
int main()
{
    myArray obj;
/*
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.print(arr, n);
    obj.rvereseArray(arr, 0, n-1);
    cout << "Reversed array is" << endl;
    obj.print(arr, n);*/



    /*int arr[] = { 2, 3, -4, -1, 6, -9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is ";
    obj.print(arr, n);
    obj.rearrangeFill(arr, n);
    cout << "Rearranged array is  ";
    obj.print(arr, n);*/




    /*int n = 5;
    int arr[] = { 1, 3, 2, 2, 5 };
    obj.rearrange(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";*/




    /*int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.RearrangePosNeg(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";*/




   /* int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    obj.rearrange2(arr, n);
    obj.print(arr, n);*/



    /*int arr[] = { 6, 4, 2, 1, 8, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before rearranging: \n";
    obj.print(arr, n);

    obj.rearrange3(arr, n);

    cout << "After rearranging: \n";
    obj.print(arr, n);*/



   /* int arr[] = {16, 17, 4, 3, 5, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    obj.nextGreatest (arr, size);
    cout << "The modified array is: \n";
    obj.print(arr, size);*/

}


