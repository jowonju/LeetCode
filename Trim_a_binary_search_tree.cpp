#include<iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return root;
        }

        if (root->left)
            root->left = trimBST(root->left, low, high);
        if (root->right)
            root->right = trimBST(root->right, low, high);

        if (root->val < low || root->val > high) {
            if (root->left) {
                root = root->left;
            }
            else if (root->right) { 
                root = root->right; 
            }
            else if (root->right == nullptr && root->left == nullptr) {
                root = nullptr;
            }

        }
        
        return root;
    }

};

int main() {
    Solution sol;

    TreeNode left(0);
    TreeNode right(4);

    TreeNode tree(3, &left, &right);
    tree.left->right = &TreeNode(2);
    tree.left->right->left = &TreeNode(1);
    
    sol.trimBST(&tree, 1, 3);
}