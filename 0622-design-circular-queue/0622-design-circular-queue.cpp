class MyCircularQueue {
public:
    int front = 0;
    int rear = 0;
    int size = 0;
    int count = 0;
    vector<int> q;

    MyCircularQueue(int k) {
        size = k;
        q.resize(k);
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        q[rear] = value;
        rear = (rear + 1) % size;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % size;
        count--;

        return true;
    }

    int Front() {
        return isEmpty() ? -1 : q[front];
    }

    int Rear() {
        return isEmpty() ? -1 : q[(rear - 1 + size) % size];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};