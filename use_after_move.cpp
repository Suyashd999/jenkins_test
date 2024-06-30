#include <iostream>
#include <utility> // For std::move
#include <string>

void useAfterMove() {
    std::string str = "Hello, World!";
    std::string movedStr = std::move(str);

    // str is now in a valid but unspecified state
    std::cout << "Moved string: " << movedStr << std::endl;

    // Attempting to use str after it has been moved is a use after move problem
    // Uncommenting the following line can lead to undefined behavior
    // std::cout << "Original string after move: " << str << std::endl;
}

int main() {
    useAfterMove();
    return 0;
}
