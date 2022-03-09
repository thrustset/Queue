#pragma once

const int MAXSIZE = 10;

class Queue {
private:
    int *data;
    int size, head, tail;
public:
    Queue();
    ~Queue();

    auto isEmpty() const -> bool;
    auto isFull() const -> bool;

    static auto printEmpty() -> void;
    static auto printFull() -> void;

    auto push(int num) -> void;
    auto pop() -> void;



    auto friend operator<<(std::ostream &os, const Queue &queue) -> std::ostream &;
};