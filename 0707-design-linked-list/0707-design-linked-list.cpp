class MyLinkedList {
private:
    // Definition for doubly-linked list.
    struct DoublyListNode {
        int val;
        DoublyListNode *prev;
        DoublyListNode *next;
        DoublyListNode(int x) : val(x), prev(NULL), next(NULL) {}
    };
    
    DoublyListNode *head;
    DoublyListNode *tail;
    int size;
    
public:
    MyLinkedList() : head(NULL), tail(NULL), size(0) {}
    
    // Get the value of the index`th node in the linked list. If the index is invalid, return -1.
    int get(int index) {
        if (index >= size) return -1;
        // head에서부터 index 번째까지 next 타고감
        DoublyListNode *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    // Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    void addAtHead(int val) {
        // 새로운 노드 초기화
        DoublyListNode *cur = new DoublyListNode(val);
        if (size == 0) {
            head = cur; tail = cur;
            size++;
            return;
        }
        // link
        cur->prev = NULL;
        cur->next = head;
        head->prev = cur;
        // head 변수 업데이트
        head = cur;
        size++;
    }
    
    // Append a node of value val as the last element of the linked list.
    void addAtTail(int val) {
        // 새로운 노드 초기화
        DoublyListNode *cur = new DoublyListNode(val);
        if (size == 0) {
            head = cur; tail = cur;
            size++;
            return;
        }
        // link
        cur->prev = tail;
        cur->next = NULL;
        tail->next = cur;
        // tail 변수 업데이트
        tail = cur;
        size++;
    }
    
    // Add a node of value val before the index`th node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
    void addAtIndex(int index, int val) {
        if (index > size) return;
        // 1) head
        if (index == 0) {
            addAtHead(val);
            return;
        }
        // 2) tail
        if (index == size) {
            addAtTail(val);
            return;
        }
        
        // 3) 중간 노드
        // 새로운 노드 초기화
        DoublyListNode *cur = new DoublyListNode(val);
        // 탐색
        DoublyListNode *tmp = head;
        for (int i = 0; i < index - 1; ++i) {
            tmp = tmp->next;
        }
        // link
        cur->prev = tmp;
        cur->next = tmp->next;
        tmp->next = cur;
        (cur->next)->prev = cur;
        size++;
    }

    // Delete the index`th node in the linked list, if the index is valid.
    // => deleteAtHead, deleteAtTail 함수가 필요한가? -> 간단해서 그냥 하나의 함수에 작성해도 될듯
    void deleteAtIndex(int index) {
        if (index >= size) return;
        // 1) head
        if (index == 0) {
            head = head->next;
            size--;
            return;
        }
        // 2) tail
        if (index == size - 1) {
            tail = tail->prev;
            size--;
            return;
        }
        
        // 3) 중간 노드
        // 탐색
        DoublyListNode *tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->next;
        }
        // link
        (tmp->prev)->next = tmp->next;
        (tmp->next)->prev = tmp->prev;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */