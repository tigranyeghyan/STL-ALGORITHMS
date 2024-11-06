#include <iostream>

void counting_sort(int *arr, int size)
{
    if(!arr || size <= 0)
    {
        return;
    }
    int min = *std::min_element(arr, arr + size);
    int max = *std::max_element(arr, arr + size);
    int range = max - min + 1;
    int *countArray = new int[range];
    for(int i = 0; i < size; ++i)
    {
        countArray[arr[i] - min]++;
    }
    for(int i = 1; i < range; ++i)
    {
        countArray[i] += countArray[i - 1];
    }

    int *outputArray = new int[size];
    for(int i = 0; i < size; ++i)
    {
        outputArray[countArray[arr[i] - min] - 1] = arr[i];
        countArray[arr[i] - min]--;
    }
    for(int i = 0; i < size; ++i)
    {
        arr[i] = outputArray[i];
    }
    delete []countArray;
    delete []outputArray;
}

void print_array(int *arr, int size)
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


void raddix_sort(int *arr, int size)
{
    int max = arr[0]; 
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    int k = 0;
    while(max)
    {
        k++;
        max /= 10;
    }
    for(int i = 0; i <= 6 ; ++i)
    {

    }
}

int main()
{
    int arr[] = {4521, 9765, 234, 567789, 3567, 78901, 56, 87654, 1, 65432};
    int size = sizeof(arr)/sizeof(int);
    print_array(arr, size);
    raddix_sort(arr, size); 
    print_array(arr, size);
    return 0;
}

