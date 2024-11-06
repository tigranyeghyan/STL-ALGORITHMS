#include <iostream>


template <typename T>
void insertion_sort(T *arr, int size)
{
    if(!arr || size <= 0)
    {
        return;
    }
    for (int i = 1; i < size; ++i)
    {
        int j = i - 1;
        T key = arr[i];
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


template <typename T>
void merge(T *arr, int left, int mid, int right)
{
    int l = mid - left + 1;
    int r = right - mid;
    T *leftArr = new T[l];
    T *rightArr = new T[r];
    for(int i = 0; i < l; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i < r; ++i)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left; 
    while(i < l && j < r)
    {
        if(leftArr[i] < rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }
    while(i < l)
    {
        arr[k++] = leftArr[i++];
    }
    while(j < r)
    {
        arr[k++] = rightArr[j++];
    }
    delete[]leftArr;
    delete[]rightArr;
}

template <typename T>
void merge_insertion(T *arr, int left, int right)
{
    if(right - left + 1 <= 32)
    {
        insertion_sort(arr + left, right + 1);
    }
    else
    {
        if(left < right)
        {
            int mid = left + (right - left) / 2;
            merge_sort(arr, left, mid);
            merge_sort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
}


template <typename T>
void print_array(T *arr, int size)
{
    if(size <= 0)
    {
        return;
    }
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}


int main()
{
    int arr[] = {0, 4, 2, 3, 5, 9, 2, 5, 6};
    print_array(arr, 9);
    merge_insertion(arr, 0, 8);
    print_array(arr, 9);
    return 0;
}

