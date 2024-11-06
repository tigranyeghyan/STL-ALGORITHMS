#include <iostream>
#include "stack.h"

int main() {
    Stack<int> stack = {1, 3, 2, 5};
    Stack<int> stack1 = {1, 3, 2, 5};
    Stack<int> stack2 = std::move(stack1);

    stack.push(7);
    stack.push(8);
    stack.pop();
    size_t size = stack.size();

    for(size_t i = 0; i < size; ++i)
    {
        std::cout << stack.peek() << " ";
        stack.pop();
    }
    std::cout << std::endl;
    return 0;
}