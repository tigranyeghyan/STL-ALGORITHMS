#include <iostream>

void sort(int *arr, std::size_t size)
{
    size_t k = 0;

    for(size_t i = 0; i < size; ++i)
    {
        if(arr[i] < 0)
        {
            std::swap(arr[i], arr[k++]);
        }
    }
}

int main()
{
    
    int arr[] = {-12, 7, -5, 16, -9, 3, -8, 14, -1, 10};
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
    sort(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i)
    {
        std::cout << arr[i] << "  ";
    }
    return 0;
}
