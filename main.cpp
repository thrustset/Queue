#include <iostream>
#include "queue.hpp"

int main() {
    auto queue = Queue();
    std::cout << queue << "\n";

    for(int i = 0; i <= MAXSIZE; i++) {
        queue.push(i + 1);
        std::cout << queue << "\n";
    }
    for(int i = 0; i < MAXSIZE / 2; i++) {
        queue.pop();
        std::cout << queue << "\n";
    }
    for(int i = 0; i < MAXSIZE / 2; i++) {
        queue.push(i + 1);
        std::cout << queue << "\n";
    }

    return 0;
}