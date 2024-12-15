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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. 수학적으로 reverse list를 정방향으로 순회하면서 각 노드를 더해나가는 것은 정수 덧셈 알고리즘과 같다.
        // 결과 list의 head 노드 추가
        int val = l1->val + l2-> val;
        ListNode* head = new ListNode(val % 10);
        ListNode* ptr3 = head;
        
        int carry = val/10;
        ListNode* ptr1 = l1->next;
        ListNode* ptr2 = l2->next;
        while (ptr1 || ptr2) {
            val = carry;
            if (ptr1) val += ptr1->val;
            if (ptr2) val += ptr2->val;
            carry = val/10;
            // tail에 삽입
            ptr3->next = new ListNode(val % 10);
            ptr3 = ptr3->next;
            
            if (ptr1) ptr1 = ptr1->next;
            if (ptr2) ptr2 = ptr2->next;
        }
        
        if (carry) ptr3->next = new ListNode(1);
        
        return head;
    }
};