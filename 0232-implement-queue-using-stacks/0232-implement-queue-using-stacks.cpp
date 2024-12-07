// Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
//  => pop, peek: 스택의 가장 밑에 있는 원소를 꺼내와야 하는 op. 위에 있는 원소들을 다른 스택으로 옮겨야 한다.  
class MyQueue {
private:
    stack<int> in_stack;
    stack<int> out_stack;
public:
    MyQueue() {}
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        if (out_stack.empty()) {
            // in_stack 원소들 전부 out_stack으로 옮기기
            while (!in_stack.empty()) {
                int tmp = in_stack.top();
                in_stack.pop();
                out_stack.push(tmp);
            }
        }
        int res = out_stack.top();
        out_stack.pop();
        return res;
    }
    
    int peek() {
        if (out_stack.empty()) {
            // in_stack 원소들 전부 out_stack으로 옮기기
            while (!in_stack.empty()) {
                int tmp = in_stack.top();
                in_stack.pop();
                out_stack.push(tmp);
            }
        }
        return out_stack.top();        
    }
    
    bool empty() {
        if (in_stack.empty() && out_stack.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */