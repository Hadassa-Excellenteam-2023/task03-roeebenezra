#pragma once

#include <iostream>
#include <list>
#include <exception>

// template comparator for template PriorityQueue
template<typename T>
struct MyComparator {
    T operator()(const T &a, const T &b) const {
        return a - b;
    }
};

template<typename T>
class PriorityQueue {

public:
    // push a new value into the queue
    void push(const T &t);

    // pop the value with the highest priority
    T poll();

private:
    std::list <T> m_data;
};

template<typename T>
void PriorityQueue<T>::push(const T &t) {
    // find the position to insert the new value based on its priority
    auto it = m_data.cbegin();
    while (it != m_data.cend() && MyComparator<T>()(*it, t) < 0) {
        ++it;
    }
    // insert the new value at the found position
    m_data.insert(it, t);
}

template<typename T>
T PriorityQueue<T>::poll() {
    if (m_data.empty()) {
        throw std::out_of_range("PriorityQueue is empty");
    }
    T item = m_data.front();
    m_data.pop_front();
    return item;
}