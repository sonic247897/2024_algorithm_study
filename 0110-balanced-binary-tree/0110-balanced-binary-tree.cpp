/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node) {
        if (node->left == NULL && node->right == NULL) {
            return 1;    
        }

        int left_depth = 0;
        if (node->left != NULL) {
            left_depth = dfs(node->left);
        }
        int right_depth = 0;
        if (node->right != NULL) {
            right_depth = dfs(node->right);
        }
        // unbalance 트리가 하나라도 감지되면 탐색 종료
        if (left_depth == -1 || right_depth == -1) return -1;
        // balance 확인
        int balance = left_depth - right_depth;
        if (balance < -1 || balance > 1) return -1;
        // left, right 중 큰 값이 depth
        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }

    bool isBalanced(TreeNode* root) {
        // 모든 서브트리에 대해서 height 차이가 1 이하여야 true
        // 1. cs - 모든 노드에 대해서 왼쪽/오른쪽 depth를 비교해야 한다. 국소적인 계산과 큰 계산이 모두 필요함 => 재귀 dfs로 leaf 노드에서부터 세면서 올라온다.
        // (근데 binary tree는 좀 더 효율적인 탐색 알고리즘이 있지 않을까? -> dfs에서 visited 플래그 사용 안해도 되긴 함..)
        // *재귀 말고 stack으로 풀려면 어떻게?
        if (root == NULL) return true;

        int res = dfs(root);
        if (res == -1) return false;
        return true;
    }
};