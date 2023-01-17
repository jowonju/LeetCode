class Solution {
public:
    //BFS(level-order traversal)
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> vec;
        
        if(root == nullptr)
            return vec;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty())
        {
            vector<int> vec2;
            int size = que.size();
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
            
                if(node->left != nullptr)
                    que.push(node->left);
                if(node->right != nullptr)
                    que.push(node->right);
                
                vec2.push_back(node->val);
                que.pop();
            }
            
            vec.push_back(vec2);
        }
        
        return vec;
    }

    //recursion
private:
    void recursion(TreeNode* root, int level, vector<vector<int>>& result) {
        if (!root) return;
        if (result.size() == level) {
            // add new vector to the result for new level
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        recursion(root->left, level + 1, result);
        recursion(root->right, level + 1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        recursion(root, 0, result);
        return result;
    }
    
};