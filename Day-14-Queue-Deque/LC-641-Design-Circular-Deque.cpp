/*
--------------------------------------------------
Problem: LeetCode 641 - Design Circular Deque
Topic: Deque Design
Day: 14/50
Difficulty: Medium

Author: Nirnay Singh
--------------------------------------------------
*/

#include <iostream>
#include <deque>

using namespace std;

class MyCircularDeque {
private:
    deque<int> dq;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
    }

    bool insertFront(int value) {

        if(isFull())
            return false;

        dq.push_front(value);
        return true;
    }

    bool insertLast(int value) {

        if(isFull())
            return false;

        dq.push_back(value);
        return true;
    }

    bool deleteFront() {

        if(isEmpty())
            return false;

        dq.pop_front();
        return true;
    }

    bool deleteLast() {

        if(isEmpty())
            return false;

        dq.pop_back();
        return true;
    }

    int getFront() {

        if(isEmpty())
            return -1;

        return dq.front();
    }

    int getRear() {

        if(isEmpty())
            return -1;

        return dq.back();
    }

    bool isEmpty() {
        return dq.empty();
    }

    bool isFull() {
        return dq.size() == capacity;
    }
};

int main() {

    MyCircularDeque dq(3);

    cout << dq.insertLast(1) << endl;
    cout << dq.insertLast(2) << endl;
    cout << dq.insertFront(3) << endl;
    cout << dq.insertFront(4) << endl;

    cout << dq.getRear() << endl;

    cout << dq.isFull() << endl;

    cout << dq.deleteLast() << endl;

    cout << dq.insertFront(4) << endl;

    cout << dq.getFront() << endl;

    return 0;
}