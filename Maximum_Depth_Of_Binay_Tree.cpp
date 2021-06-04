using namespace std;
#include<iostream>

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int rightLength = 0;
        int leftLength = 0;
        int result = 0;

        rightLength = maxDepth(root->right);
        leftLength = maxDepth(root->left);

        result = 1 + (rightLength > leftLength ? rightLength : leftLength);

        return result;
    }
};

int main() {
    Solution sol;
    
    TreeNode node9(9);
    TreeNode node15(15);
    TreeNode node7(7);
    
    TreeNode node20(20, &node15, &node7);
    TreeNode node(3, &node9, &node20);

    std::cout << sol.maxDepth(&node) << std::endl;
}