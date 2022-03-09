#include <iostream>
#include "queue.hpp"

Queue::Queue() :
    size{0},
    head{0},
    tail{0}
{
    data = new int[MAXSIZE];
}

Queue::~Queue() {
    delete [] data;
}

auto Queue::isEmpty() const -> bool {
    if(size)
        return false;
    return true;
}

auto Queue::isFull() const -> bool {
    if(size == MAXSIZE)
        return true;
    return false;
}

auto Queue::printEmpty() -> void {
    std::cout << "Queue is empty!\n";
}

auto Queue::printFull() -> void {
    std::cout << "Error: queue is full!\n";
}

auto Queue::push(int num) -> void {
    if(isFull()) {
        printFull();
        return;
    }

    if(!isEmpty()) {
        tail++;
        if(tail == MAXSIZE)
            tail = 0;
    }

    data[tail] = num;
    size++;
}

auto Queue::pop() -> void {
    if(isEmpty()) {
        printEmpty();
        return;
    }

    if(size > 1) {
        head++;
        if(head == MAXSIZE)
            head = 0;
    }

    size--;
}

auto operator<<(std::ostream &os, const Queue &queue) -> std::ostream & {
    os << "size:\t" << queue.size << "\n";
    os << "head:\t" << queue.head << "\n";
    os << "tail:\t" << queue.tail << "\n";
    os << "queue:\t";

    if(queue.isEmpty()) {
        queue.printEmpty();
        return os;
    }

    if(queue.size == 1) {
        os << queue.data[queue.head] << "\n";
        return os;
    }

    int i = queue.head;
    while(true) {
        if(i == MAXSIZE)
            i = 0;

        os << queue.data[i] << " ";
        if(i == queue.tail)
            break;

        i++;
    }

    os << "\n";
    return os;
}
