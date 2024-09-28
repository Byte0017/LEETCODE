class MyCircularQueue {
public:
    int size;
    int* arr;
    int front;
    int rear;

    MyCircularQueue(int k) {
        this->size = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            // Queue is full
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = rear = -1;  // Reset queue to empty state
        } else {
            front = (front + 1) % size;
        }
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (front == 0 && rear == size - 1) || ((rear + 1) % size == front);
    }
};
