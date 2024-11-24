#include <climits>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* cur, int p_val, int q_val) {
        // 후손을 찾았음을 나타내는 플래그 어떻게? => 10^9보다 큰 INT_MAX 값 사용
        // 후손을 못 찾았음 => INT_MIN
        // 공통 조상을 찾은 경우 => 범위 내의 값
        // 1. 자기 자신도 후손이 될 수 있음
        int cur_found = 0;
        if (cur->val == p_val || cur->val == q_val) {
            cur_found = INT_MAX;
        }
        
        // 2. dfs로 후손 찾기
        int left_found = INT_MIN;
        if (cur->left != NULL) {
            left_found = dfs(cur->left, p_val, q_val);
        }
        int right_found = INT_MIN;
        if (cur->right != NULL) {
            right_found = dfs(cur->right, p_val, q_val);
        }

        // 3. 공통 조상인지 확인
        // 공통 조상인 경우
        if ((left_found == INT_MAX && right_found == INT_MAX) ||
            (cur_found == INT_MAX && left_found == INT_MAX) ||
            (cur_found == INT_MAX && right_found == INT_MAX)) {
            return cur->val;
        }
        // 공통 조상이 아닌 경우
        if (cur_found == INT_MAX || left_found == INT_MAX || right_found == INT_MAX) return INT_MAX;
        // 값 forward
        return left_found > right_found ? left_found : right_found;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1. cs - LCA에 대한 사전지식이 없는 상황에서는 시뮬레이션을 해서 규칙을 찾아본다.
        //  => 하나의 노드로 수렴하기 때문에 탐색할 때부터 규칙을 잘 세워서 탐색하고, 되돌아 올 때 마주치게 해본다.
        //  -> bfs로 시도해보다가 막혀서 그냥 dfs 재귀 돌림
        int res = dfs(root, p->val, q->val);
        return new TreeNode(res);
    }
};