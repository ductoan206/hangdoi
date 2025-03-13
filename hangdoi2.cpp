#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    bool isEmpty() {
        return (front == nullptr);
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.peek();
    q.dequeue();
    q.peek();
    return 0;
}

