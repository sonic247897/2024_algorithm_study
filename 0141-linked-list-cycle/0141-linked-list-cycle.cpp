/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 1. cs - 문제에 나온 그대로 next 포인터를 순회하면서 두 번 방문하는 노드가 있는지 확인한다.
        // Follow up: Can you solve it using O(1) (i.e. constant) memory?
        //  => val을 사용하지 않으므로 visited 플래그 값으로 덮어씌워도 된다. 0, 1은 원본 val이 가질수 있는 값이므로 플래그로 사용하려면 987654321 같은 값을 사용한다.
        if (head == NULL) return false;

        ListNode *cur = head;
        cur->val = 987654321;
        while (cur->next != NULL) {
            cur = cur->next;
            if (cur->val == 987654321) return true;
            cur->val = 987654321;
        }

        return false;
    }
};