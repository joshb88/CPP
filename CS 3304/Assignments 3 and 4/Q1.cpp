#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedStack.cpp"

int main() {
    LinkedStack<int> oddStack;
    LinkedStack<int> evenStack;
    std::ifstream inFile("input.txt");
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int num;
        while (iss >> num) {
            if (num % 2 == 0) {
                if (evenStack.isEmpty() || evenStack.peek() != num) {
                    evenStack.push(num);
                } else {
                    evenStack.pop();
                }
                std::cout << "Top of even stack: " << evenStack.peek() << std::endl;
            } else {
                if (oddStack.isEmpty() || oddStack.peek() != num) {
                    oddStack.push(num);
                } else {
                    oddStack.pop();
                }
                std::cout << "Top of odd stack: " << oddStack.peek() << std::endl;
            }
        }
    }
    inFile.close();
    return 0;
}