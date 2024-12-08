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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. cs - 투 포인터로 각 list의 원소들 비교.
        //  => linked list에서 원소의 삽입 구현: 노드가 head, 중간, tail인 경우 나눠서 구현
        //  => 새로 만들어질 list에 포인터를 두면 tail 삽입 구현만으로도 쉽게 구현할 수 있다(three 포인터). 배열과 다르게 보조배열을 새롭게 정의하지 않고 기존 노드들의 reference만 바뀌는 것이므로 공간 복잡도는 여전히 O(1)이다.
        if (!list1) return list2;
        if (!list2) return list1;
        
        ListNode* new_list = NULL;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        // head
        if (ptr1->val <= ptr2->val) {
            new_list = ptr1;
            ptr1 = ptr1->next;
        } else {
            new_list = ptr2;
            ptr2 = ptr2->next;
        }
        ListNode* new_head = new_list;

        // tail에 삽입
        while (ptr1 && ptr2) {
            if (ptr1->val <= ptr2->val) {
                new_list->next = ptr1;
                new_list = new_list->next;
                ptr1 = ptr1->next;
            } else {
                new_list->next = ptr2;
                new_list = new_list->next;
                ptr2 = ptr2->next;
            }
        }
        
        if (!ptr1) {
            while (ptr2) {
                new_list->next = ptr2;
                new_list = new_list->next;
                ptr2 = ptr2->next;
            }
        }
        if (!ptr2) {
            while (ptr1) {
                new_list->next = ptr1;
                new_list = new_list->next;
                ptr1 = ptr1->next;
            }
        }

        return new_head;
    }
};