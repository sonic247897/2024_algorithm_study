/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. 수학 - list 길이의 배수만큼 이동하는 동작을 하면 원본 list와 똑같아지므로 생략해도 됨. list 길이제한에 비해 k가 매우 크므로 필요한 작업임.
        if (!head || !head->next) return head; // 길이가 0 또는 1인 경우 k 이동해도 똑같음.
        
        // 1) list의 길이를 구한다.
        int size = 2;
        ListNode* cur = head->next;
        while (cur->next) {
            size++;
            cur = cur->next;
        }
        ListNode* tail = cur;
        
        // 2) k % size 만큼 이동 - [size-k+1, size] 위치의 노드들을 통째로 list의 맨 앞에 삽입
        k %= size;
        int move = size - k;
        cur = head;
        while (--move > 0) {
            cur = cur->next;
        }
        // link
        tail->next = head;
        head = cur->next;
        cur->next = NULL; // new tail
         
        return head;
    }
};