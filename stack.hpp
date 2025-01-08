// stack.hpp
#pragma once
#include <stdexcept>
#include <iostream>

namespace mf {

class Stack {
private:
    int* data;          // Dynamic array to store stack elements
    int capacity;       // Maximum capacity of the stack
    int topIndex;       // Index of the top element (-1 if empty)

public:
    // Constructor
    Stack(int maxCapacity)
        : capacity(maxCapacity), topIndex(-1) {
        if (maxCapacity <= 0) {
            throw std::invalid_argument("Stack capacity must be greater than zero");
        }
        data = new int[maxCapacity];
    }

    // Destructor
    ~Stack() {
        delete[] data;
    }

    // Add an element to the stack
    void push(int value) {
        if (topIndex + 1 >= capacity) {
            throw std::overflow_error("Stack overflow: cannot push onto a full stack");
        }
        data[++topIndex] = value;
    }

    // Remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: cannot pop from an empty stack");
        }
        --topIndex;
    }

    // Clear the stack
    void clear() {
        topIndex = -1;
    }

    // Return the number of elements on the stack
    int size() const {
        return topIndex + 1;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Access the top element of the stack
    int top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: no top element");
        }
        return data[topIndex];
    }

    // Display the contents of the stack (for debugging/demo purposes)
    void display() const {
        std::cout << "Stack contents: ";
        for (int i = 0; i <= topIndex; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

} // namespace mf
