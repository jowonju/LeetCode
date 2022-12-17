class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     
        string result;
        int vectorSize = strs.size();
        int stringSize = strs[0].size();
        int index = 0;
        
        if(vectorSize == 1)
            return strs[0];

        for(int i = 0; i < stringSize; i++){
            
            for(int j = 1; j < vectorSize; j++)
            {
                if(strs[j][i] == strs[0][i])
                {
                    int check = i - index;
                
                    if(j == vectorSize - 1 && check < 2)
                    {
                        result.push_back(strs[0][i]);
                        index = i;
                    }
                }
                else{
                    return result;
                }
            }
        }
      
        return result;
    }
        
};