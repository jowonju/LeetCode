class Solution {
public:
    TreeNode* Construct(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return NULL;
        
        int mid = (right + left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = Construct(nums, left, mid - 1);
        node->right = Construct(nums, mid + 1, right);
        
        return node;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Construct(nums, 0, nums.size() - 1);
    }A
};