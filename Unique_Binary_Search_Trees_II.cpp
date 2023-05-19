class Solution {
public:
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> result;
        
        if(start > end)
        {
            result.push_back(nullptr);
            return result; 
        }
            
        for(int i = start; i <= end; i++){
        
            auto leftSubTree = generate(start, i-1);
            auto rightSubTree = generate(i+1, end);
            
            for(int j = 0; j < leftSubTree.size(); j++) {
			    for(int k = 0; k < rightSubTree.size(); k++) {
				    TreeNode* root = new TreeNode(i);   // Create root with value i
				    root->left = leftSubTree[j];   // Connect left subtree rooted at leftSubTree[j]
                    root->right = rightSubTree[k];   // Connect right subtree rooted at rightSubTree[k]
				    result.push_back(root);    // Add this tree(rooted at i) to ans data-structure
			    }
		    }
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};