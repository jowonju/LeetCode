class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = i + 1, index = i + 1; j < matrix.size(); j++, index++)
            {
                swap(matrix[i][j], matrix[index][i]);
            }
            
        }
        
        for(int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};