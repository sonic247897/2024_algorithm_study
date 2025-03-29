class MyCircularQueue {
private:
    vector<int> q;
    int head;
    int tail;

public:
    // Initializes the object with the size of the queue to be k.
    MyCircularQueue(int k) {
        q.reserve(k);
        head = -1;
        tail = -1; // 실제 마지막 원소를 가리킴
    }
    
    // Inserts an element into the circular queue. Return true if the operation is successful.
    bool enQueue(int value) {
        if (isFull()) return false;
        
        if (isEmpty()) { // 포인터 초기화
            head = 0;
        }
        tail = (tail + 1) % q.capacity();
        q[tail] = value;
        return true;
    }
    
    // Deletes an element from the circular queue. Return true if the operation is successful.
    bool deQueue() {
        if (isEmpty()) return false;
        
        // 큐가 empty 상태가 되면 포인터 초기화
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % q.capacity();
        }
        return true;
    }
    
    // Gets the front item from the queue. If the queue is empty, return -1.
    int Front() {
        if (isEmpty()) return -1;
        return q[head];
    }
    
    // Gets the last item from the queue. If the queue is empty, return -1.
    int Rear() {
        if (isEmpty()) return -1;
        return q[tail];
    }

    bool isEmpty() {
        return head == -1;
    }
    
    bool isFull() {
        // tail이 head 바로 직전 원소를 가리키는 상태면 full
        return (tail + 1) % q.capacity() == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */