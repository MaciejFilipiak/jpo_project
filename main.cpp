#include <iostream>
#include "stack.hpp"

void displayMenu() {
    std::cout << "\nChoose an option:\n";
    std::cout << "1. Push (add) an element to the stack\n";
    std::cout << "2. Pop (remove) the top element from the stack\n";
    std::cout << "3. Display the number of elements on the stack\n";
    std::cout << "4. Clear the stack\n";
    std::cout << "5. Display stack contents\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice, value;
    int stackSize;

    std::cout << "Enter the stack capacity (or 0 for default capacity of 10): ";
    std::cin >> stackSize;

    mf::Stack stack = (stackSize == 0) ? mf::Stack() : mf::Stack(stackSize);

    do {
        displayMenu();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter a value to push onto the stack: ";
                    std::cin >> value;
                    stack.push(value);
                    std::cout << "Value pushed onto the stack.\n";
                    break;

                case 2:
                    stack.pop();
                    std::cout << "Top element removed from the stack.\n";
                    break;

                case 3:
                    std::cout << "Number of elements on the stack: " << stack.size() << "\n";
                    break;

                case 4:
                    stack.clear();
                    std::cout << "Stack cleared.\n";
                    break;

                case 5:
                    stack.display();
                    break;

                case 0:
                    std::cout << "Exiting the program. Goodbye!\n";
                    break;

                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }

    } while (choice != 0);

    return 0;
}
