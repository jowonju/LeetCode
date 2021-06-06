using namespace std;
#include<iostream>
#include<map>
#include<vector>
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
	
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    	
    }
};

int main()
{
    Solution sol;

    TreeNode one_node3(3);
    TreeNode two_node3(3);
    TreeNode node2(2);
    TreeNode node1(1);
    TreeNode node5(5);
    TreeNode node7(7);
    TreeNode node4(4);
	
    TreeNode root1(1, &one_node3, &node2);
    root1.left->left = &node5;
    TreeNode root2(2, &node1, &two_node3);
    root2.right->right = &node7;
    root2.left->right = &node4;
	
	TreeNode* test = sol.mergeTrees(&root1, &root2);
	
}