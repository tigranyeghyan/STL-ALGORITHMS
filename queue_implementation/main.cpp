#include <iostream>
#include "queue.h"

int main() {
    Queue<int> q;  // Create an empty queue of integers

    // Test empty and size on an empty queue
    std::cout << "Initial queue empty: " << std::boolalpha << q.empty() << std::endl;
    std::cout << "Initial queue size: " << q.size() << std::endl;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Test size after adding elements
    std::cout << "Queue size after 3 pushes: " << q.size() << std::endl;

    // Access and print front and back elements
    std::cout << "Front element: " << q.front() << std::endl;
    std::cout << "Back element: " << q.back() << std::endl;

    // Push more elements to test the queue behavior
    q.push(40);
    q.push(50);

    // Print updated front and back
    std::cout << "New front element: " << q.front() << std::endl;
    std::cout << "New back element: " << q.back() << std::endl;

    // Remove elements from the queue by moving the front
    std::cout << "Popping elements from the queue:" << std::endl;
    while (!q.empty()) {
        std::cout << "Front element: " << q.front() << ", Size: " << q.size() << std::endl;
        q.pop();
    }

    // Final state of the queue
    std::cout << "Final queue empty: " << q.empty() << std::endl;
    std::cout << "Final queue size: " << q.size() << std::endl;

    return 0;
}
