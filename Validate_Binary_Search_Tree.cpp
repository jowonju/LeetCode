class Solution {
public:
    int FindMax(TreeNode* root){
        while(root->right != nullptr){
            root = root->right;
        }
        return root->val;
    }
    
    int FindMin(TreeNode* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root->val;
    }
    
    bool isValidBST(TreeNode* root) {        
        if(root == nullptr)
            return true;
        
        if(root->left != nullptr && FindMax(root->left) >= root->val)
        {
            return false;
        }
            
        if(root->right != nullptr && FindMin(root->right) <= root->val)
        {
            return false;
        }

        if(!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        
        return true;
    }

    //time: O(n), space: O(n)
    // Empty trees are valid BSTs.
    if (root == nullptr) {
        return true;
    }

    // The current node's value must be between low and high.
    if ((low != nullptr && root->val <= low->val) ||
        (high != nullptr && root->val >= high->val)) {
        return false;
    }

    // The left and right subtree must also be valid.
    return validate(root->right, root, high) &&
           validate(root->left, low, root);
};