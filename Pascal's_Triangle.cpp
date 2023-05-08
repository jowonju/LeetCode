class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        
        for(int i = 0; i < numRows; i++)
        {
            vector<int> vec1;
            for(int j = 0; j <= i ; j++)
            {
                if(j > 0 && j < i){
                    vec1.push_back(vec[i-1][j] + vec[i-1][j-1]);
                }
                else{
                    vec1.push_back(1);        
                }
            }
            vec.push_back(vec1);
        }
        
        return vec;
    }
};