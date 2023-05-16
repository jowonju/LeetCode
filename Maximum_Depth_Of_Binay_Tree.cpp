class Solution {
public:
    int maxDepth(TreeNode* root) {

        //using recursion
        if(root == nullptr)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;

        //iterative traversal(Breath-f)
            int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int result = 0;
        
        queue<TreeNode*> treeQueue;
        
        treeQueue.push(root);
        
        while(!treeQueue.empty()) {
            result += 1;
            
            int size = treeQueue.size();
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                
                if(node->left != nullptr)
                {
                    treeQueue.push(node->left);    
                }
            
                if(node->right != nullptr)
                {
                    treeQueue.push(node->right);       
                }    
            }
            return result;   
        }
    }
};