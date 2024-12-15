/*
// Definition for a Node..
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // child의 tail 찾아서 parent_next와 link (parent와 child는 이미 child 포인터로 연결되어 있음)
    void build(Node* parent) {
        Node* parent_next = parent->next;
        // link
        Node* cur = parent->child;
        parent->next = cur;
        cur->prev = parent;
        
        Node* child_tail = NULL;
        while (cur) {
            if (cur->child) {
                build(cur);
                cur->child = NULL;
            }
            if (!cur->next) child_tail = cur;
            cur = cur->next;
        }
        
        // link
        if (parent_next) {
            child_tail->next = parent_next;
            parent_next->prev = child_tail;
        }
        
        parent->child = NULL;
    }
    
    Node* flatten(Node* head) {
        // 1. cs - 구현 문제. doubly linked list의 삽입(head, 중간, tail)을 구현한다.
        // The nodes in the child list should appear after curr and before curr.next in the flattened list.
        // The nodes in the list must have all of their child pointers set to null.
        //  => 위 조건을 만족하기 위해서는 순회 순서를 잘 지켜야 하고, 포인터를 추가하면 쉽게 해결될 수도 있어보임.
        //  => head 삽입은 발생하지 않음. 대부분 중간노드 삽입이며, tail 삽입 조건을 찾아야 함
        //  -> depth가 증가하면서 같은 동작이 반복되고 bottom-up으로 최종 list를 만들수 있으므로 재귀로 풀어봄
        if (!head) return head;
        
        Node* cur = head;
        while (cur) {
            if (cur->child) {
                build(cur);
            }
            cur = cur->next;
        }
        
        return head;
        
        // @ 본래 linked list는 선형 탐색을 지원하는 선형 자료구조인데, 이 문제처럼 선형탐색을 할 수 없게 변형된 구조는 어떤 장점이 있는걸까? 실제로 쓰이는 자료구조인지?
        // => 이거 그냥 그래프(트리)임. 즉 이 문제는 비선형 자료구조를 선형 자료구조로 만들어보는 예제이다.
    }
};