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
    // 부모 노드를 입력으로 받아서 left와 right 자식 노드를 root로 하는 트리를 교환하고, 각 자식을 부모로 하는 swap 함수 재귀적으로 호출
    void swap(TreeNode* parent) {
        if (parent == nullptr) return;

        TreeNode* tmp = parent->left;
        parent->left = parent->right;
        parent->right = tmp;

        swap(parent->left);
        swap(parent->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        // 재귀? => stack overflow 발생하면 어떡함.. -> node 개수 최대 100개이므로 log100 이라 문제 없음.
        // 부모 기준으로 right와 left의 트리(val 값만 바꾸는 것x)를 계속 swap하면 됨
        swap(root);
        return root;
    }
};