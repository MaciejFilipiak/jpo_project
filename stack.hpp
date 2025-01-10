#pragma once
#include <stdexcept>
#include <iostream>

namespace mf {

class Stack {
private:
    int* m_data;          // Dynamic array to store stack elements
    int m_capacity;       // Maximum m_capacity of the stack
    int m_topIndex;       // Index of the top element (-1 if empty)

public:
    // Default constructor
    Stack() : m_capacity(10), m_topIndex(-1) {
        m_data = new int[m_capacity];
    }

    // Parameterized constructor
    Stack(int maxm_capacity) 
        : m_capacity(maxm_capacity), m_topIndex(-1) {
        if (maxm_capacity <= 0) {
            throw std::invalid_argument("Stack m_capacity must be greater than zero");
        }
        m_data = new int[maxm_capacity];
    }

    // Destructor
    ~Stack() {
        delete[] m_data;
    }

    // Add an element to the stack
    void push(int value) {
        if (m_topIndex + 1 >= m_capacity) {
            throw std::overflow_error("Stack overflow: cannot push onto a full stack");
        }
        m_data[++m_topIndex] = value;
    }

    // Remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: cannot pop from an empty stack");
        }
        --m_topIndex;
    }

    // Clear the stack
    void clear() {
        m_topIndex = -1;
    }

    // Return the number of elements on the stack
    int size() const {
        return m_topIndex + 1;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return m_topIndex == -1;
    }

    // Access the top element of the stack
    int top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: no top element");
        }
        return m_data[m_topIndex];
    }

    // Display the contents of the stack (for debugging/demo purposes)
    void display() const {
        std::cout << "Stack contents: ";
        for (int i = 0; i <= m_topIndex; ++i) {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
};

} // namespace mf
