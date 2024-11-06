#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    std::cout << vec.size() << vec.capacity() << std::endl; 
    vec.push_back(5);
    std::cout << vec.size() << vec.capacity() << std::endl; 
    vec.push_back(5);
    std::cout << vec.size() << vec.capacity() << std::endl; 
    vec.push_back(5);
    std::cout << vec.size() << vec.capacity() << std::endl; 

    return 0;
}