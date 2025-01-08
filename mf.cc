
// main.cpp
#include "stack.hpp"
#include <iostream>

int main() {
    try {
        // Create a stack with a maximum capacity of 5
        mf::Stack stack(5);

        // Push elements onto the stack
        std::cout << "Pushing elements onto the stack...\n";
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();

        // Access the top element
        std::cout << "Top element: " << stack.top() << "\n";

        // Remove the top element
        std::cout << "Popping the top element...\n";
        stack.pop();
        stack.display();

        // Clear the stack
        std::cout << "Clearing the stack...\n";
        stack.clear();
        stack.display();

        // Check if the stack is empty
        if (stack.isEmpty()) {
            std::cout << "Stack is now empty.\n";
        }

        // Push more elements to demonstrate overflow handling
        std::cout << "Pushing elements until stack overflows...\n";
        stack.push(40);
        stack.push(50);
        stack.push(60);
        stack.push(70);
        stack.push(80);

        // Attempt to push beyond capacity
        stack.push(90); // This should throw an exception

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
