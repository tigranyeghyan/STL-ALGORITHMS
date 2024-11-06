#include <iostream>
#include <string>

void sort(std::string& str)
{
    std::size_t size = str.size();
    std::size_t big = 0;

    for(int i = 0; i < size; ++i)
    {
        if(str[i] >=  'A' && str[i] <= 'Z')
        {
            std::swap(str[i], str[big++]);
        }
    }
}

int main()
{
    std::string str = "aADdJVasF";
    sort(str);
    std::cout << str << std::endl; 
    return 0;
}


