class Solution {
public:
    bool CheckMirror(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == nullptr || t2 == nullptr)
            return t1 == t2;

        if(t1->val != t2->val)
        {
            return false;
        }
        
        return CheckMirror(t1->left,t2->right) && CheckMirror(t1->right, t2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return CheckMirror(root->left, root->right);
    }
};