class Solution {
public:
    int Generate(int i, int j, vector<vector<int>>& arr)
    {
        if(arr[i][j] != 0)
            return arr[i][j];
        
        if(i == j || j == 1)
            return 1;
        
        arr[i-1][j-1] = Generate(i - 1, j - 1, arr);
        arr[i-1][j] = Generate(i - 1, j, arr);
        
        return arr[i-1][j-1] + arr[i-1][j];
    }
    
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        vector<vector<int>> memory(rowIndex + 2, std::vector<int>(rowIndex + 2));
        
        for(int i = 1; i <= rowIndex + 1; i++)
        {
            vec.push_back(Generate(rowIndex + 1, i, memory));
        }
        
        return vec;
    }
};