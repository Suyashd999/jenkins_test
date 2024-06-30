#include <iostream>
#include <utility> // For std::move

class Resource {
public:
    Resource() : data(new int[10]) {
        std::cout << "Resource acquired.\n";
    }

    // Move constructor
    Resource(Resource&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Resource moved.\n";
    }

    // Move assignment operator
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete[] data; // Free existing resource
            data = other.data;
            other.data = nullptr;
            std::cout << "Resource moved (assignment).\n";
        }
        return *this;
    }

    ~Resource() {
        delete[] data;
        std::cout << "Resource destroyed.\n";
    }

    void print() const {
        if (data) {
            std::cout << "Resource is valid.\n";
        } else {
            std::cout << "Resource is moved-from and invalid.\n";
        }
    }

private:
    int* data;
};

void useAfterMoveExample() {
    Resource res1;
    res1.print();

    Resource res2 = std::move(res1); // Move res1 to res2
    res2.print();

    // Attempting to use res1 after move
    res1.print(); // res1 is now in an unspecified state
}

int main() {
    useAfterMoveExample();
    return 0;
    
}
