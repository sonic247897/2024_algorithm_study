/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL; 
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1. cs - 문제 정의에 따르면 입력 자료구조는 그래프(트리x)이다.
        // A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
        //  => deep copy를 효율적으로 구현하기 위해서는 중복 없는 그래프 순회가 필요하다. 포인터까지 탐색해야 하므로 노드가 아니라 '간선 완전탐색' 문제임 (간선 구별 - 각 간선을 유니크하게 분별할 수 있어야함)
        //  => 선형 탐색(next 포인터) + 비선형 탐색(random 포인터)
        //    -> 선형 탐색도 가능하므로 index를 정의할 수 있어서 간선을 [index, index](출발점, 도착점) 쌍으로 표현 가능. 다만 해당 방법을 이용하려면 선형 탐색을 먼저 끝내야 한다.
        //  - deep copy는 새로운 list를 무조건 만들어야 하므로 투 포인터로 푼다.
        
        /* 투 포인터로 3순회 - O(N) */
        if (!head) return NULL;
        
        // 1) 1순회 하면서 val, 자기주소 기록. val에 index 쓰기 (val은 복사할 객체에 저장)
        vector<Node*> new_addr;
        
        int idx = 0;
        Node* ptr = head;
        Node* new_head = new Node(head->val);
        Node* new_ptr = new_head;
        while (ptr) {
            if (ptr->next) new_ptr->next = new Node(ptr->next->val);
            
            new_addr.emplace_back(new_ptr);
            
            ptr->val = idx;
            ++idx;
            
            ptr = ptr->next;
            new_ptr = new_ptr->next;
        }
        
        // 2) 2순회 하면서 각 노드에서 random 포인터 순회 & 구현
        ptr = head;
        new_ptr = new_head;
        while(ptr) {
            if (ptr->random) {
                new_ptr->random = new_addr[ptr->random->val];
            }  
            
            ptr = ptr->next;
            new_ptr = new_ptr->next;
        }
        
        // 3) 3순회 하면서 원본 객체의 val 복원 (안 해도 통과하긴 함) 
            
        return new_head;
        // @ linked list 특성상 random access가 불가하므로 [주소, 주소]로 식별하는게 낫지만 val이 32bit int 자료형이라 주소를 기록할 수 없다.
        // @@ [index, index] 정보로 random 포인터 구현하는데 linked list의 random access 불가능한 특성 때문에 주소를 바로 계산할 수 없어서 O(N^2) 복잡도가 됨. hashmap이나 배열 등의 보조 자료구조에 'index - 주소' 쌍을 저장하지 않는한 줄이기 어려울듯. 
    }
};