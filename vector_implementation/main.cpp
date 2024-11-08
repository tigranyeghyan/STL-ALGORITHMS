#include <iostream>
#include "vector.h" // Include your vector header file here

void test_constructors() {
    // Default constructor
    Vector<int> vec1;
    std::cout << "Default constructor: size = " << vec1.size() << "\n";

    // Constructor with size
    Vector<int> vec2(5);
    std::cout << "Size constructor: size = " << vec2.size() << "\n";

    // Constructor with size and initial value
    Vector<int> vec3(5, 42);
    std::cout << "Size and value constructor: ";
    for (size_t i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << "\n";

    // Initializer list constructor
    Vector<int> vec4{1, 2, 3, 4, 5};
    std::cout << "Initializer list constructor: ";
    for (size_t i = 0; i < vec4.size(); ++i) {
        std::cout << vec4[i] << " ";
    }
    std::cout << "\n";
}

void test_push_pop() {
    Vector<int> vec;
    vec.push_back(10);

    vec.push_back(20);
 
    vec.push_back(30);
    std::cout << "After push_back: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    vec.pop_back();
    std::cout << "After pop_back: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void test_accessors() {
    Vector<int> vec{10, 20, 30};

    std::cout << "Front element: " << vec.front() << "\n";
    std::cout << "Back element: " << vec.back() << "\n";

    vec[1] = 50;
    std::cout << "After modifying element at index 1: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
/*
    try {
        vec.at(10); // Out-of-range access
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught for out-of-range access: " << e.what() << "\n";
    }
*/
}

void test_copy_and_move() {
    // Copy constructor
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2 = vec1;
    std::cout << "After copy construction: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << "\n";

    // Move constructor
    Vector<int> vec3 = std::move(vec1);
    std::cout << "After move construction: ";
    for (size_t i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << "\n";

    // Copy assignment
    Vector<int> vec4;
    vec4 = vec3;
    std::cout << "After copy assignment: ";
    for (size_t i = 0; i < vec4.size(); ++i) {
        std::cout << vec4[i] << " ";
    }
    std::cout << "\n";

    // Move assignment
    Vector<int> vec5;
    vec5 = std::move(vec3);
    std::cout << "After move assignment: ";
    for (size_t i = 0; i < vec5.size(); ++i) {
        std::cout << vec5[i] << " ";
    }
    std::cout << "\n";
}

void test_insert_erase() {
    Vector<int> vec{1, 2, 3, 4, 5};
    vec.insert(2, 42); // Insert at position 2
    std::cout << "After insert at index 2: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    vec.erase(2); // Erase element at position 2
    std::cout << "After erase at index 2: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void test_resize_reserve() {
    Vector<int> vec(3, 10);
    vec.reserve(10);
    std::cout << "After reserve: capacity = " << vec.capacity() << "\n";

    vec.resize(5, 42);
    std::cout << "After resize: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    test_constructors();
    test_push_pop();
    test_accessors();
    test_copy_and_move();
    test_insert_erase();
    test_resize_reserve();

    std::cout << "All tests completed.\n";
    return 0;
}
