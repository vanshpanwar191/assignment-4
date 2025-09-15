#include <iostream>
using namespace std;

#define MAX 100


class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front++;
        }
        return val;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    
    void copyFrom(Queue &q) {
        front = q.front;
        rear = q.rear;
        for (int i = front; i <= rear; i++) {
            arr[i] = q.arr[i];
        }
    }
};


class StackTwoQ {
    Queue q1, q2;

public:
    void push(int x) {
        q2.enqueue(x);

        
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        
        Queue temp;
        temp.copyFrom(q1);
        q1.copyFrom(q2);
        q2.copyFrom(temp);
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << q1.dequeue() << endl;
    }

    void top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top: " << q1.getFront() << endl;
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};
class StackOneQ {
    Queue q;

public:
    void push(int x) {
        q.enqueue(x);
        int s = q.size();
        
        for (int i = 1; i < s; i++) {
            q.enqueue(q.dequeue());
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << q.dequeue() << endl;
    }

    void top() {
        if (q.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top: " << q.getFront() << endl;
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};
int main() {
    cout << "Stack using TWO Queues:\n";
    StackTwoQ s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.top();   
    s1.pop();   
    s1.top();   

    cout << "\nStack using ONE Queue:\n";
    StackOneQ s2;
    s2.push(100);
    s2.push(200);
    s2.push(300);
    s2.top(); 
    s2.pop();   
    s2.top();   

    return 0;
}
